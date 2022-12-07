
package src.gros;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;

import org.json.JSONObject;

import src.Messenger;

/**
 * Classe correspondant à un serveur UDP multithreadé.
 * Serveur pour le Marché de Gros
 */
public class ServeurUDPGros implements Runnable {
	private final int portServeurUDP;
	private final Messenger gestionMessage;

	/**
	 * Constructeur du ServeurTCP (utilisable dans un Thread)
	 */
	public ServeurUDPGros(int portServeurUDP) {
		this.portServeurUDP = portServeurUDP;
		this.gestionMessage = new Messenger("ServeurUDPGros");
	}

	@Override
	public void run() {
		/**
		 * Double 'while true' pour pouvoir relancer
		 * la lecture des requêtes en cas d'erreur
		 */
		gestionMessage.afficheWarning("Serveur UDP Gros démarré.");
		while (true) {
			while (true) {
				// Création de la socket
				DatagramSocket socket = null;
				try {
					socket = new DatagramSocket(portServeurUDP);
				} catch (SocketException e) {
					gestionMessage.afficheErreur("Erreur lors de la création de la socket : " + e);
					gestionMessage.afficheErreur("Extinction du serveur");
					return;
				}

				// Lecture du message du client
				JSONObject reponse = new JSONObject();
				reponse.put("code", "KO");
				DatagramPacket msg = null;
				try {
					// Création du message
					byte[] tampon = new byte[1024];
					msg = new DatagramPacket(tampon, tampon.length);
					socket.receive(msg);
					JSONObject requete = new JSONObject(new String(msg.getData(), 0, msg.getLength()));

					switch (requete.getString("type")) {
					case "TARE":
						gestionMessage.afficheMessage("Requête reçue d'un TARE :\n" + requete);
						// Si y'a de l'énergie, alors renvoyer YES BITCH
						reponse.put("code", "OK");
						break;

					case "PONE":
						reponse.put("code", "OK");
						break;
					}

				} catch (IOException e) {
					gestionMessage.afficheErreur("Erreur lors de la réception du message : " + e);
					socket.close();
					break;
				}

				// Envoie de la réponse au client : Création et envoi du segment UDP
				try {
					byte[] tampon = reponse.toString().getBytes();
					DatagramPacket packet = new DatagramPacket(tampon, tampon.length, msg.getAddress(), msg.getPort());
					socket.send(packet);
				} catch (IOException e) {
					gestionMessage.afficheErreur("Erreur lors de l'envoi du message : " + e);
					socket.close();
					break;
				}
				socket.close();
			}
		}
	}
}

