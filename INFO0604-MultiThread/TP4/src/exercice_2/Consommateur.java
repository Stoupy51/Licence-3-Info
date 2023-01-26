
package exercice_2;

import java.util.Random;

import utils.ConsoleColors;
import utils.Logger;

public class Consommateur implements Runnable {
	private Logger Logger;
	private BoiteMsg boite;

	public Consommateur(String name, int id, BoiteMsg boite) {
		this.Logger = new Logger(name + " #" + Integer.toString(id));
		this.boite = boite;
	}

	public void run() {
		// Logger.printWarning("Début du thread");

		// Récupération des messages
		String msg = "";
		do {
			msg = boite.recuperer();
			if (!msg.equals(""))
				Logger.printInfo("Récupération du message \"" + msg + "\"", ConsoleColors.BLUE_BRIGHT);

			try {
				Thread.sleep(new Random().nextInt(4000) + 1000 + 1);
			} catch (Exception e) {
				Logger.printError("Erreur lors de l'attente : " + e.getMessage());
			}

		} while (!msg.endsWith("Terminé"));
		
		Logger.printWarning("Fin du thread");
	}
}

