
package src;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.PrintWriter;
import java.net.Socket;

/**
 * Classe correspondant au thread associe à chaque connexion d'un client.
 */
public class ThreadConnexionAMI extends Thread {
	private BufferedReader input;
	private PrintWriter output;
	private Socket socketClient;

	public ThreadConnexionAMI(Socket socketClient) {
		this.socketClient = socketClient;

		// Association d'un flux d'entrée et de sortie
		try {
			input = new BufferedReader(new InputStreamReader(socketClient.getInputStream()));
			output = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socketClient.getOutputStream())), true);
		} catch (IOException e) {
			System.err.println("Association des flux impossible : " + e);
			System.exit(0);
		}
	}

	@Override
	public void run() {
		try {
			// Lecture de la requête
			InputStream is = socketClient.getInputStream();
			ObjectInputStream ois = new ObjectInputStream(is);
			RequeteAMIGros req = (RequeteAMIGros) ois.readObject();

			// Envoie en réponse le contenu toString de la requête
			System.out.println("Lu et envoie de : " + req);
			output.println("Requête lue par le serveur, avec contenu : " + req);
		}

		// Ensemble des catches
		catch (IOException e) {
			System.err.println("Erreur lors de la lecture de la requête : " + e);
			System.exit(0);
		} catch (ClassNotFoundException e) {
			System.err.println("Erreur lors du cast de la requête : " + e);
			System.exit(0);
		}

		// Fermeture des flux et des sockets
		try {
			input.close();
			output.close();
			socketClient.close();
		} catch (IOException e) {
			System.err.println("Erreur lors de la fermeture des flux et des sockets : " + e);
			System.exit(0);
		}
	}
}
