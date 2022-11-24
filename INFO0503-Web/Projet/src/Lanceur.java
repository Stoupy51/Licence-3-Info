
package src;

import java.util.Scanner;

import src.ami.ServeurTCPAMI;

public class Lanceur {
	Lanceur() {}

	public static void main(String[] args) {
		System.err.println("\n\n\n\n\n\n\n\n\n\n\n" + ConsoleColors.GREEN_BRIGHT + "Lancement du projet...\n" + ConsoleColors.RESET);

		// Fichier de configuration
		String fileString = args.length == 0 ? "config.json" : args[0];
		Configuration config = new Configuration(fileString, !Configuration.fichierExiste(fileString));
		String adresseServeurTCP = config.getString("adresseServeurTCP");
		int portServeurTCP = config.getInt("portServeurTCP");



		// Lancement du Serveur TCP AMI
		ServeurTCPAMI serveurTCPAMI = new ServeurTCPAMI(portServeurTCP);
		Thread threadAMI = new Thread(serveurTCPAMI);
		threadAMI.start();

		/**
		 * Actions :
		 * 0 - Fermeture de tout
		 * 1 - Client TCP envoie une requête à l'AMI
		 * 2 - ?
		 * 3 - ?
		 * 4 - ?
		 * 5 - ?
		 * 6 - ?
		 */
		while (true) {
			System.err.println(ConsoleColors.GREEN_BRIGHT + "Entrez une action entre 1 et 6 : " + ConsoleColors.RESET);
			Scanner in = new Scanner(System.in);
			String action = in.nextLine();
			switch (action) {
				case "0":
					System.exit(0);
				case "1":
					Thread t = new Thread(new ClientTCP(adresseServeurTCP, portServeurTCP));
					t.start();
			}
			in.close();
		}
	}
}
