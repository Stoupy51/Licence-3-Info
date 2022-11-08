import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.PrintWriter;
import java.util.Scanner;

import java.net.Socket;
import java.net.UnknownHostException;

/**
 * Classe correspondant à un client TCP.
 * Le client envoie la chaine 'Bonjour' et lit une réponse de la part du serveur.
 * Le client envoie ensuite la chaine 'Au revoir' et lit une réponse.
 * Le numéro de port du serveur est spécifié dans la classe ServeurTCP.
 * @author Cyril Rabat
 */
public class ClientTCP {

    public static final int portEcoute = 5001;

    public static void main(String[] args) {
        // Création de la socket
        Socket socket = null;
        try {
            socket = new Socket("localhost", portEcoute);
        } catch(UnknownHostException e) {
            System.err.println("Erreur sur l'hôte : " + e);
            System.exit(0);
        } catch(IOException e) {
            System.err.println("Création de la socket impossible : " + e);
            System.exit(0);
        }
    
        // Association d'un flux d'entrée et de sortie
        BufferedReader input = null;
        PrintWriter output = null;
        try {
            input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            output = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);
        } catch(IOException e) {
            System.err.println("Association des flux impossible : " + e);
            System.exit(0);
        }
    
        // Envoi de 'Bonjour'
        String message = "Bonjour";
        System.out.println("Envoi: " + message);
        output.println(message);

        // Lecture de 'Bonjour Client!'
        try {
            message = input.readLine();
        } catch(IOException e) {
            System.err.println("Erreur lors de la lecture : " + e);
            System.exit(0);
        }
        System.out.println("Lu: " + message);

		Scanner in = new Scanner(System.in);
        int pfc = 1;
		while (pfc == 1) {
			// Lecture du serveur
			try {
				message = input.readLine();
				System.out.println("Lu: " + message);
			} catch(IOException e) {
				System.err.println("Erreur lors de la lecture : " + e);
				System.exit(0);
			}
			
			// Envoi au serveur
			message = in.nextLine();
			if (message.equals("P") || message.equals("p")) {
				message = "0";
			}
			else if (message.equals("F") || message.equals("f")) {
				message = "1";
			}
			else if (message.equals("C") || message.equals("c")) {
				message = "2";
			}
			System.out.println("Envoi: " + message);
			output.println(message);
		}

        // Fermeture des flux et de la socket
        try {
            input.close();
            output.close();
            socket.close();
        } catch(IOException e) {
            System.err.println("Erreur lors de la fermeture des flux et de la socket : " + e);
            System.exit(0);
        }
    }

}