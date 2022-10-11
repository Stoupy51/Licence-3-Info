package bu_01;

import java.util.Calendar;
import java.util.GregorianCalendar;

import org.json.JSONObject;

import java.time.format.DateTimeFormatter;

/**
 * Classe représentant un(e) auteur (autrice) de livre.
 * @author Cyril Rabat et Jean-Charles BOISSON (2022-2023 small update)
 * @version 1.1
 */
public class Auteur {

    /** Nom de l'auteur*/
    private String nom;
    /** Sa date de naissance*/
    private GregorianCalendar dateDeNaissance;
   
    /**
     * Crée un auteur avec un nom et une date de naissance.
     * @param nom le nom
     * @param dateDeNaissance la date de naissance
     */
    public Auteur(String nom, GregorianCalendar dateDeNaissance) {
        this.nom = nom;
        this.dateDeNaissance = dateDeNaissance;
    }
    
    /**
     * Retourne le nom.
     * @return le nom
     */
    public String getNom() {
        return nom;
    }
    
    /**
     * Retourne la date de naissance.
     * @return la date de naissance
     */
    public GregorianCalendar getDateDeNaissance() {
        return dateDeNaissance;
    }
    
    /**
     * Convertit l'auteur en chaine de caractères.
     * @return une chaine de caractères au format "nom, jour mois année"
     */
    @Override
    public String toString() {
        // Adaptation de la sortie selon le format jour/mois/année
        // voir aussi : https://docs.oracle.com/en/java/javase/19/docs/api/java.base/java/time/format/DateTimeFormatter.html
        String dateFormatee = dateDeNaissance.toZonedDateTime().format(DateTimeFormatter.ofPattern("d MMM uuuu"));
        return nom + ", " + dateFormatee;
    }

    /**
     * @return l'auteur converti en objet JSON
     */
    public JSONObject toJSON() {
        JSONObject objet = new JSONObject();
        objet.put("nom", nom);
        objet.put("annee",  dateDeNaissance.get(Calendar.YEAR));
        objet.put("mois",   dateDeNaissance.get(Calendar.MONTH));
        objet.put("jour",   dateDeNaissance.get(Calendar.DAY_OF_MONTH));
        return objet;
    }

    /**
     * Crée un auteur à partir d'un JSONObject
     * @param json
     */
    public static Auteur fromJSON(JSONObject json) {
        return new Auteur(
            json.getString("nom"),
            new GregorianCalendar(json.getInt("annee"), json.getInt("mois"), json.getInt("jour"))
        );
    }
}

