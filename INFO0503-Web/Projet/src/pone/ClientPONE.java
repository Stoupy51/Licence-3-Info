
package src.pone;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.Socket;
import java.net.SocketException;
import java.net.UnknownHostException;
import java.util.Random;

import org.json.JSONObject;

import src.CodeDeSuivi;
import src.Energie;
import src.Lanceur;
import src.Messenger;

/**
 * Le PONE fourni de l'énergie au Marché de Gros toutes les 10 secondes.
 */
public class ClientPONE implements Runnable {
	private final String adresseServeurUDPGros;
	private final int portServeurUDPGros;
	private final String adresseServeurTCPAmi;
	private final int portServeurTCPAMI;
	private final String nomDuPONE = "ClientPoneUDP";
	private final Messenger gestionMessage;
	private int count;
	private final Energie energie;

	/*
	 * Constructeur du Client UDP PONE
	 * 
	 * @param adresseServeurUDPGros L'adresse du serveur UDP du Marché de Gros
	 * 
	 * @param portServeurUDPGros Le port du serveur UDP du Marché de Gros
	 * 
	 * @param adresseServeurTCPAmi L'adresse du serveur TCP de l'Ami
	 * 
	 * @param portServeurTCPAMI Le port du serveur TCP de l'Ami
	 * 
	 * @param count Le nombre de fois que le PONE doit fournir de l'énergie
	 * 
	 * @param energie L'énergie à fournir. Si null, une énergie aléatoire sera créée
	 */
	public ClientPONE(String adresseServeurUDPGros, int portServeurUDPGros, String adresseServeurTCPAmi,
			int portServeurTCPAMI, int count) {
		this.adresseServeurUDPGros = adresseServeurUDPGros;
		this.portServeurUDPGros = portServeurUDPGros;
		this.adresseServeurTCPAmi = adresseServeurTCPAmi;
		this.portServeurTCPAMI = portServeurTCPAMI;
		this.gestionMessage = new Messenger(nomDuPONE);
		this.count = count;
		this.energie = null;
	}

	public ClientPONE(String adresseServeurUDPGros, int portServeurUDPGros, String adresseServeurTCPAmi,
			int portServeurTCPAMI, int count, Energie energie) {
		this.adresseServeurUDPGros = adresseServeurUDPGros;
		this.portServeurUDPGros = portServeurUDPGros;
		this.adresseServeurTCPAmi = adresseServeurTCPAmi;
		this.portServeurTCPAMI = portServeurTCPAMI;
		this.gestionMessage = new Messenger(energie.getCodeDeSuivi().getFournisseur());
		this.count = count;
		this.energie = energie;
	}

	/**
	 * Procédure qui sera mise en oeuvre via le start du Thread
	 */
	public void run() {
		gestionMessage.afficheWarning("Client UDP PONE démarré.");
		while (count > 0) {
			count--;

			// Sleep de 1 seconde
			Lanceur.sleepPls(1000);

			// Création d'une énergie au hasard si aucune n'est fournie
			JSONObject json = new JSONObject();
			json.put("type", "PONE");
			Energie ener = null;
			if (energie == null) {
				JSONObject obj = new JSONObject();
				obj.put("energyType", new Random().nextInt(3));
				obj.put("quantity", new Random().nextInt(5001) + 500);
				obj.put("minQuantity", 0);
				obj.put("extractMode", new Random().nextInt(5));
				obj.put("extractModeStrict", "N");
				obj.put("energyFromCountry", "FR");
				obj.put("maxPrice", new Random().nextInt(100) / 100.0 + 0.01);
				obj.put("maxBudget", 0);
				obj.put("date", System.currentTimeMillis() / 1000L);
				obj.put("fournisseur", nomDuPONE);
				CodeDeSuivi code = CodeDeSuivi.fromJSON(obj);
				ener = new Energie(code, "CRADO");

			} else {
				ener = energie;
			}
			json.put("energy", ener.toJSON());

			// json == null si l'énergie est invalide selon l'AMI
			System.err.println("");
			gestionMessage.afficheMessage("Demande d'un CRADO à l'AMI.");
			json = demandeCRADO(json);
			if (json == null)
				gestionMessage.afficheWarning("L'énergie est invalide selon l'AMI, elle ne sera pas envoyée.");
			else {
				gestionMessage.afficheMessage("CRADO reçu, envoie de l'énergie au Marché de Gros.");
				envoieEnergie(json);
			}
		}
	}

	/**
	 * Envoie l'énergie au serveur TCP de l'AMI
	 * afin de recevoir un CRADO
	 * 
	 * @param json L'énergie à envoyer
	 */
	private JSONObject demandeCRADO(JSONObject json) {
		Socket socket = null;
		try {
			socket = new Socket(adresseServeurTCPAmi, portServeurTCPAMI);
		} catch (UnknownHostException e) {
			gestionMessage.afficheErreur("Erreur sur l'hôte : " + e);
			return null;
		} catch (IOException e) {
			gestionMessage.afficheErreur("Création de la socket impossible : " + e);
			return null;
		}

		BufferedReader input = null;
		PrintWriter output = null;
		try {
			input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			output = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);
		} catch (Exception e) {
			gestionMessage.afficheErreur("Association des flux impossible : " + e);
			try {
				socket.close();
			} catch (Exception e2) {
				gestionMessage.afficheErreur("Erreur lors de la fermeture de la socket : " + e2);
			}
			return null;
		}

		// Envoi de l'énergie
		output.println(json);

		String message = "";
		try {
			message = input.readLine();
			input.close();
			output.close();
			socket.close();
		} catch (Exception e) {
			gestionMessage.afficheErreur("Erreur : " + e);
			return null;
		}
		if (message == "")
			return null;
		json.put("energy", new JSONObject(message));
		return json;
	}

	/**
	 * Envoie une énergie au Marché de Gros
	 * 
	 * @param json L'énergie à envoyer
	 */
	private void envoieEnergie(JSONObject json) {
		// Création de la socket
		DatagramSocket socket = null;
		try {
			socket = new DatagramSocket();
		} catch (SocketException e) {
			gestionMessage.afficheErreur("Erreur lors de la création du socket : " + e);
			gestionMessage.afficheErreur("Extinction du Client");
			return;
		}

		// Création et envoi du segment UDP au Marché de Gros
		try {
			byte[] data = json.toString().getBytes();
			InetAddress adresse = InetAddress.getByName(adresseServeurUDPGros);
			DatagramPacket msg = new DatagramPacket(data, data.length, adresse, portServeurUDPGros);
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

			// JSONObject requete = new JSONObject(new String(msg.getData(), 0,
			// msg.getLength()));
			// gestionMessage.afficheMessage("Réponse reçue du Marché de Gros : " + requete
			// + "\n");

		} catch (IOException e) {
			gestionMessage.afficheErreur("Erreur lors de la réception du message : " + e);
		}

		// Fermeture du socket
		socket.close();
	}
}

