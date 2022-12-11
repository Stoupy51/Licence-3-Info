
package src;

import java.util.Scanner;

import org.json.JSONObject;

import src.ami.ServeurTCPAMI;
import src.gros.ServeurUDPGros;
import src.pone.ClientPONE;
import src.tare.ServeurHttpTARE;

public class Lanceur {

	public static void main(String[] args) {
		System.err.println(
			"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
			+ ConsoleColors.GREEN_BRIGHT
			+ "Lancement du projet...\nVidage du fichier logs.txt...\n"
			+ ConsoleColors.RESET);

		// Vidage du fichier logs.txt
		Messenger.resetLogsFile();

		// Fichier de configuration
		String fileString = args.length == 0 ? "config.json" : args[0];
		JSONObject config = new JSONFile(fileString, !JSONFile.fichierExiste(fileString)).getJSON();
		String adresseServeurs = config.getString("adresseServeurs");
		int portServeurTCP = config.getInt("portServeurTCP");
		int portServeurUDP = config.getInt("portServeurUDP");
		int portServeurHTTP = config.getInt("portServeurHTTP");
		int portServeurPHP = config.getInt("portServeurPHP");

		System.err.println(ConsoleColors.GREEN_BRIGHT + "Entrez une action entre 1 et 6 : " + ConsoleColors.RESET);
		System.err.println("0 - Scénario A : Système avec une entité de chaque (Revendeur, TARÉ, Marché de Gros, PONE, Ami). Le client demande une quantité d'énergie sans aucune contrainte particulière et sa demande est toute de suite satisfaite car le PONE produit exactement le type d'énergie demandé. L'AMI enregistre donc l'achat et le Revendeur valide la commande au Client.");
		System.err.println("1 - Scénario B : ?");
		Scanner in = new Scanner(System.in);
		String action = in.nextLine();

		switch (action) {

			case "0": // Scénario A
				System.err.println(ConsoleColors.GREEN_BRIGHT + "Lancement du scénario A...\n" + ConsoleColors.RESET);
				
				// Lancement du Serveur TCP AMI, puis du Serveur UDP Gros, puis du Serveur HTTP TARE, puis du Client UDP PONE
				new Thread(new ServeurTCPAMI(portServeurTCP)).start();
				new Thread(new ServeurUDPGros(adresseServeurs, portServeurTCP, portServeurUDP, true)).start();
				new Thread(new ServeurHttpTARE(adresseServeurs, portServeurTCP, adresseServeurs, portServeurHTTP, portServeurUDP)).start();

				Energie energy = new Energie(new CodeDeSuivi("0-1500.0-0.0-3-N-FR-0.05-0.0-"+System.currentTimeMillis()/1000+"-MyLittlePONE"), "");
				new Thread(new ClientPONE(adresseServeurs, portServeurUDP, adresseServeurs, portServeurTCP, 1, energy)).start();

				sleepPls(4000);
				System.err.println(ConsoleColors.GREEN_BRIGHT + "\nVeuillez lancer le serveur PHP : "+ ConsoleColors.ORANGE + "cd php/ && php -S localhost:" + portServeurPHP + ConsoleColors.RESET);
				System.err.println(ConsoleColors.GREEN_BRIGHT + "Et vous pouvez maintenant commander en allant sur le site\n" + ConsoleColors.RESET);
				break;

			case "1": // Scénario B
				break;

			case "10":
				System.err.println(ConsoleColors.GREEN_BRIGHT + "Lancement du scénario A...\n" + ConsoleColors.RESET);
				System.err.println("Veuillez lancer le serveur PHP : 'cd php/' && 'php -S localhost:" + portServeurPHP + "'");

				// Lancement du Serveur UDP Gros
				Thread threadGros = new Thread(new ServeurUDPGros(adresseServeurs, portServeurTCP, portServeurUDP, false));
				threadGros.start();

				// Lancement du Serveur HTTP TARE
				Thread threadTARE = new Thread(new ServeurHttpTARE(adresseServeurs, portServeurTCP, adresseServeurs, portServeurHTTP, portServeurUDP));
				threadTARE.start();

				// Lancement du Client UDP PONE
				Thread pone = new Thread(new ClientPONE(adresseServeurs, portServeurUDP, adresseServeurs, portServeurTCP, 100));
				pone.start();
				break;

			default:
				break;
		}
		in.close();
	}

	public static void sleepPls(int i) {
		try {
			Thread.sleep(i);
		} catch (InterruptedException e) {
			System.err.println(ConsoleColors.RED_BRIGHT + "Erreur lors du sleep : " + e + ConsoleColors.RESET);
		}
	}
}

