
package src;

import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.PrintWriter;

import java.net.Socket;
import java.net.UnknownHostException;

import org.json.JSONObject;

public class ClientTCP {
	
	public static String requeteToAMI(JSONObject json, String adrAMI, int portAMI, Messenger gestionMessage) {
		Socket socket = null;
		try {
			socket = new Socket(adrAMI, portAMI);
		} catch (UnknownHostException e) {
			gestionMessage.afficheErreur("Erreur sur l'hôte : " + e);
			return null;
		} catch (IOException e) {
			gestionMessage.afficheErreur("Création de la socket impossible : " + e);
			return null;
		}

		BufferedReader input = null;
		PrintWriter output = null;
		try {
			input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			output = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);
		} catch (Exception e) {
			gestionMessage.afficheErreur("Association des flux impossible : " + e);
			try {
				socket.close();
			} catch (Exception e2) {
				gestionMessage.afficheErreur("Erreur lors de la fermeture de la socket : " + e2);
			}
			return null;
		}

		// Envoi de la requête
		output.println(json);

		String message = "";
		try {
			message = input.readLine();
			input.close();
			output.close();
			socket.close();
		} catch (Exception e) {
			gestionMessage.afficheErreur("Erreur : " + e);
			return null;
		}
		return message;
	}
}
