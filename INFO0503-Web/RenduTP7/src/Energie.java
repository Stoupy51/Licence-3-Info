
package src;

import java.io.Serializable;
import org.json.JSONObject;

/**
 * Classe définissant l'énergie
 * 
 * @author Alexandre Collignon
 */
public class Energie implements Serializable {
	private CodeDeSuivi codeDeSuivi;

	public Energie(CodeDeSuivi codeDeSuivi) {
		this.codeDeSuivi = codeDeSuivi;
	}

	// Getters & Setters
	public CodeDeSuivi getCodeDeSuivi() { return codeDeSuivi; }
	public void setCodeDeSuivi(CodeDeSuivi codeDeSuivi) { this.codeDeSuivi = codeDeSuivi; }

    @Override
	public String toString() {
		return codeDeSuivi.toString();
	}

	/**
     * @return l'energie convertie en objet JSON
     */
    public JSONObject toJSON() {
        JSONObject objet = new JSONObject();
        objet.put("codeDeSuivi", codeDeSuivi.toJSON());
        return objet;
    }
	
	/**
     * @return une instance de Energie à partir d'un JSONObject
	 */
    public static Energie fromJSON(JSONObject json) {
        return new Energie(
			CodeDeSuivi.fromJSON(json.getJSONObject("codeDeSuivi"))
		);
    }
}

