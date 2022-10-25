import java.io.IOException;

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
public class ServeurUDP {

    public static int portEcoute = 2025;

    public static void main(String[] args) {
        while (true) {

        // Création de la socket
        DatagramSocket socket = null;
        try {        
            socket = new DatagramSocket(portEcoute);
        } catch(SocketException e) {
            System.err.println("Erreur lors de la création de la socket : " + e);
            System.exit(0);
        }

        // Création du message
        byte[] tampon = new byte[1024];
        DatagramPacket msg = new DatagramPacket(tampon, tampon.length);

        // Lecture du message du client
        String texte = "";
        try {
            socket.receive(msg);
            texte = new String(msg.getData(), 0, msg.getLength());
            System.out.println("Lu: " + texte);
        } catch(IOException e) {
            System.err.println("Erreur lors de la réception du message : " + e);
            System.exit(0);
        }

        // Création du message
        try {
            InetAddress adresse = InetAddress.getByName(null);
            String message = "Bonjour Client "+msg.getAddress().getHostAddress()+" ayant répondu \""+texte+"\"";
            tampon = message.getBytes();
            msg = new DatagramPacket(tampon, tampon.length, adresse, portEcoute+1);
            
        } catch(UnknownHostException e) {
            System.err.println("Erreur lors de la création du message : " + e);
            System.exit(0);
        }

        // Envoi du message
        try {
            socket.send(msg);
        } catch(IOException e) {
            System.err.println("Erreur lors de l'envoi du message : " + e);
            System.exit(0);
        }

        // Fermeture de la socket
        socket.close();
    }}
}

