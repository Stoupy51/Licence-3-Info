
package exercice_1;

import utils.ConsoleColors;
import utils.Logger;

public class ThreadExtends extends Thread {
	private Logger Logger;
	private int id;

	public ThreadExtends(String name, int id) {
		this.Logger = new Logger(name + " #" + Integer.toString(id));
		this.id = id;
	}

	public void run() {
		// Logger.printWarning("Début du thread");

		// Hello World!
		Logger.printInfo("Hello World! Je suis " + getId() + " et je suis nommé " + getName(), ConsoleColors.BLUE_BRIGHT);
		
		id = 0;
		// Logger.printWarning("Fin du thread");
	}
}
