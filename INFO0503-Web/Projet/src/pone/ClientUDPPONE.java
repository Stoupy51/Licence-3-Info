
package src.pone;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;
import java.util.Random;

import org.json.JSONObject;

import src.CodeDeSuivi;
import src.Energie;
import src.Messenger;

/**
 * Le PONE fourni de l'énergie au Marché de Gros toutes les 10 secondes.
 */
public class ClientUDPPONE implements Runnable {
	private final String adresseServeurUDPTare;
	private final int portServeurUDP;
	private final Messenger gestionMessage;
	private int count;

	/**
	 * Constructeur du clientUDP (utilisable dans un Thread)
	 * 
	 * @param adresseServeurUDPTare L'adresse du serveur UDP.
	 * @param portServeurUDP        Le numéro de port pour la communication avec le
	 *                              serveur.
	 * @param count                 Le nombre d'énergies total que le PONE va
	 *                              envoyer
	 */
	public ClientUDPPONE(String adresseServeurUDPTare, int portServeurUDP, int count) {
		this.adresseServeurUDPTare = adresseServeurUDPTare;
		this.portServeurUDP = portServeurUDP;
		this.gestionMessage = new Messenger("ClientPoneUDP");
		this.count = count;
	}

	/**
	 * Procédure qui sera mise en oeuvre via le start du Thread
	 */
	public void run() {
		gestionMessage.afficheWarning("Client UDP PONE démarré.");
		while (count > 0) {
			count--;

			// Sleep de 5 secondes
			try {
				Thread.sleep(5000);
			} catch (InterruptedException e) {
				gestionMessage.afficheErreur("Erreur lors du sleep : " + e);
			}

			// Création de la socket
			DatagramSocket socket = null;
			try {
				socket = new DatagramSocket();
			} catch (SocketException e) {
				gestionMessage.afficheErreur("Erreur lors de la création du socket : " + e);
				gestionMessage.afficheErreur("Extinction du Client");
				return;
			}

			// Création d'une énergie au hasard
			JSONObject obj = new JSONObject();
			int q = new Random().nextInt(51) + 50;
			String[] countries = { "FR", "AL", "ES", "IT", "EN_GB", "BE" };
			obj.put("energyType", new Random().nextInt(3));
			obj.put("quantity", q + new Random().nextInt(51) + 50);
			obj.put("minQuantity", q);
			obj.put("extractMode", new Random().nextInt(5));
			obj.put("extractModeStrict", "Y");
			obj.put("energyFromCountry", countries[new Random().nextInt(6)]);
			obj.put("maxPrice", new Random().nextInt(5));
			obj.put("maxBudget", new Random().nextInt(5000) + 5);
			obj.put("date", System.currentTimeMillis() / 1000L);
			CodeDeSuivi code = CodeDeSuivi.fromJSON(obj);
			Energie energie = new Energie(code, "signature");

			JSONObject json = new JSONObject();
			json.put("type", "PONE");
			json.put("energy", energie.toJSON());

			// Création et envoi du segment UDP
			try {
				byte[] data = json.toString().getBytes();
				InetAddress adresse = InetAddress.getByName(adresseServeurUDPTare);
				DatagramPacket msg = new DatagramPacket(data, data.length, adresse, portServeurUDP);
				socket.send(msg);
			} catch (UnknownHostException e) {
				gestionMessage.afficheErreur("Erreur lors de la création de l'adresse : " + e);
				gestionMessage.afficheErreur("Extinction du Client");
				socket.close();
				return;
			} catch (IOException e) {
				gestionMessage.afficheErreur("Erreur lors de l'envoi du message : " + e);
				gestionMessage.afficheErreur("Extinction du Client");
				socket.close();
				return;
			}

			// Lecture du message du client
			DatagramPacket msg = null;
			try {
				// Création du message
				byte[] tampon = new byte[1024];
				msg = new DatagramPacket(tampon, tampon.length);
				socket.receive(msg);
				JSONObject requete = new JSONObject(new String(msg.getData(), 0, msg.getLength()));
				//gestionMessage.afficheMessage("Réponse reçue du TARE : " + requete);

			} catch (IOException e) {
				gestionMessage.afficheErreur("Erreur lors de la réception du message : " + e);
				socket.close();
				break;
			}

			// Fermeture du socket
			socket.close();
		}
	}
}

