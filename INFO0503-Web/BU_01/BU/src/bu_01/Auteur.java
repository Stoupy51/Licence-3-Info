package bu_01;

import java.util.GregorianCalendar;
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
    public GregorianCalendar dateDeNaissance() {
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

}
