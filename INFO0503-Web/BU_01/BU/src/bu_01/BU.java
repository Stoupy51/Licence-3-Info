package bu_01;

import org.json.JSONArray;
import org.json.JSONObject;

/**
 * Classe représentant une BU.
 * @author Cyril Rabat et Jean-Charles BOISSON (2021-2023 small updates)
 * @version 1.3
 */
public class BU {

    /** compteur qui servira de clef */
    private static int compteur = 0;

    /** le conteneur pour les couples clef/livre */
    private java.util.HashMap<Integer,Livre> livres;
    
    /**
     * Crée une BU.
     */
    public BU() {
        livres = new java.util.HashMap<Integer,Livre>();
    }
        
    /**
     * Ajoute un livre à la BU et retourne son identifiant.
     * @param livre le livre à ajouter
     * @return l'identifiant du livre ajouté
     */
    public int ajouterLivre(Livre livre) {

        System.out.println("En "+compteur+", ajout du livre de titre : \""+livre.getTitre()+"\"");

        livres.put(compteur, livre);
        // La valeur est bien renvoyée avant d'être incrémentée localement.
        return compteur++;
    }
    
    /** 
     * Retourne un livre associe a une clef (s'il existe).
     * @param i la clef du livre
     * @return le livre (ou null)
     */
    public Livre getLivre(int i) {
	    // En JAVA, int et Integer profite d'une conversion implicite
        if(livres.containsKey(i))
	        return livres.get(i);
	    return null;  
    }

    /**
     * Convertit la BU en chaine de caractères.
     * @return une chaine de caractères
     */
    @Override
    public String toString() {
        
        if(livres.size()==0)
            return "La BU est vide pour le moment ...";
        
        String contenu_BU="Contenu actuel de la BU :\n";

	    // Version sans utilisation du mot clef "var" <=> il faut indiquer explicitement les types que l'on utilise
	    java.util.Iterator<java.util.Map.Entry<Integer,Livre>> entrees = livres.entrySet().iterator();
	    while(entrees.hasNext()) {
	        java.util.Map.Entry<Integer,Livre> entree = entrees.next();
	        contenu_BU+="\t"+entree.getKey()+" = "+entree.getValue().toString()+"\n";
	    }

	    // Version avec l'utilisation du mot clef  "var" <=> il faut se douter des types utilises (notamment pour le getKey et getValue)
	    /*var entrees = livres.entrySet().iterator();
	    while(entrees.hasNext()) {
	        var entree = entrees.next();
	        contenu_BU+="\t"+entree.getKey()+" = "+entree.getValue().toString()+"\n";
	    }*/

	    // Version apparemment plus simple mais avec des performances bien moindre
        /*for(int cle : livres.keySet()){
            contenu_BU+="\t"+cle+" = "+livres.get(cle).toString()+"\n";
	    }*/

        return contenu_BU;
    }
    
    /**
     * @return la BU convertie en objet JSON
     */
    public JSONObject toJSON() {
        JSONObject objet = new JSONObject();
        JSONArray livresArray = new JSONArray();
        for (int i = compteur - livres.size(); i < compteur; i++) {
            livresArray.put(getLivre(i).toJSON());
        }
        objet.put("livres", livresArray);
        return objet;
    }

    /**
     * Crée une BU à partir d'un JSONObject
     * @param json
     */
    public static BU fromJSON(JSONObject json) {
        BU bu = new BU();
        JSONArray livresArray = json.optJSONArray("livres");
        for (int i = 0; i < livresArray.length(); i++) {
            bu.ajouterLivre(Livre.fromJSON(livresArray.getJSONObject(i)));
        }
        return bu;
    }

}

