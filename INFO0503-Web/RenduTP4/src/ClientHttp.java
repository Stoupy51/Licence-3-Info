
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStreamWriter;
import java.net.URLConnection;
import java.net.URL;
import java.net.MalformedURLException;

/**
 * Classe correspondant à un client Http.
 * @author Alexandre Collignon
 */
public class ClientHttp {

    public static void main(String[] args) {
        String listeDonnees = "", donnees;        
        
        //listeDonnees = "nom=Terrieur&prenom=Alain";
        //System.out.println(listeDonnees);

        // Mise en forme de l'URL
        URL url = null;
        try { 
            url = new URL("http://localhost:8080/index"); 
        } catch(MalformedURLException e) { 
            System.err.println("URL incorrect : " + e);
            System.exit(0);
        }
        
        // Etablissement de la connexion
        URLConnection connexion = null; 
        try { 
            connexion = url.openConnection(); 
            connexion.setDoOutput(true);
        } catch(IOException e) { 
            System.err.println("Connexion impossible : " + e);
            System.exit(0);
        } 
        
        // Envoi de la requête
        try {
            OutputStreamWriter writer = new OutputStreamWriter(connexion.getOutputStream());
            writer.write(listeDonnees);
            writer.flush();
            writer.close();
        } catch(IOException e) {
            System.err.println("Erreur lors de l'envoi de la requete : " + e);
            System.exit(0);            
        }        
        
        // Réception des données depuis le serveur
        donnees = ""; 
        try { 
            BufferedReader reader = new BufferedReader(new InputStreamReader( connexion.getInputStream())); 
            String tmp; 
            while((tmp = reader.readLine()) != null)
                donnees += tmp; 
            reader.close(); 
        } catch(Exception e) { 
            System.err.println("Erreur lors de la lecture de la réponse : " + e);
            System.exit(0);
        }
        
        // Affichage des données reçues
        System.out.println("Réponse du serveur : ");
        System.out.println(donnees);
    }
}

