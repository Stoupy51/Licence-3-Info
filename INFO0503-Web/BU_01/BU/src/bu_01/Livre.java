package bu_01;

import org.json.JSONObject;

/**
 * Classe représentant un livre.
 * @author Cyril Rabat et Jean-Charles BOISSON (2022-2023 small update)
 * @version 1.2
 */
public class Livre {
    
    /** Titre du livre */
    private String titre;
    /** Auteur du livre */
    private Auteur auteur;
    
    /**
     * Crée un livre.
     * @param titre le titre
     * @param auteur l'auteur
     */
    public Livre(String titre, Auteur auteur) {
        this.titre = titre;
        this.auteur = auteur;
    }
    
    /**
     * Retourne le titre.
     * @return le titre
     */
    public String getTitre() {
        return titre;
    }
    
    /**
     * Retourne l'auteur.
     * @return l'auteur
     */
    public Auteur getAuteur() {
        return auteur;
    }
    
    /**
     * Convertit le livre en chaine de caractères.
     * @return une chaine de caractères
     */
    @Override
    public String toString() {
        return titre + " (" + auteur + ")";
    }

    /**
     * @return le livre converti en objet JSON
     */
    public JSONObject toJSON() {
        JSONObject objet = new JSONObject();
        objet.put("titre", titre);
        objet.put("auteur", auteur.toJSON());
        return objet;
    }
}

