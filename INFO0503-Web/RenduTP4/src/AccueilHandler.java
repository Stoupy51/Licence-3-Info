
import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;
import com.sun.net.httpserver.Headers;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.io.OutputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URI;
import java.net.URLDecoder;
import java.nio.file.Files;
import java.nio.file.Path;

/**
 * Classe correspondant au handler sur le contexte 'index.html'.
 * 
 * @author Alexandre Collignon
 */
class AccueilHandler implements HttpHandler {

    public void handle(HttpExchange t) {
        int rCode = 200;
        String reponse = "";
        try {
            reponse += Files.readString(Path.of("website/index.html"));
        } catch (IOException e) {
            System.err.println("Fichier introuvable : " + e);
            reponse = "Erreur 404: Fichier Introuvable";
            rCode = 404;
        }

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
        reponse += "<p>Données en POST : ";
        if (query == null)
            reponse += "<b>Aucune</b></p>";
        else {
            try {
                query = URLDecoder.decode(query, "UTF-8");
            } catch (UnsupportedEncodingException e) {
                query = "";
            }
            reponse += "<b>" + query + "</b></p>";
        }

        // Envoi de l'en-tête Http
        try {
            Headers h = t.getResponseHeaders();
            h.set("Content-Type", "text/html; charset=utf-8");
            t.sendResponseHeaders(rCode, reponse.getBytes().length);
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

