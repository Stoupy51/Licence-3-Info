
package src;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.PrintWriter;
import java.net.Socket;

/**
 * Classe correspondant au thread associe à chaque connexion d'un client.
 */
public class ThreadConnexion extends Thread {
	private InputStream is;
	private BufferedReader input;
	private PrintWriter output;
	private Socket socketClient;

	public ThreadConnexion(Socket socketClient) {
		this.socketClient = socketClient;

		// Association d'un flux d'entrée et de sortie
		try {
			is = socketClient.getInputStream();
			input = new BufferedReader(new InputStreamReader(is));
			output = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socketClient.getOutputStream())), true);
		} catch (IOException e) {
			System.err.println("Association des flux impossible : " + e);
			System.exit(0);
		}
	}

	@Override
	public void run() {
        // Lecture de 'Bonjour'
        String message = "";
        try {
			byte[] bytes = input.readLine().getBytes();
            message = new String(bytes);
			System.out.println("Lu : " + message);

			String repDechiffre = new String(ChiffrementAES.dechiffrement(bytes));

			String send = "Chiffré & Déchiffré ["+ message + " & " + repDechiffre + "]";
			System.out.println("Envoyé : " + send);
			output.println(send);
		}

		// Ensemble des catches
		catch (IOException e) {
			System.err.println("Erreur lors de la lecture de la requête : " + e);
			System.exit(0);
		}

		// Fermeture des flux et des sockets
		try {
			input.close();
			output.close();
			socketClient.close();
		} catch (IOException e) {
			System.err.println("Erreur lors de la fermeture des flux et des sockets : " + e);
			System.exit(0);
		}
	}
}
