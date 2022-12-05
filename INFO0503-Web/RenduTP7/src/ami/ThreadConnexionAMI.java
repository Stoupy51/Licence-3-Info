
package src.ami;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.ByteArrayInputStream;
import java.io.PrintWriter;
import java.net.Socket;

import src.ChiffrementAES;
import src.Energie;
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
			System.exit(0);
		}
	}

	@Override
	public void run() {
		try {
			// Lecture de la requête
			InputStream is = socketClient.getInputStream();
			ObjectInputStream ois = new ObjectInputStream(is);
			byte[] bytes = (byte[]) ois.readObject();

			// Conversion du tableau de bytes en objet déchiffré
			ByteArrayInputStream bis = new ByteArrayInputStream(ChiffrementAES.dechiffrement(bytes));
			ois = new ObjectInputStream(bis);
			Energie energy = (Energie) ois.readObject();
			gestionMessage.afficheMessage("Lu    " + energy);
		}
		// Ensemble des catches
		catch (IOException e) {
			gestionMessage.afficheErreur("Erreur lors de la lecture de la requête : " + e);
			System.exit(0);
		} catch (ClassNotFoundException e) {
			gestionMessage.afficheErreur("Erreur lors du cast de la requête : " + e);
			System.exit(0);
		}

		// Fermeture des flux et des sockets
		try {
			gestionMessage.afficheWarning("Fermeture de la connexion avec le client : " + socketClient);
			input.close();
			output.close();
			socketClient.close();
		} catch (IOException e) {
			gestionMessage.afficheErreur("Erreur lors de la fermeture des flux et des sockets : " + e);
			System.exit(0);
		}
	}
}
