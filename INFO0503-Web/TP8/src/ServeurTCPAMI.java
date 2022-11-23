
package src;

import java.io.File;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.NoSuchAlgorithmException;

/**
 * Classe correspondant à un serveur TCP multithreadé.
 * Serveur pour l'AMI (Autorité des Marchés Internationaux)
 */
public class ServeurTCPAMI {
	public static final int portEcoute = 5101;

	public static void main(String[] args) {
		checkKeys();

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

	// Partie Signatures
	public static final String privateKeyFile = "privateKey.bin";
	public static final String publicKeyFile = "publicKey.bin";
	private static void checkKeys() {
		if (!(new File(privateKeyFile).isFile()) || !(new File(publicKeyFile).isFile())) {
			// Création d'un générateur RSA
			KeyPairGenerator generateurCles = null;
			try {
				generateurCles = KeyPairGenerator.getInstance("RSA");
				generateurCles.initialize(2048);
			} catch (NoSuchAlgorithmException e) {
				System.err.println("Erreur lors de l'initialisation du générateur de clés : " + e);
				return;
			}
			// Génération de la paire de clés
			KeyPair paireCles = generateurCles.generateKeyPair();
			// Sauvegarde de la clé privée
			GestionClesRSA.sauvegardeClePrivee(paireCles.getPrivate(), privateKeyFile);
			// Sauvegarde de la clé publique
			GestionClesRSA.sauvegardeClePublique(paireCles.getPublic(), publicKeyFile);
			System.out.println("Clés sauvegardées.");
		}
	}

	public String createSignatureCRADO() {
		String r = "";

		return r;
	}

}
