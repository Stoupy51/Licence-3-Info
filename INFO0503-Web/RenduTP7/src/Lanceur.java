
package src;

import src.ami.ServeurTCPAMI;

public class Lanceur {
	Lanceur() {}

	public static void main(String[] args) {
		System.err.println("\n\n\n\n\n\n\n\n\n\n\n" + ConsoleColors.GREEN_BRIGHT + "Lancement du programme...\n" + ConsoleColors.RESET);

		// Fichier de configuration
		String fileString = args.length == 0 ? "config.json" : args[0];
		Configuration config = new Configuration(fileString, !Configuration.fichierExiste(fileString));
		String adresseServeurTCP = config.getString("adresseServeurTCP");
		int portServeurTCP = config.getInt("portServeurTCP");

		// Lancement du Serveur TCP AMI
		ServeurTCPAMI serveurTCPAMI = new ServeurTCPAMI(portServeurTCP);
		Thread threadAMI = new Thread(serveurTCPAMI);
		threadAMI.start();

		// Lancement du Client TCP
		ClientTCP clientTCP = new ClientTCP(adresseServeurTCP, portServeurTCP);
		Thread threadClientTCP = new Thread(clientTCP);
		threadClientTCP.start();
	}
}
