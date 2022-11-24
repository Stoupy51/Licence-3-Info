
package src;

import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.PrintWriter;

import java.net.Socket;
import java.net.UnknownHostException;

import src.ami.RequeteToAMI;

/**
 * Classe correspondant à un client TCP <em>Runnable</em>.
 * Le client envoie la chaine 'Bonjour' et lit une réponse de la part du
 * serveur.
 * Le client envoie ensuite la chaine 'Au revoir' et lit une réponse.
 * 
 * @author Cyril Rabat et Jean-Charles BOISSON (11/2022)
 * 
 * @version 1.1
 * 
 */
public class ClientTCP implements Runnable {

	/** adresse du serveur TCP (non modifiable) */
	private final String adresseServeurTCP;

	/** Port du serveur TCP (non modifiable) */
	private final int portServeurTCP;

	/** Outil de gestion des messages (non modifiable) */
	private final Messenger gestionMessage;

	/**
	 * Constructeur du clientTCP (utilisable dans un Thread)
	 * 
	 * @param adresseServeurTCP L'adresse du serveur TCP.
	 * @param portServeurTCP    Le numéro de port pour la communication avec le
	 *                          serveur.
	 */
	public ClientTCP(String adresseServeurTCP, int portServeurTCP) {
		this.adresseServeurTCP = adresseServeurTCP;
		this.portServeurTCP = portServeurTCP;
		this.gestionMessage = new Messenger("ClientTCP ");
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
		RequeteToAMI req = new RequeteToAMI(1,"Marché de Gros", "test requête");
		try {
			// Send req in TCP
			OutputStream os = socket.getOutputStream();
			ObjectOutputStream oos = new ObjectOutputStream(os);
			oos.writeObject(req);
			oos.flush();
		} catch (Exception e) {
			gestionMessage.afficheErreur("Erreur lors de la sérialisation : " + e);
			System.exit(0);
		}
		gestionMessage.afficheErreur("Test erreur");
		gestionMessage.afficheMessage("Envoi  " + req);
		output.println(req);

		String message = "";
		try {
			message = input.readLine();
		} catch (Exception e) {
			gestionMessage.afficheErreur("Erreur lors de la lecture : " + e);
			System.exit(0);
		}
		gestionMessage.afficheMessage("Lu    " + message);

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
