
package src;

import java.util.Scanner;

import src.ami.ServeurTCPAMI;
import src.pone.ClientUDPPONE;

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
		 * 2 - Scénario A : dans un système ayant un seul PONE et un
		 * 		seul TARE (en plus du revendeur, du marché de gros
		 * 		et de l'AMI), le client demande une quantité d'énergie
		 * 		sans aucune contrainte particulière et sa demande est
		 * 		toute de suite satisfaite car le PONE produit exactement
		 * 		le type d'énergie demandé. Il y a donc achat
		 * 		(avec enregistrement de l'achat côté AMI) puis
		 * 		distribution au revendeur (en passant par le TARE).
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

				case "2":
					Thread pone = new Thread(new ClientUDPPONE(adresseServeurTCP, portServeurTCP, 100));
					pone.start();

				default:
					break;
			}
			in.close();
		}
	}
}
