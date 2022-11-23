
package src;

import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.PrintWriter;

import java.net.Socket;
import java.net.UnknownHostException;

public class ClientTCP {

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
		OutputStream os = null;
		try {
			input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			os = socket.getOutputStream();
			output = new PrintWriter(new BufferedWriter(new OutputStreamWriter(os)), true);
		} catch (IOException e) {
			System.err.println("Association des flux impossible : " + e);
			System.exit(0);
		}

		// Envoi
		String message = "";
		try {
			message = "Test de chiffrement";
			byte[] bytes = ChiffrementAES.chiffrement(message);
			System.out.println("Envoi: " + new String(bytes));
			os.write(bytes);
			os.flush();
		} catch (IOException e) {
			System.err.println("Erreur lors de l'envoie des données : " + e);
			System.exit(0);	
		}

		// Lecture
		try {
			message = input.readLine();
			System.out.println("Lu: " + message);
		} catch (IOException e) {
			System.err.println("Erreur lors de la lecture : " + e);
			System.exit(0);
		}

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
