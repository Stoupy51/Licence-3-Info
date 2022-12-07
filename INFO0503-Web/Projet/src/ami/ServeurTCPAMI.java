
package src.ami;

import java.io.File;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.NoSuchAlgorithmException;

import src.GestionClesRSA;
import src.Messenger;
import src.ConsoleColors;

/**
 * Classe correspondant à un serveur TCP multithreadé.
 * Serveur pour l'AMI (Autorité des Marchés Internationaux)
 */
public class ServeurTCPAMI implements Runnable {
	/** Port du serveur TCP (non modifiable) */
	private final int portServeurTCP;
	/** Outil de gestion des messages (non modifiable) */
	private final Messenger gestionMessage;

	/**
	 * Constructeur du ServeurTCP (utilisable dans un Thread)
	 */
	public ServeurTCPAMI(int portServeurTCP) {
		this.portServeurTCP = portServeurTCP;
		this.gestionMessage = new Messenger("ServeurTCPAMI");
		checkKeys();
	}

	@Override
	public void run() {
		// Création de la socket serveur
		ServerSocket socketServeur = null;
		try {
			socketServeur = new ServerSocket(portServeurTCP);
		} catch (IOException e) {
			gestionMessage.afficheErreur("Création de la socket impossible : " + e);
			System.exit(0);
		}

		// Attente des connexions des clients
		try {
			Socket socketClient;
			gestionMessage.afficheWarning("Serveur TCP AMI démarré.");
			while (true) {
				socketClient = socketServeur.accept();
				gestionMessage.afficheWarning("Connexion d'un client : " + socketClient);
				ThreadConnexionAMI t = new ThreadConnexionAMI(socketClient, gestionMessage);
				t.start();
			}
		} catch (Exception e) {
			gestionMessage.afficheErreur("Erreur lors de l'attente d'une connexion : " + e);
			System.exit(0);
		}

		// Fermeture de la socket
		try {
			socketServeur.close();
		} catch (Exception e) {
			gestionMessage.afficheErreur("Erreur lors de la fermeture de la socket : " + e);
			System.exit(0);
		}
	}

	// Partie Signatures
	public static final String privateKeyFile = "privateKey.bin";
	public static final String publicKeyFile = "publicKey.bin";

	private void checkKeys() {
		if (!(new File(privateKeyFile).isFile()) || !(new File(publicKeyFile).isFile())) {
			// Création d'un générateur RSA
			KeyPairGenerator generateurCles = null;
			try {
				generateurCles = KeyPairGenerator.getInstance("RSA");
				generateurCles.initialize(2048);
			} catch (NoSuchAlgorithmException e) {
				gestionMessage.afficheErreur("Erreur lors de l'initialisation du générateur de clés : " + e);
				gestionMessage.afficheErreur("Extinction du serveur");
				return;
			}
			// Génération de la paire de clés
			KeyPair paireCles = generateurCles.generateKeyPair();
			// Sauvegarde de la clé privée
			GestionClesRSA.sauvegardeClePrivee(paireCles.getPrivate(), privateKeyFile);
			// Sauvegarde de la clé publique
			GestionClesRSA.sauvegardeClePublique(paireCles.getPublic(), publicKeyFile);
			gestionMessage.afficheMessage(ConsoleColors.GREEN + "Clées sauvegardées.");
		}
	}

	/**
	public String createSignatureCRADO() {
		String r = "";

		return r;
	}
	*/
}
