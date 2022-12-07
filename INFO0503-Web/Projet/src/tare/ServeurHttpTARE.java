
package src.tare;

import java.io.IOException;
import com.sun.net.httpserver.HttpServer;

import src.Messenger;

import java.net.InetSocketAddress;

/**
 * Classe correspondant à un serveur Http pour les TARE.
 * Le serveur écoute sur le port 8080.
 * 
 * @author Alexandre Collignon
 */
public class ServeurHttpTARE implements Runnable {
	private final String adresseServeurUDPTare;
	private final int portServeurHTTP;
	private final int portServeurUDPGros;
	private final Messenger gestionMessage;

	/**
	 * Constructeur du ServeurHTTP (utilisable dans un Thread)
	 */
	public ServeurHttpTARE(String adresseServeurUDPTare, int portServeurHTTP, int portServeurUDPGros) {
		this.adresseServeurUDPTare = adresseServeurUDPTare;
		this.portServeurHTTP = portServeurHTTP;
		this.portServeurUDPGros = portServeurUDPGros;
		this.gestionMessage = new Messenger("ServeurHTTPTare");
	}

	@Override
	public void run() {
		HttpServer serveur = null;
		try {
			serveur = HttpServer.create(new InetSocketAddress(portServeurHTTP), 0);
		} catch (IOException e) {
			gestionMessage.afficheErreur("Erreur lors de la création du serveur " + e);
			return;
		}

		serveur.createContext("/", new RevendeurHandler(adresseServeurUDPTare, portServeurUDPGros, gestionMessage));
		serveur.setExecutor(null);
		serveur.start();

		gestionMessage.afficheWarning("Serveur HTTP TARE démarré.");
	}
}
