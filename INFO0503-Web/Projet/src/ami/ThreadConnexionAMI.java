
package src.ami;

import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.PrintWriter;
import java.net.Socket;

import org.json.JSONObject;

import src.Messenger;

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
		this.gestionMessage = gestionMessage;

		// Association d'un flux d'entrée et de sortie
		try {
			input = new BufferedReader(new InputStreamReader(socketClient.getInputStream()));
			output = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socketClient.getOutputStream())), true);
		} catch (IOException e) {
			this.gestionMessage.afficheErreur("Association des flux impossible : " + e);
			gestionMessage.afficheErreur("Extinction du serveur");
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
			switch (type) {
				case "hmm":
					break;
			}

			// Envoie en réponse le contenu toString de la requête
			gestionMessage.afficheMessage("Lu    " + req);
			
			String msg = "Requête lue par le serveur, avec contenu : \"" + req + "\"";
			gestionMessage.afficheMessage("Envoi  " + msg);
			output.println(msg);
		}

		// Ensemble des catches
		catch (IOException e) {
			gestionMessage.afficheErreur("Erreur lors de la lecture de la requête : " + e);
			gestionMessage.afficheErreur("Extinction du serveur");
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
			gestionMessage.afficheErreur("Extinction du serveur");
			return;
		}
	}
}
