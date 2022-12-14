
package src.tare;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;

import org.json.JSONObject;

import src.Messenger;

public class ClientTareUDP {

	public static String requete(Messenger gestionMessage, JSONObject json, String adresseServeurUDP, int portEcoute) {
		// Création de la socket
		DatagramSocket socket = null;
		try {
			socket = new DatagramSocket(portEcoute + 1);
		} catch (SocketException e) {
			gestionMessage.afficheErreur("Erreur lors de la création de la socket : " + e);
			return "";
		}

		// Création du message
		DatagramPacket msg = null;
		try {
			InetAddress adresse = InetAddress.getByName(adresseServeurUDP);
			JSONObject req = new JSONObject();
			req.put("type", "TARE");
			req.put("data", json);

			byte[] tampon = req.toString().getBytes();
			msg = new DatagramPacket(tampon, tampon.length, adresse, portEcoute);
			socket.send(msg);

		} catch (UnknownHostException e) {
			gestionMessage.afficheErreur("Erreur lors de la création du message : " + e);
			socket.close();
			return "";
		} catch (IOException e) {
			gestionMessage.afficheErreur("Erreur lors de l'envoi du message : " + e);
			socket.close();
			return "";
		}

		// Création du message
		byte[] tampon = new byte[1024];
		msg = new DatagramPacket(tampon, tampon.length);

		// Lecture du message du client
		String texte = "";
		try {
			socket.receive(msg);
			texte = new String(msg.getData(), 0, msg.getLength());
		} catch (IOException e) {
			gestionMessage.afficheErreur("Erreur lors de la réception du message : " + e);
			socket.close();
			return "";
		}

		// Fermeture de la socket
		socket.close();

		return texte;
	}
}

