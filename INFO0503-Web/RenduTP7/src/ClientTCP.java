
package src;

import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.ByteArrayOutputStream;
import java.io.PrintWriter;

import java.net.Socket;
import java.net.UnknownHostException;

public class ClientTCP implements Runnable {
	/** adresse du serveur TCP (non modifiable) */
	private final String adresseServeurTCP;
	/** Port du serveur TCP (non modifiable) */
	private final int portServeurTCP;
	/** Outil de gestion des messages (non modifiable) */
	private final Messenger gestionMessage;

	public ClientTCP(String adresseServeurTCP, int portServeurTCP) {
		this.adresseServeurTCP = adresseServeurTCP;
		this.portServeurTCP = portServeurTCP;
		this.gestionMessage = new Messenger("ClientTCP    ");
	}

	/**
	 * Procédure qui sera mise en oeuvre via le start du Thread
	 */
	public void run() {
		Socket socket = null;
		try {
			socket = new Socket(adresseServeurTCP, portServeurTCP);
		} catch (UnknownHostException e) {
			gestionMessage.afficheErreur("Erreur sur l'hôte : " + e);
			System.exit(0);
		} catch (IOException e) {
			gestionMessage.afficheErreur("Création de la socket impossible : " + e);
			System.exit(0);
		}
		gestionMessage.afficheWarning("Connexion établie avec le serveur : " + socket);

		BufferedReader input = null;
		PrintWriter output = null;
		try {
			input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			output = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);
		} catch (Exception e) {
			gestionMessage.afficheErreur("Association des flux impossible : " + e);
			System.exit(0);
		}

		// Envoi d'une requête
		Energie energy = new Energie(new CodeDeSuivi("0-2573.0-1200.0-3-true-FR-0.1546-400.0-1665232943"));
		try {
			// Convertir l'objet en tableau de bytes
			ByteArrayOutputStream bos = new ByteArrayOutputStream();
			ObjectOutputStream out = new ObjectOutputStream(bos);   
			out.writeObject(energy);
			out.flush();
			byte[] bytes = bos.toByteArray();

			// Envoyer le tableau de bytes chiffré
			OutputStream os = socket.getOutputStream();
			ObjectOutputStream oos = new ObjectOutputStream(os);
			gestionMessage.afficheMessage("Envoi  " + energy);
			oos.writeObject(ChiffrementAES.chiffrement(bytes));
			oos.flush();
		} catch (Exception e) {
			gestionMessage.afficheErreur("Erreur lors de la sérialisation : " + e);
			System.exit(0);
		}

		// Fermeture de la connexion
		try {
			gestionMessage.afficheWarning("Fermeture de la connexion avec le serveur : " + socket);
			input.close();
			output.close();
			socket.close();
		} catch (Exception e) {
			gestionMessage.afficheErreur("Erreur lors de la fermeture des flux et de la socket : " + e);
			System.exit(0);
		}
	}
}
