
package src;

import java.util.Scanner;

import src.ami.ServeurTCPAMI;
import src.gros.ServeurUDPGros;
import src.pone.ClientUDPPONE;
import src.tare.ServeurHttpTARE;

public class Lanceur {

	public static void main(String[] args) {
		System.err.println("\n\n\n\n\n\n\n\n\n\n\n" + ConsoleColors.GREEN_BRIGHT + "Lancement du projet...\n"
				+ ConsoleColors.RESET);

		// Fichier de configuration
		String fileString = args.length == 0 ? "config.json" : args[0];
		Configuration config = new Configuration(fileString, !Configuration.fichierExiste(fileString));
		String adresseServeurs = config.getString("adresseServeurs");
		int portServeurTCP = config.getInt("portServeurTCP");
		int portServeurUDP = config.getInt("portServeurUDP");
		int portServeurHTTP = config.getInt("portServeurHTTP");
		int portServeurPHP = config.getInt("portServeurPHP");

		// Lancement du Serveur TCP AMI
		ServeurTCPAMI serveurTCPAMI = new ServeurTCPAMI(portServeurTCP);
		Thread threadAMI = new Thread(serveurTCPAMI);
		threadAMI.start();

		/**
		 * Actions :
		 * 0 - Fermeture de tout
		 * 1 - Client TCP envoie une requête à l'AMI
		 * 2 - Scénario A : dans un système ayant un seul PONE et un
		 * seul TARE (en plus du revendeur, du marché de gros
		 * et de l'AMI), le client demande une quantité d'énergie
		 * sans aucune contrainte particulière et sa demande est
		 * toute de suite satisfaite car le PONE produit exactement
		 * le type d'énergie demandé. Il y a donc achat
		 * (avec enregistrement de l'achat côté AMI) puis
		 * distribution au revendeur (en passant par le TARE).
		 * 3 - ?
		 * 4 - ?
		 * 5 - ?
		 * 6 - ?
		 */

		try {
			Thread.sleep(1000);
		} catch (InterruptedException e) {
			System.err.println(ConsoleColors.RED_BRIGHT + "Erreur lors du sleep : " + e + ConsoleColors.RESET);
		}
		System.err.println(ConsoleColors.GREEN_BRIGHT + "Entrez une action entre 1 et 6 : " + ConsoleColors.RESET);
		Scanner in = new Scanner(System.in);
		String action = in.nextLine();

		switch (action) {

			case "0":
				System.exit(0);

			case "1":
				Thread t = new Thread(new ClientTCP(adresseServeurs, portServeurTCP));
				t.start();

			case "2":
				System.err.println(ConsoleColors.GREEN_BRIGHT + "Lancement du scénario A...\n" + ConsoleColors.RESET);
				System.err.println("Veuillez lancer le serveur PHP : 'cd php/' && 'php -S localhost:" + portServeurPHP + "'");

				// Lancement du Serveur UDP Gros
				Thread threadGros = new Thread(new ServeurUDPGros(portServeurUDP));
				threadGros.start();

				// Lancement du Serveur HTTP TARE
				Thread threadTARE = new Thread(new ServeurHttpTARE(adresseServeurs, portServeurHTTP, portServeurUDP));
				threadTARE.start();

				Thread pone = new Thread(new ClientUDPPONE(adresseServeurs, portServeurUDP, 100));
				pone.start();

			default:
				break;
		}
		in.close();
	}
}

