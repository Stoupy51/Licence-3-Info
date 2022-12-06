
package src.gros;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.net.DatagramSocket;
import java.net.DatagramPacket;
import java.net.SocketException;
import java.net.InetAddress;
import java.net.UnknownHostException;

/**
 * Classe correspondant à un serveur UDP.
 * La chaine de caractères "Bonjour" est envoyée au serveur.
 * Le port d'écoute du serveur est indiqué dans la classe ServeurUDP.
 * @author Cyril Rabat
 */
public class ServeurGrosUDP {
    public final int portEcoute = 2025;

    public static void main(String[] args) {
        while (true) {
            // Création de la socket
            DatagramSocket socket = null;
            try {        
                socket = new DatagramSocket(portEcoute);
            } catch(SocketException e) {
                System.err.println("Erreur lors de la création de la socket : " + e);
                //System.exit(0);
            }

            // Création du message
            byte[] tampon = new byte[1024];
            DatagramPacket msg = new DatagramPacket(tampon, tampon.length);

            // Lecture du message du client
            String reponse = "";
            try {
				System.out.println("Listening request...");
                socket.receive(msg);
                Requete requete = null;
                ByteArrayInputStream bais = new ByteArrayInputStream(msg.getData());     
                try {
                    ObjectInputStream ois = new ObjectInputStream(bais);    
                    requete = (Requete) ois.readObject();
					switch (requete.getType()) {
						case REQUETE_TARE:
							reponse = "Le TARE " + requete.getNom() + " envoie la requête : " + requete.getRequete();
							break;
						case REQUETE_PONE:
							reponse = "Le PONE " + requete.getNom() + " envoie la requête : " + requete.getRequete();
							break;
						default:
							break;
					}
                } catch(java.io.IOException | ClassNotFoundException e) {
                    System.err.println("Erreur lors de la désérialisation : " + e);
                    //System.exit(0);
                }
                System.out.println("Envoyé à "+ msg.getAddress().getHostAddress() + ":" + msg.getPort() + " : " + reponse);
            } catch(IOException e) {
                System.err.println("Erreur lors de la réception du message : " + e);
                //System.exit(0);
            }

            // Création du message
            try {
                InetAddress adresse = InetAddress.getByName(null);
                String message = reponse;
                tampon = message.getBytes();
                msg = new DatagramPacket(tampon, tampon.length, adresse, portEcoute + 1);
                
            } catch(UnknownHostException e) {
                System.err.println("Erreur lors de la création du message : " + e);
                //System.exit(0);
            }

            // Envoi du message
            try {
                socket.send(msg);
            } catch(IOException e) {
                System.err.println("Erreur lors de l'envoi du message : " + e);
                //System.exit(0);
            }

            // Fermeture de la socket
            socket.close();
        }
    }
}

