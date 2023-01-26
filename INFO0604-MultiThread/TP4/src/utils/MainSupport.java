
package utils;

public class MainSupport {
	private Logger logger;
	private long time;
	private long ms;

    public MainSupport(Logger logger) {
		this.logger = logger;
        this.time = System.nanoTime();
		this.ms = System.currentTimeMillis();

		System.out.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		this.logger.printInfo("Début de la fonction main()\n\n", ConsoleColors.RED_BRIGHT);
	}

	/**
	 * Affichage du temps d'exécution selon l'ordre de grandeur
	 */
	public void end() {
		long time = System.nanoTime() - this.time;
		long ms = System.currentTimeMillis() - this.ms;
		String time_s = "";

		// Convertion en µs, ms ou s tout en gardant 3 chiffres après la virgule
		if (time < 1000) {
			time_s = Long.toString(time) + "ns";
		} else if (time < 1000000) {
			time_s = String.format("%.3f", (double)time/1000) + "µs";
		} else if (ms < 1000) {
			time_s = String.format("%.3f", (double)time/1000000) + "ms";
		} else if (ms < 1000 * 60) {
			time_s = String.format("%.3f", (double)ms/1000) + "s";
		} else if (ms < 1000 * 60 * 60) {
			time_s = String.format("%.3f", (double)ms/(1000 * 60)) + "min";
		} else {
			time_s = String.format("%.3f", (double)ms/(1000 * 60 * 60)) + "h";
		}
		
		this.logger.printInfo("\n\nFin de la fonction main() en " + time_s + "\n", ConsoleColors.RED_BRIGHT);
	}
}

