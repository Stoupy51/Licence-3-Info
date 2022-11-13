
package src;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * Classe correspondant à un serveur TCP multithreadé.
 * Serveur pour l'AMI (Autorité des Marchés Internationaux)
 */
public class ServeurTCPAMI {
	public static final int portEcoute = 5101;

	public static void main(String[] args) {
		// Création de la socket serveur
		ServerSocket socketServeur = null;
		try {
			socketServeur = new ServerSocket(portEcoute);
		} catch (IOException e) {
			System.err.println("Création de la socket impossible : " + e);
			System.exit(0);
		}

		// Attente des connexions des clients
		try {
			Socket socketClient;
			while (true) {
				System.out.println("En attente d'une connexion...");
				socketClient = socketServeur.accept();
				System.out.println("Connexion d'un client : " + socketClient);
				ThreadConnexionAMI t = new ThreadConnexionAMI(socketClient);
				t.start();
			}
		} catch (IOException e) {
			System.err.println("Erreur lors de l'attente d'une connexion : " + e);
			System.exit(0);
		}

		// Fermeture de la socket
		try {
			socketServeur.close();
		} catch (IOException e) {
			System.err.println("Erreur lors de la fermeture de la socket : " + e);
			System.exit(0);
		}
	}
}
