import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.PrintWriter;

import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;

/**
 * Classe correspondant à un serveur TCP.
 * Le client envoie la chaine 'Bonjour' et lit une réponse de la part du serveur.
 * Le client envoie ensuite la chaine 'Au revoir' et lit une réponse.
 * Le numéro de port du serveur est spécifié dans la classe ServeurTCP.
 * @author Cyril Rabat
 */
public class ServeurTCP {

    public static final int portEcoute = 5001;

    public static void main(String[] args) {
        // Création de la socket serveur
        ServerSocket socketServeur = null;
        try {    
            socketServeur = new ServerSocket(portEcoute);
        } catch(IOException e) {
            System.err.println("Création de la socket impossible : " + e);
            System.exit(0);
        }

        // Attente d'une connexion d'un client
        Socket socketClient = null;
        try {
            socketClient = socketServeur.accept();
        } catch(IOException e) {
            System.err.println("Erreur lors de l'attente d'une connexion : " + e);
            System.exit(0);
        }

        // Association d'un flux d'entrée et de sortie
        BufferedReader input = null;
        PrintWriter output = null;
        try {
            input = new BufferedReader(new InputStreamReader(socketClient.getInputStream()));
            output = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socketClient.getOutputStream())), true);
        } catch(IOException e) {
            System.err.println("Association des flux impossible : " + e);
            System.exit(0);
        }

        // Lecture de 'Bonjour'
        String message = "";
        try {
            message = input.readLine();
        } catch(IOException e) {
            System.err.println("Erreur lors de la lecture : " + e);
            System.exit(0);
        }
        System.out.println("Lu: " + message);

        // Envoi de 'Bonjour Client!'
        message = "Bonjour Client!";
        System.out.println("Envoi: " + message);
        output.println(message);

        int pfc = 1;
		while (pfc == 1) {
			int scoreServeur = 0;
			int scoreClient = 0;
			while (scoreClient < 3 || scoreServeur < 3) {
				output.println("Que jouez-vous ? (P/F/C)");
				int pick = (int)(Math.random() * 2);
				message = "";
				try {
					message = input.readLine();
					int clientPick = Integer.parseInt(message);
					if (pick == clientPick) {
						output.println("Egalité !");
					}
					else if ((pick + 1 % 3) > (clientPick + 1 % 3)) {
						output.println("Perdu !");
						scoreServeur++;
					}
					else {
						output.println("Gagné !");
						scoreClient++;
					}
					output.println("Score [S-C] : " + Integer.toString(scoreServeur) + "-" + Integer.toString(scoreClient));
				} catch(IOException e) {
					System.err.println("Erreur lors de la lecture : " + e);
					System.exit(0);
				}
			}
			if (scoreClient > scoreServeur) {
				output.println("Vous avez gagné la partie !");
			}
			else {
				output.println("Vous avez perdu la partie !");
			}
			
			output.println("Voulez-vous rejouer au Pierre-Feuille-Ciseau ? (Y/n)");
			message = "";
			try {
				message = input.readLine();
			} catch(IOException e) {
				System.err.println("Erreur lors de la lecture : " + e);
				System.exit(0);
			}
			if (message.equals("n")) {
				pfc = 0;
			}
		}
        
        // Fermeture des flux et des sockets
        try {
            input.close();
            output.close();
            socketClient.close();
            socketServeur.close();
        } catch(IOException e) {
            System.err.println("Erreur lors de la fermeture des flux et des sockets : " + e);
            System.exit(0);
        }
    }

}