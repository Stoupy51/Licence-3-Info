
import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;
import com.sun.net.httpserver.Headers;
import java.io.IOException;
import java.io.OutputStream;
import java.nio.file.Files;
import java.nio.file.Paths;

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
			// Page d'accueil
			for (String s : Files.readAllLines(Paths.get("website/index.html"))) {
				reponse += s;
			}
        } catch (IOException e) {
            System.err.println("Fichier introuvable : " + e);
            reponse = "Erreur 404: Fichier Introuvable";
            rCode = 404;
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

