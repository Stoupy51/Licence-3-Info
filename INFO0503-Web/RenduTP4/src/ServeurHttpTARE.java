
import java.io.IOException;
import com.sun.net.httpserver.HttpServer;
import java.net.InetSocketAddress;

/**
 * Classe correspondant à un serveur Http pour les TARE.
 * Le serveur écoute sur le port 8080.
 * 
 * @author Alexandre Collignon
 */
public class ServeurHttpTARE {

    public static void main(String[] args) {
        HttpServer serveur = null;
        try {
            serveur = HttpServer.create(new InetSocketAddress(8080), 0);
        } catch (IOException e) {
            System.err.println("Erreur lors de la création du serveur " + e);
            System.exit(0);
        }

        serveur.createContext("/", new AccueilHandler());
        serveur.setExecutor(null);
        serveur.start();

        System.out.println("Serveur TARE démarré. Pressez CTRL+C pour arrêter.");
    }
}

