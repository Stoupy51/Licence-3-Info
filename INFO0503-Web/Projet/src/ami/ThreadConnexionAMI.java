
package src.ami;

import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.PrintWriter;
import java.net.Socket;

import org.json.JSONObject;

import src.Energie;
import src.Messenger;
import src.SignatureUtils;

/**
 * Classe correspondant au thread associe à chaque connexion d'un client.
 */
public class ThreadConnexionAMI extends Thread {
	private final Messenger gestionMessage;
	private BufferedReader input;
	private PrintWriter output;
	private Socket socketClient;

	public ThreadConnexionAMI(Socket socketClient, Messenger gestionMessage) {
		this.socketClient = socketClient;
		this.gestionMessage = new Messenger(gestionMessage.getId() + ":" + this.getName());

		// Association d'un flux d'entrée et de sortie
		try {
			input = new BufferedReader(new InputStreamReader(socketClient.getInputStream()));
			output = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socketClient.getOutputStream())), true);
		} catch (IOException e) {
			gestionMessage.afficheErreur("Association des flux impossible : " + e);
			gestionMessage.afficheErreur("Extinction du thread");
			return;
		}
	}

	@Override
	public void run() {
		try {
			// Lecture de la requête en String
			String req = input.readLine();
			JSONObject json = new JSONObject(req);
			String type = json.getString("type");
			String reponse = "";
			Energie energy = null;

			if (type.equals("PONE")) {
				// Si l'énergie est valide, alors créer un CRADO
				// Sinon réponse vide
				energy = Energie.fromJSON(json.getJSONObject("energy"));
				if (checkEnergy(energy)) {
					String crado = SignatureUtils.generateCRADO(ServeurTCPAMI.privateKeyFile, energy.getCodeDeSuivi().getCode());
					energy.setCrado(crado);
					reponse = energy.toJSON().toString();
					gestionMessage.afficheMessage("Demande d'un CRADO par un PONE validée.");
				}
				else {
					gestionMessage.afficheMessage("Demande d'un CRADO par un PONE refusée car il ne respecte pas les conditions.");
				}
			}
			else {
				// Requête du Marché de Gros, du TARÉ, du Revendeur, du Client
				// Demande vérification de l'énergie (énergie valide et CRADO valide)
				gestionMessage.afficheMessage("Demande de vérification du CRADO par un " + type);
				energy = Energie.fromJSON(json.getJSONObject("energy"));
				if (
					checkEnergy(energy)
					&&
					SignatureUtils.generateCRADO(ServeurTCPAMI.privateKeyFile, energy.getCodeDeSuivi().getCode())
						.equals(energy.getCrado())
				) {
					reponse = "OK";
				}
				else {
					reponse = "KO";
				}
			}
			output.println(reponse);
		}
		// Ensemble des catches
		catch (Exception e) {
			gestionMessage.afficheErreur("Erreur lors de la lecture de la requête : " + e);
			gestionMessage.afficheErreur("Extinction du thread");
			return;
		}

		// Fermeture des flux et des sockets
		try {
			gestionMessage.afficheWarning("Fermeture de la connexion avec le client : " + socketClient);
			input.close();
			output.close();
			socketClient.close();
		} catch (IOException e) {
			gestionMessage.afficheErreur("Erreur lors de la fermeture des flux et des sockets : " + e);
			gestionMessage.afficheErreur("Extinction du thread");
			return;
		}
	}

	/**
	 * Vérifie si l'énergie est valide (prix pas au dessus de 5€ par unité)
	 * 
	 * @param energy
	 * @return true si l'énergie est valide, false sinon
	 */
	private Boolean checkEnergy(Energie energy) {
		return energy.getCodeDeSuivi().getMaxPrice() <= 5;
	}
}
