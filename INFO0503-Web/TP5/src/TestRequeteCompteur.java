
package src;

import java.io.ByteArrayOutputStream;
import java.io.ByteArrayInputStream;
import java.io.ObjectOutputStream;
import java.io.ObjectInputStream;
import org.json.JSONObject;

/**
 * Classe pour vérifier et comprendre le fonctionnement de l'objet RequeteCompteur
 */
public class TestRequeteCompteur {

    /**
     * Constructeur NON UTILISE (c'est juste pour éviter un warning lors de la génération de la documentation)
     */
    public TestRequeteCompteur() {}

    /**
     * Méthode main classique qui lance les tests.
     * 
     * @param args Les arguments de la ligne de commande (non utilisés ici)
     */
    public static void main(String[] args) {

        var requete = new RequeteCompteur("Spiderman", 22);

        System.out.println();
        System.out.println("requete en String       : "+ requete);        
        System.out.println("requete en String json  : "+requete.toJSON());
    
        System.out.println();

        var baos = new ByteArrayOutputStream();
        try {
            ObjectOutputStream oos = new ObjectOutputStream(baos);
            oos.writeObject(requete);
        } catch(java.io.IOException e) {
            System.err.println("Erreur lors de la sérialisation : " + e);
            System.exit(0);
        }
        
        byte[] donnees = baos.toByteArray();

        RequeteCompteur requete2=null;
        var bais = new ByteArrayInputStream(donnees);     
        
        try {
            var ois = new ObjectInputStream(bais);    
            requete2 = (RequeteCompteur) ois.readObject();
        } catch(java.io.IOException | ClassNotFoundException e) {
            System.err.println("Erreur lors de la désérialisation : " + e);
            System.exit(0);
        }
        System.out.println("requete2 en String      : "+requete2);
        System.out.println("requete2 en String JSON : "+requete2.toJSON());
        System.out.println();

        System.out.println("requete et requete2 représente le même objet    ? "+(requete==requete2?"OUI":"NON"));
        System.out.println("requete et requete2 sont logiquement identiques ? "+(requete.equals(requete2)?"OUI":"NON"));
        
        System.out.println();

        RequeteCompteur requete3=RequeteCompteur.fromJSON(requete.toJSON());

        System.out.println("requete3 en String      : "+requete3);
        System.out.println("requete3 en String JSON : "+requete3.toJSON());
        System.out.println();

        System.out.println("requete et requete3 représente le même objet    ? "+(requete==requete3?"OUI":"NON"));
        System.out.println("requete et requete3 sont logiquement identiques ? "+(requete.equals(requete3)?"OUI":"NON"));
        
        System.out.println();

        System.out.println("requete2 et requete3 représente le même objet    ? "+(requete2==requete3?"OUI":"NON"));
        System.out.println("requete2 et requete3 sont logiquement identiques ? "+(requete2.equals(requete3)?"OUI":"NON"));

        System.out.println();
    }
}
