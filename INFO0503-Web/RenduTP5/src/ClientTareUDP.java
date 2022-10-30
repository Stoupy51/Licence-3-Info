
package src;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;

/**
 * Classe correspondant à un client UDP.
 * La chaine de caractères "Bonjour" est envoyée au serveur.
 * Le port d'écoute du serveur est indiqué dans la classe ServeurUDP.
 * 
 * @author Cyril Rabat
 */
public class ClientTareUDP {

	public static int portEcoute = 2025;

	public static void main(String[] args) {
		String req = "Requête de test";
		CodeDeSuivi codeDeSuivi = new CodeDeSuivi("0-2573.0-1200.0-3-true-FR-0.1546-400.0-1665232943");

		// Création de la socket
		DatagramSocket socket = null;
		try {
			socket = new DatagramSocket(portEcoute + 1);
		} catch (SocketException e) {
			System.err.println("Erreur lors de la création de la socket : " + e);
			// System.exit(0);
		}

		// Création du message
		DatagramPacket msg = null;
		try {
			InetAddress adresse = InetAddress.getByName(null);
			Requete requete = new Requete("TARE 1", codeDeSuivi, Requete.Type.REQUETE_TARE, req);
			ByteArrayOutputStream baos = new ByteArrayOutputStream();
			try {
				ObjectOutputStream oos = new ObjectOutputStream(baos);
				oos.writeObject(requete);
			} catch (java.io.IOException e) {
				System.err.println("Erreur lors de la sérialisation : " + e);
				// System.exit(0);
			}
			byte[] tampon = baos.toByteArray();
			msg = new DatagramPacket(tampon, tampon.length, adresse, portEcoute);

		} catch (UnknownHostException e) {
			System.err.println("Erreur lors de la création du message : " + e);
			// System.exit(0);
		}

		// Envoi du message
		try {
			socket.send(msg);
		} catch (IOException e) {
			System.err.println("Erreur lors de l'envoi du message : " + e);
			// System.exit(0);
		}

		// Création du message
		byte[] tampon = new byte[1024];
		msg = new DatagramPacket(tampon, tampon.length);

		// Lecture du message du client
		try {
			socket.receive(msg);
			String texte = new String(msg.getData(), 0, msg.getLength());
			System.out.println("Lu: " + texte);
		} catch (IOException e) {
			System.err.println("Erreur lors de la réception du message : " + e);
			// System.exit(0);
		}

		// Fermeture de la socket
		socket.close();
	}
}

