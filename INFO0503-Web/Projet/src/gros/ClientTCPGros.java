
package src.gros;

import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;

/**
 * Classe correspondant à un client TCP.
 * Pour le Marché de Gros
 */
public class ClientTCPGros {
	public static final int portEcoute = 5101;

	public static void main(String[] args) {
		// Création de la socket
		Socket socket = null;
		try {
			socket = new Socket("localhost", portEcoute);
		} catch (UnknownHostException e) {
			System.err.println("Erreur sur l'hôte : " + e);
			System.exit(0);
		} catch (IOException e) {
			System.err.println("Création de la socket impossible : " + e);
			System.exit(0);
		}

		// Association d'un flux d'entrée et de sortie
		BufferedReader input = null;
		PrintWriter output = null;
		try {
			input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			output = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);
		} catch (IOException e) {
			System.err.println("Association des flux impossible : " + e);
			System.exit(0);
		}

		/*/ Envoi de 'Bonjour'
		String name = "PONE 1";
		RequeteAMIGros req = new RequeteAMIGros("Marché de Gros", "5 MWH venant de " + name);
		try {
			// Send req in TCP
			OutputStream os = socket.getOutputStream();
			ObjectOutputStream oos = new ObjectOutputStream(os);
			oos.writeObject(req);
			oos.flush();
		} catch (java.io.IOException e) {
			System.err.println("Erreur lors de la sérialisation : " + e);
			System.exit(0);
		}
		System.out.println("Envoi : " + req);
		output.println(req);
		*/

		// Lecture de la réponse du serveur
		String message = "";
		try {
			message = input.readLine();
		} catch (IOException e) {
			System.err.println("Erreur lors de la lecture : " + e);
			System.exit(0);
		}
		System.out.println("Lu: " + message);

		// Fermeture des flux et de la socket
		try {
			input.close();
			output.close();
			socket.close();
		} catch (IOException e) {
			System.err.println("Erreur lors de la fermeture des flux et de la socket : " + e);
			System.exit(0);
		}
	}
}
