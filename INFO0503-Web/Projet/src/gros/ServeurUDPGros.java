
package src.gros;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;

import org.json.JSONArray;
import org.json.JSONObject;

import src.ClientTCP;
import src.CodeDeSuivi;
import src.Energie;
import src.JSONFile;
import src.Messenger;

/**
 * Classe correspondant à un serveur UDP multithreadé.
 * Serveur pour le Marché de Gros
 */
public class ServeurUDPGros implements Runnable {
	private final String adresseServeurTCPAmi;
	private final int portServeurTCPAmi;
	private final int portServeurUDP;
	private final Messenger gestionMessage;
	private JSONFile energiesFile;
	private JSONObject energiesObject;

	/**
	 * Constructeur du ServeurTCP (utilisable dans un Thread)
	 */
	public ServeurUDPGros(String adresseServeurTCPAmi, int portServeurTCPAmi, int portServeurUDP, Boolean newFile) {
		this.adresseServeurTCPAmi = adresseServeurTCPAmi;
		this.portServeurTCPAmi = portServeurTCPAmi;
		this.portServeurUDP = portServeurUDP;
		this.gestionMessage = new Messenger("ServeurUDPGros");

		if (newFile) {
			// Création du fichier JSON
			energiesFile = new JSONFile("energies.json", true);
			energiesObject = new JSONObject();
			energiesObject.put("energies", new JSONArray());
			energiesFile.setJSON(energiesObject);
			energiesFile.sauvegarder();
		}
		else {
			// Charge le fichier JSON
			String fileString = "energies.json";
			energiesFile = new JSONFile(fileString, !JSONFile.fichierExiste(fileString));
			energiesObject = energiesFile.getJSON();

			// Charge les énergies dans le JSONArray
			try {
				energiesObject.getJSONArray("energies");
			} catch (Exception e) {
				energiesObject.put("energies", new JSONArray());
				energiesFile.setJSON(energiesObject);
				energiesFile.sauvegarder();
			}
		}
	}

	private Boolean insertEnergy(JSONObject requete) {
		// Insertion de l'énergie dans le JSONArray
		JSONArray energiesArray = energiesObject.getJSONArray("energies");
		energiesArray.put(requete.getJSONObject("energy"));

		// Sauvegarde du JSONArray dans le fichier JSON
		energiesObject.put("energies", energiesArray);
		energiesFile.setJSON(energiesObject);
		energiesFile.sauvegarder();
		return true;
	}

	/**
	 * Méthode permettant de traiter une requête
	 * et extraire l'énergie correspondante à la commande
	 * 
	 * @param requete la requête à traiter
	 * @return La réponse à la requête (l'énergie)
	 */
	private JSONObject extractEnergy(JSONObject requete) {
		JSONObject json = new JSONObject();

		// Création de l'énergie demandée pour la comparer avec les énergies du fichier
		Energie energy, commande = new Energie(
			CodeDeSuivi.fromJSON(requete.getJSONObject("data")),
			null
		);

		JSONArray energiesArray = energiesObject.getJSONArray("energies");
		int length = energiesArray.length();
		for (int i = 0; i < length; i++) {
			energy = Energie.fromJSON(energiesArray.getJSONObject(i));

			// Si l'énergie est supérieure à la requête (respecte la commande), on l'envoie
			if (energy.compareTo(commande) == 1) {
				json.put("code", "OK");
				json.put("energy", energy.toJSON());

				// On supprime l'énergie du fichier
				energiesArray.remove(i);
				energiesObject.put("energies", energiesArray);
				energiesFile.setJSON(energiesObject);
				energiesFile.sauvegarder();
				return json;
			}
		}

		json.put("code", "KO");
		json.put("message", "Aucune energie disponible pour le moment.");
		return json;
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
				JSONObject requete = null;
				DatagramPacket msg = null;
				try {

					byte[] tampon = new byte[1024];
					msg = new DatagramPacket(tampon, tampon.length);
					socket.receive(msg);
					requete = new JSONObject(new String(msg.getData(), 0, msg.getLength()));

				} catch (IOException e) {
					gestionMessage.afficheErreur("Erreur lors de la réception du message : " + e);
					socket.close();
					break;
				}

				// Traitement de la requête
				JSONObject reponse = new JSONObject();
				reponse.put("code", "KO");
				try {
					switch (requete.getString("type")) {
						case "TARE":
							reponse = extractEnergy(requete);
							if (reponse.getString("code").equals("OK")) {
								gestionMessage.afficheMessage("Energie extraite pour un TARE !");
							} else {
								gestionMessage.afficheMessage("Aucune énergie disponible pour un TARE !");
							}
							break;

						case "PONE":
							// Vérification de l'énergie reçue
							gestionMessage.afficheMessage("Demande de vérification de signature de l'énergie d'un PONE reçue.");
							JSONObject reqToAMI = new JSONObject();
							reqToAMI.put("type", "GROS");
							reqToAMI.put("energy", requete.getJSONObject("energy"));
							String code = ClientTCP.requeteToAMI(reqToAMI, adresseServeurTCPAmi, portServeurTCPAmi, gestionMessage);
							if (code.equals("OK") && insertEnergy(requete)) {
								gestionMessage.afficheMessage("Enregistrement de l'énergie car la signature est bonne.");
								reponse.put("code", "OK");
							}
							//gestionMessage.afficheMessage("Requête reçue d'un PONE :" + requete + "\nRéponse envoyée :" + reponse + "\n");
							break;
					}
				} catch (Exception e) {
					gestionMessage.afficheErreur("Erreur lors du traitement de la requête : " + e + "\nRequête : " + requete);
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

