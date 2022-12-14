
package src.tare;

import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;

import src.ClientTCP;
import src.Messenger;

import com.sun.net.httpserver.Headers;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.UnsupportedEncodingException;
import java.net.URI;
import java.net.URLDecoder;

import org.json.JSONObject;

/**
 * Classe correspondant au handler pour réceptionner
 * les requêtes HTTP provenant du revendeur.
 * 
 * @author Alexandre Collignon
 */
class RevendeurHandler implements HttpHandler {
	private final String adresseServeurTCPAmi;
	private final int portServeurTCPAmi;
	private final String adresseServeurUDPTare;
	private final int portServeurUDPGros;
	private final Messenger gestionMessage;

	/**
	 * Constructeur du RevendeurHandler
	 */
	public RevendeurHandler(String adresseServeurTCPAmi, int portServeurTCPAmi, String adresseServeurUDPTare, int portServeurUDPGros, Messenger gestionMessage) {
		this.adresseServeurTCPAmi = adresseServeurTCPAmi;
		this.portServeurTCPAmi = portServeurTCPAmi;
		this.adresseServeurUDPTare = adresseServeurUDPTare;
		this.portServeurUDPGros = portServeurUDPGros;
		this.gestionMessage = gestionMessage;
	}

	/**
	 * Méthode appelée lors de la réception d'une requête HTTP
	 */
	public void handle(HttpExchange t) {
        // Récupération des données
        URI requestedUri = t.getRequestURI();
        String query = requestedUri.getRawQuery();

        // Utilisation d'un flux pour lire les données du message Http
        BufferedReader br = null;
        try {
            br = new BufferedReader(new InputStreamReader(t.getRequestBody(), "utf-8"));
        } catch (UnsupportedEncodingException e) {
            gestionMessage.afficheErreur("Erreur lors de la récupération du flux " + e);
            System.exit(0);
        }

        // Récupération des données en POST
        try {
            query = br.readLine();
        } catch (IOException e) {
            gestionMessage.afficheErreur("Erreur lors de la lecture d'une ligne " + e);
            System.exit(0);
        }

        // Affichage des données
        String reponse = "";
        if (query != null) {
            try {
                query = URLDecoder.decode(query, "UTF-8");
				JSONObject json = new JSONObject(query);
				gestionMessage.afficheMessage("Requête reçue par le revendeur, renvoie au Marché de Gros !");

				// Envoie de la commande en UDP au Marché de Gros et Récupération de la réponse
				String r = ClientTareUDP.requete(gestionMessage, json, adresseServeurUDPTare, portServeurUDPGros);
				JSONObject jsonReponse = new JSONObject(r);

				if (jsonReponse.getString("code").equals("KO")) {
					reponse = jsonReponse.toString();
					gestionMessage.afficheMessage("Réponse du marché de gros reçue, renvoie au revendeur que : " + jsonReponse.getString("message"));
				}
				else {
					// Vérification du CRADO de l'énergie
					JSONObject reqToAMI = new JSONObject();
					reqToAMI.put("type", "TARE");
					reqToAMI.put("energy", jsonReponse.getJSONObject("energy"));
					String code = ClientTCP.requeteToAMI(reqToAMI, adresseServeurTCPAmi, portServeurTCPAmi, gestionMessage);
					if (code.equals("OK")) {
						reponse = jsonReponse.toString();
						gestionMessage.afficheMessage("Réponse du marché de gros reçue, renvoie au revendeur car le CRADO est valide !");
					}
					else {
						JSONObject jsonErreur = new JSONObject();
						jsonErreur.put("code", "KO");
						jsonErreur.put("message", "Erreur lors de la vérification du CRADO de l'énergie");
						reponse = jsonErreur.toString();
						gestionMessage.afficheMessage("Réponse du marché de gros reçue, erreur lors de la vérification du CRADO de l'énergie !");
					}
				}

            } catch (UnsupportedEncodingException e) {
				gestionMessage.afficheErreur("Erreur lors du décodage de la requête " + e);
			}
        }

		// Envoi de l'en-tête Http
		try {
			Headers h = t.getResponseHeaders();
			h.set("Content-Type", "text/html; charset=utf-8");
			t.sendResponseHeaders(200, reponse.getBytes().length);
		} catch (IOException e) {
			gestionMessage.afficheErreur("Erreur lors de l'envoi de l'en-tête : " + e);
			return;
		}

		// Envoi du corps (données HTML)
		try {
			OutputStream os = t.getResponseBody();
			os.write(reponse.getBytes());
			os.close();
		} catch (IOException e) {
			gestionMessage.afficheErreur("Erreur lors de l'envoi du corps : " + e);
		}
	}
}
