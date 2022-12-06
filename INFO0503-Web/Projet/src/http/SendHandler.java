package src.http;

import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;

import src.CodeDeSuivi;

import com.sun.net.httpserver.Headers;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.io.OutputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URI;
import java.net.URLDecoder;

import org.json.JSONObject;

/**
 * Classe correspondant au handler sur le contexte 'send.html'.
 * 
 * @author Alexandre Collignon
 */
class SendHandler implements HttpHandler {

    public void handle(HttpExchange t) {
        // Récupération des données
        URI requestedUri = t.getRequestURI();
        String query = requestedUri.getRawQuery();

        // Utilisation d'un flux pour lire les données du message Http
        BufferedReader br = null;
        try {
            br = new BufferedReader(new InputStreamReader(t.getRequestBody(), "utf-8"));
        } catch (UnsupportedEncodingException e) {
            System.err.println("Erreur lors de la récupération du flux " + e);
            System.exit(0);
        }

        // Récupération des données en POST
        try {
            query = br.readLine();
        } catch (IOException e) {
            System.err.println("Erreur lors de la lecture d'une ligne " + e);
            System.exit(0);
        }

        // Affichage des données
        String reponse = "";
        if (query == null)
            reponse += "<b>Aucune donnée reçue</b>";
        else {
            try {
                query = URLDecoder.decode(query, "UTF-8");
				// Decode query : "type=commande&data=0-2573.0-1200.0-3-true-FR-0.1546-400.0-1665232943"
				String[] split = query.split("&");
				String type = split[0].split("=")[1];
				if (type.equals("commande")) {
					String data = split[1].split("=")[1];
					CodeDeSuivi code;
					// Décodage des données de la commande : JSON complet ou Code de suivi en texte
					if (data.startsWith("{")) {
						JSONObject objet = new JSONObject(data);
						code = CodeDeSuivi.fromJSON(objet);
					}
					else {
						code = new CodeDeSuivi(data);
					}
					reponse = code.toJSON().toString();
				}
				else {
					reponse = "Erreur : type de requête inconnu : " + type;
				}
            } catch (UnsupportedEncodingException e) {
				System.err.println("Erreur lors du décodage de la requête " + e);
			}
        }

        // Envoi de l'en-tête Http
        try {
            Headers h = t.getResponseHeaders();
            h.set("Content-Type", "application/json; charset=utf-8");
            t.sendResponseHeaders(200, reponse.getBytes().length);
        } catch (IOException e) {
            System.err.println("Erreur lors de l'envoi de l'en-tête : " + e);
            System.exit(0);
        }

        // Envoi du corps (données HTML)
        try {
            OutputStream os = t.getResponseBody();
            os.write(reponse.getBytes());
            os.close();
        } catch (IOException e) {
            System.err.println("Erreur lors de l'envoi du corps : " + e);
        }
    }
}

