
package exercice_1;

import utils.Logger;
import utils.ConsoleColors;

public class m_main {
	private final static Logger Logger = new Logger("");

    public static void main(String[] args) throws Exception {
		System.out.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		Logger.printInfo("Début de la fonction main()\n\n", ConsoleColors.RED_BRIGHT);
        Long time = System.currentTimeMillis();

		// Initializations
		int nb_threads = 4;
		int total_threads = nb_threads * 2;
		Thread threads[] = new Thread[total_threads];

		// Création des threads
		for (int i = 0; i < total_threads; i += 2) {
			threads[i] = new ThreadExtends("Thread Extends", i/2);
			threads[i+1] = new Thread(new ThreadImplements("Thread Implements", i/2));
			threads[i].start();
			threads[i+1].start();
		}

		// Attente de la fin des threads
		for (int i = 0; i < total_threads; i++)
			threads[i].join();

        Logger.printInfo("\n\nFin de la fonction main() en " + Long.toString((System.currentTimeMillis()-time)) + "ms\n", ConsoleColors.RED_BRIGHT);
    }
}

