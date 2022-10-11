package bu_01;

import java.util.GregorianCalendar;
import org.json.JSONObject;

/**
 * Classe de test du package bu_1
 * @author J.-C. BOISSON (2021-2023)
 * @version 1.1
 */
public class Test_BU_1 {

    /**
     * Constructeur par défault
     */
    public Test_BU_1(){}

    /**
     * Méthode principale classique
     * 
     * @param args Arguments de la ligne de commande (non utilisés ici)
     */
    public static void main(String[] args) {
        Auteur jrrT = new Auteur("J.R.R Tolkien", new GregorianCalendar(1982, 01, 03));
        System.out.println("\n"+jrrT+"\n");

        JSONObject objet = jrrT.toJSON();
        System.out.println(objet);
        
        BU bu = new BU();
        bu.ajouterLivre(new Livre("Le seigneur des anneaux", jrrT));
        bu.ajouterLivre(new Livre("Eragon", new Auteur("Christopher Paolini", new GregorianCalendar(1983,11,17))));
        bu.ajouterLivre(new Livre("Le Silmarillion", jrrT));
        System.out.println("\n"+bu.toJSON()+"\n");

        BU bu2 = BU.fromJSON(bu.toJSON());
        System.out.println("\n"+bu2.toJSON()+"\n\n"+bu+bu2+"\n");
    }
}

