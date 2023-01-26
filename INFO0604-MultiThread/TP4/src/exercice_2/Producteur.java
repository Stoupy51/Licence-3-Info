
package exercice_2;

import java.util.Random;

import utils.ConsoleColors;
import utils.Logger;

public class Producteur implements Runnable {
	private Logger Logger;
	private BoiteMsg boite;
	private String msg[];

	public Producteur(String name, int id, BoiteMsg boite) {
		this.Logger = new Logger(name + " #" + Integer.toString(id));
		this.boite = boite;
		this.msg = new String[] {
			"Bonjour",
			"Je vais bien",
			"Terminé"
		};
	}

	public void run() {
		// Logger.printWarning("Début du thread");

		// Envoie progressif des messages
		for (int i = 0; i < msg.length; i++) {
			Logger.printInfo("Envoie du message \"" + msg[i] + "\"", ConsoleColors.GREEN_BRIGHT);
			boite.deposer(this.Logger.getPrefix() + msg[i]);
			
			do {
				try {
					Thread.sleep(new Random().nextInt(4000) + 1000 + 1);
				} catch (Exception e) {
					Logger.printError("Erreur lors de l'attente : " + e.getMessage());
				}
			} while (!boite.deposer(this.Logger.getPrefix() + msg[i]));
		}
		
		Logger.printWarning("Fin du thread");
	}
}

