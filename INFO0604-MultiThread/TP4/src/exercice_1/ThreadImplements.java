
package exercice_1;

import utils.ConsoleColors;
import utils.Logger;

public class ThreadImplements implements Runnable {
	private Logger Logger;
	private int id;

	public ThreadImplements(String name, int id) {
		this.Logger = new Logger(name + " #" + Integer.toString(id));
		this.id = id;
	}

	public void run() {
		// Logger.printWarning("Début du thread");

		// Hello World!
		Logger.printInfo("Hello World! Je suis " + Thread.currentThread().getId() + " et je suis nommé " + Thread.currentThread().getName(), ConsoleColors.PURPLE_BRIGHT);
		
		// Logger.printWarning("Fin du thread");
	}
}
