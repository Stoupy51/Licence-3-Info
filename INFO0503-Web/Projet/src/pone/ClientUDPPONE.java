
package src.pone;

import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.ByteArrayOutputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.net.UnknownHostException;
import java.util.Random;
import java.util.concurrent.TimeUnit;

import org.json.JSONObject;

import src.CodeDeSuivi;
import src.Energie;
import src.Messenger;

/**
 * Le PONE fourni de l'énergie au Marché de Gros toutes les 10 secondes.
 */
public class ClientUDPPONE implements Runnable {
	private final String adresseServeurUDP;
	private final int portServeurUDP;
	private final Messenger gestionMessage;
	private int count;

	/**
	 * Constructeur du clientUDP (utilisable dans un Thread)
	 * 
	 * @param adresseServeurUDP L'adresse du serveur UDP.
	 * @param portServeurUDP    Le numéro de port pour la communication avec le
	 *                          serveur.
	 * @param count             Le nombre d'énergies total que le PONE va envoyer
	 */
	public ClientUDPPONE(String adresseServeurUDP, int portServeurUDP, int count) {
		this.adresseServeurUDP = adresseServeurUDP;
		this.portServeurUDP = portServeurUDP;
		this.gestionMessage = new Messenger("ClientPoneUDP");
		this.count = count;
	}

	/**
	 * Procédure qui sera mise en oeuvre via le start du Thread
	 */
	public void run() {
		while (count > 0) {
			count--;

			// Sleep de 5 secondes
			try {
				TimeUnit.SECONDS.sleep(5);
			} catch (InterruptedException e) {
				gestionMessage.afficheErreur("Erreur lors du sleep : " + e);
			}

			// Création de la socket
			DatagramSocket socket = null;
			try {
				socket = new DatagramSocket();
			} catch (SocketException e) {
				gestionMessage.afficheErreur("Erreur lors de la création du socket : " + e);
				return;
			}

			// Création d'une énergie au hasard
			JSONObject obj = new JSONObject();
			int q = new Random().nextInt(51) + 50;
			String[] countries = {"FR","AL","ES","IT","EN-GB","BE"};
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

			// Transformation en tableau de bytes (Sérialization de l'énergie)
			ByteArrayOutputStream baos = new ByteArrayOutputStream();
			try {
				ObjectOutputStream oos = new ObjectOutputStream(baos);
				oos.writeObject(energie);
			} catch (IOException e) {
				gestionMessage.afficheErreur("Erreur lors de la sérialisation : " + e);
				socket.close();
				return;
			}

			// Création et envoi du segment UDP
			try {
				byte[] data = baos.toByteArray();
				InetAddress adresse = InetAddress.getByName(adresseServeurUDP);
				DatagramPacket msg = new DatagramPacket(data, data.length, adresse, portServeurUDP);
				socket.send(msg);
			} catch (UnknownHostException e) {
				gestionMessage.afficheErreur("Erreur lors de la création de l'adresse : " + e);
				socket.close();
				return;
			} catch (IOException e) {
				gestionMessage.afficheErreur("Erreur lors de l'envoi du message : " + e);
				socket.close();
				return;
			}

			// Fermeture du socket
			socket.close();
		}
	}
}

