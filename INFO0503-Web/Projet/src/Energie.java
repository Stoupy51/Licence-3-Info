
package src;

import java.io.Serializable;
import org.json.JSONObject;

/**
 * Classe définissant l'énergie
 * 
 * @author Alexandre Collignon
 */
public class Energie implements Serializable, Comparable<Energie> {
	private CodeDeSuivi codeDeSuivi;
	private String signature;

	/** 
	 * Création de l'énergie à partir d'un CodeDeSuivi
	 */
	public Energie(CodeDeSuivi codeDeSuivi, String signature) {
		this.codeDeSuivi = codeDeSuivi;
		this.signature = signature;
	}

	// Getters & Setters
	public CodeDeSuivi getCodeDeSuivi() { return codeDeSuivi; }
	public String getSignature() { return signature; }
	public void setCodeDeSuivi(CodeDeSuivi codeDeSuivi) { this.codeDeSuivi = codeDeSuivi; }
	public void setSignature(String signature) { this.signature = signature; }

	/**
     * @return l'energie convertie en objet JSON
     */
    public JSONObject toJSON() {
        JSONObject objet = new JSONObject();
		objet.put("codeDeSuivi", codeDeSuivi.toJSON());
        objet.put("signature", signature);
        return objet;
    }
	
	/**
     * Crée une énergie à partir d'un JSONObject
     * @param json
     */
    public static Energie fromJSON(JSONObject json) {
        return new Energie(
			CodeDeSuivi.fromJSON(json.getJSONObject("codeDeSuivi")),
			json.getString("signature")
		);
    }

	/**
	 * Compare l'énergie avec une autre énergie.
	 * - EnergyType
	 * - EnergyFromCountry
	 * - Quantity
	 * - MaxPrice
	 * - MaxBudget
	 * 
	 * @param commande
	 * @return 1 si l'énergie respectre la commande
	 */
	@Override
	public int compareTo(Energie commande) {
		CodeDeSuivi cds = commande.getCodeDeSuivi();
		if (
			codeDeSuivi.getEnergyType() == cds.getEnergyType() &&
			codeDeSuivi.getEnergyFromCountry().equals(cds.getEnergyFromCountry()) &&

			codeDeSuivi.getQuantity() > cds.getMinQuantity() &&
			codeDeSuivi.getMaxPrice() <= cds.getMaxPrice() &&
			codeDeSuivi.getQuantity() * codeDeSuivi.getMaxPrice() <= cds.getMaxBudget()
		) {
			if (cds.getExtractModeStrict().equals("N")) {
				return 1;
			}
			if (cds.getExtractModeStrict().equals("Y") && codeDeSuivi.getExtractMode() == cds.getExtractMode()) {
				return 1;
			}
		}
		return 0;
	}
}

