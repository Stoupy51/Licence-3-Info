
package src;

import java.io.Serializable;
import org.json.JSONObject;

/**
 * Classe correspondant a une requete du jeu du compteur. Cette classe peut-être utilisée en mode
 * sérialisé standard ou en mode sérialisé JSON.
 * @author Jean-Charles BOISSON
 * @version 1.1
 */
public class RequeteCompteur implements Serializable, Comparable<RequeteCompteur> {

    /**
     * Le nom du joueur qui est l'auteur de la requête
     */
    private String nom;
    /**
     * La valeur choisie par le joueur
     */
    private int valeur;

    /**
     * Constructeur par initialisation
     * @param nom le nom du joueur
     * @param valeur la valeur entière que le joueur va jouer
     */
    public RequeteCompteur(String nom, int valeur) {
        this.nom = nom;
        this.valeur = valeur;
    }

    /**
     * Retourne le nom de la personne
     * @return le nom de la personne
     */
    public String getNom() {
        return nom;
    }

    /**
     * Retourne la valeur choisie
     * @return retourne la proposition de valeur
     */
    public int getValeur() {
        return valeur;
    }

    /**
     * Transforme la requête en String
     * @return une chaine de caractères contenant la requête
     */
    @Override
    public String toString() {
        return nom+" propose "+valeur;
     }

     /**
      * Indique si l'autre objet RequeteCompteur est similaire (0), sinon c'est la valeur qui indique l'ordre
      * @return L'ordre entre this et l'objet RequeteCompteur
      */
     @Override
     public int compareTo(RequeteCompteur requete) {
        if(nom.compareTo(requete.nom)==0 && valeur==requete.valeur)
            return 0;
        return valeur - requete.valeur;
     }

     /**
      * Indique si l'autre objet RequeteCompteur est un RequeteCompteur logiquement identique
      * @return vrai ou faux
      */
      @Override
      public boolean equals(Object autreObjet) {

         if(autreObjet instanceof RequeteCompteur requete)
             return compareTo(requete)==0;
             
         return false;
      }

     /**
      * Transformation en JSONObject (pour obtenir ensuite un String JSON)
      * avec les getters actuel on pourrait se passer de cette méthode.
      * @return un JSONOBject décrivant la requête en cours
      */
    public JSONObject toJSON() {
        var json = new JSONObject();

        json.put("nom",nom);
        json.put("valeur",valeur);

        return json;
    } 

    /**
     * Récupération d'un objet requête depuis sa version String JSON
     * 
     * @param json La version String JSON de l'objet originel
     * 
     * @return une instance de requête contenant l'information provenant du String JSON
     */
    public static RequeteCompteur fromJSON(String json) {
        return fromJSON(new JSONObject(json));
    }

    /**
     * Récupération d'un objet requête depuis sa version JSONObject
     * 
     * @param jsonObject La version JSONObject de l'objet originel
     * 
     * @return une instance de requête contenant l'information provenant du String JSON
     */
    public static RequeteCompteur fromJSON(JSONObject jsonObject) {
        return new RequeteCompteur(jsonObject.getString("nom"), jsonObject.getInt("valeur"));
    }
}