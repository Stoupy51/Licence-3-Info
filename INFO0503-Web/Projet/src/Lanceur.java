
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
		System.err.println("\n1 - Scénario A : Système avec une entité de chaque (Revendeur, TARÉ, Marché de Gros, PONE, Ami). Le client demande une quantité d'énergie sans aucune contrainte particulière et sa demande est toute de suite satisfaite car le PONE produit exactement le type d'énergie demandé. Le Revendeur valide donc la commande au Client.");
		System.err.println("\n2 - Scénario B : Système comme le scénario A. Le client demande une quantité d'énergie sans aucune contrainte particulière et sa demande n'est pas satisfaite car le Marché de Gros ne possède aucune énergie enregistrée. Mais la commande peut être satisfaite au bout d'un certain temps (30 secondes) où PONE produit exactement le type d'énergie demandé. Le Revendeur valide donc la commande au Client.");
		System.err.println("\n3 - Scénario C : Système comme le scénario A. Le client demande une quantité d'énergie avec la contrainte de la localisation de production de l'énergie (Nucléaire) et sa demande n'est pas satisfaite car le Marché de Gros ne possède aucune énergie enregistrée respectant la demande. Mais la commande peut être satisfaite au bout d'un certain temps (30 secondes) où un autre PONE (nommé PONE 2) arrive sur le marché et produit exactement le type d'énergie demandé. Le Revendeur valide la commande au Client.");
		System.err.println("\nx - Scénario D : Non Fonctionnel.");
		System.err.println("\nx - Scénario A2 : Non Fonctionnel MAIS le CRADO est généré de base dans tous les cas et scénarios.");
		System.err.println("");

		Scanner in = new Scanner(System.in);
		String action = in.nextLine();

		Energie energy = null;
		switch (action) {

			case "1": // Scénario A
				System.err.println(ConsoleColors.GREEN_BRIGHT + "Lancement du scénario A...\n" + ConsoleColors.RESET);
				
				// Lancement du Serveur TCP AMI, puis du Serveur UDP Gros, puis du Serveur HTTP TARE, puis du Client UDP PONE
				new Thread(new ServeurTCPAMI(portServeurTCP)).start();
				new Thread(new ServeurUDPGros(adresseServeurs, portServeurTCP, portServeurUDP, true)).start();
				new Thread(new ServeurHttpTARE(adresseServeurs, portServeurTCP, adresseServeurs, portServeurHTTP, portServeurUDP)).start();

				energy = new Energie(new CodeDeSuivi("0-1500.0-0.0-3-N-FR-0.05-0.0-"+System.currentTimeMillis()/1000+"-MyLittlePONE"), "");
				new Thread(new ClientPONE(adresseServeurs, portServeurUDP, adresseServeurs, portServeurTCP, 1, energy)).start();

				sleepPls(4000);
				System.err.println(ConsoleColors.GREEN_BRIGHT + "\nVeuillez lancer le serveur PHP dans un autre terminal si ce n'est pas déjà le cas : "+ ConsoleColors.ORANGE + "cd php/ && php -S localhost:" + portServeurPHP + ConsoleColors.RESET);
				System.err.println(ConsoleColors.GREEN_BRIGHT + "Et vous pouvez maintenant commander en allant sur le site\n" + ConsoleColors.RESET);
				break;

			case "2": // Scénario B
				System.err.println(ConsoleColors.GREEN_BRIGHT + "Lancement du scénario B...\n" + ConsoleColors.RESET);
				
				// Lancement du Serveur TCP AMI, puis du Serveur UDP Gros, puis du Serveur HTTP TARE, puis du Client UDP PONE
				new Thread(new ServeurTCPAMI(portServeurTCP)).start();
				new Thread(new ServeurUDPGros(adresseServeurs, portServeurTCP, portServeurUDP, true)).start();
				new Thread(new ServeurHttpTARE(adresseServeurs, portServeurTCP, adresseServeurs, portServeurHTTP, portServeurUDP)).start();

				sleepPls(1000);
				System.err.println(ConsoleColors.GREEN_BRIGHT + "\nVeuillez lancer le serveur PHP dans un autre terminal si ce n'est pas déjà le cas : "+ ConsoleColors.ORANGE + "cd php/ && php -S localhost:" + portServeurPHP + ConsoleColors.RESET);
				System.err.println(ConsoleColors.GREEN_BRIGHT + "Et vous pouvez maintenant commander en allant sur le site\n" + ConsoleColors.RESET);

				// Ajout du PONE qui va produire de l'énergie
				sleepPls(30000);
				energy = new Energie(new CodeDeSuivi("0-1500.0-0.0-3-N-FR-0.05-0.0-"+System.currentTimeMillis()/1000+"-MyLittlePONE"), "");
				new Thread(new ClientPONE(adresseServeurs, portServeurUDP, adresseServeurs, portServeurTCP, 1, energy)).start();
				break;
			
			case "3": // Scénario C
				System.err.println(ConsoleColors.GREEN_BRIGHT + "Lancement du scénario C...\n" + ConsoleColors.RESET);
				
				// Lancement du Serveur TCP AMI, puis du Serveur UDP Gros, puis du Serveur HTTP TARE, puis du Client UDP PONE
				new Thread(new ServeurTCPAMI(portServeurTCP)).start();
				new Thread(new ServeurUDPGros(adresseServeurs, portServeurTCP, portServeurUDP, true)).start();
				new Thread(new ServeurHttpTARE(adresseServeurs, portServeurTCP, adresseServeurs, portServeurHTTP, portServeurUDP)).start();

				energy = new Energie(new CodeDeSuivi("0-1500.0-0.0-4-N-FR-0.05-0.0-"+System.currentTimeMillis()/1000+"-MyLittlePONE_Charbon"), "");
				new Thread(new ClientPONE(adresseServeurs, portServeurUDP, adresseServeurs, portServeurTCP, 1, energy)).start();

				sleepPls(4000);
				System.err.println(ConsoleColors.GREEN_BRIGHT + "\nVeuillez lancer le serveur PHP dans un autre terminal si ce n'est pas déjà le cas : "+ ConsoleColors.ORANGE + "cd php/ && php -S localhost:" + portServeurPHP + ConsoleColors.RESET);
				System.err.println(ConsoleColors.GREEN_BRIGHT + "Et vous pouvez maintenant commander en allant sur le site\n" + ConsoleColors.RESET);

				// Ajout du PONE qui va produire de l'énergie
				sleepPls(30000);
				energy = new Energie(new CodeDeSuivi("0-1500.0-0.0-3-N-FR-0.05-0.0-"+System.currentTimeMillis()/1000+"-PONE_2_Nucleaire"), "");
				new Thread(new ClientPONE(adresseServeurs, portServeurUDP, adresseServeurs, portServeurTCP, 1, energy)).start();
				break;

			case "10":
				System.err.println(ConsoleColors.GREEN_BRIGHT + "Lancement du scénario A...\n" + ConsoleColors.RESET);
				System.err.println("Veuillez lancer le serveur PHP dans un autre terminal : 'cd php/' && 'php -S localhost:" + portServeurPHP + "'");

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

