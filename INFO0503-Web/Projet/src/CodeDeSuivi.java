
package src;

import java.io.Serializable;

import org.json.JSONObject;

public class CodeDeSuivi implements Comparable<CodeDeSuivi>, Serializable {

	private String code;

	private int energyType;
	private float quantity;
	private float minQuantity;
	private int extractMode;
	private String extractModeStrict;
	private String energyFromCountry;
	private float maxPrice;
	private float maxBudget;
	private int date;

	/**
	 * Crée un Code de suivi en utilisant le code fourni en paramètre
	 * 
	 * @param code le code
	 */
	public CodeDeSuivi(String code) {
		this.code = code;
		try {
			String[] parts = code.split("-");
			this.energyType = Integer.parseInt(parts[0]);
			this.quantity = Float.parseFloat(parts[1]);
			this.minQuantity = Float.parseFloat(parts[2]);
			this.extractMode = Integer.parseInt(parts[3]);
			this.extractModeStrict = parts[4];
			this.energyFromCountry = parts[5];
			this.maxPrice = Float.parseFloat(parts[6]);
			this.maxBudget = Float.parseFloat(parts[7]);
			this.date = Integer.parseInt(parts[8]);
		} catch (Exception e) {
			System.out.println("\nErreur lors de la création du code de suivi 'CODE INVALIDE' : " + code);
		}
	}

	/**
	 * @return le code
	 */
	public String getCode() {
		return code;
	}

	/**
	 * @return Getter pour tous les attributs
	 */
	public int getEnergyType() {
		return energyType;
	}

	public float getQuantity() {
		return quantity;
	}

	public float getMinQuantity() {
		return minQuantity;
	}

	public int getExtractMode() {
		return extractMode;
	}

	public String getExtractModeStrict() {
		return extractModeStrict;
	}

	public String getEnergyFromCountry() {
		return energyFromCountry;
	}

	public float getMaxPrice() {
		return maxPrice;
	}

	public float getMaxBudget() {
		return maxBudget;
	}

	public int getDate() {
		return date;
	}

	/**
	 * @return une chaine de caractères au format "code-code-...-code"
	 */
	@Override
	public String toString() {
		return "CodeDeSuivi{"
				+ "code=" + code + ", "
				+ "energyType=" + energyType + ", "
				+ "quantity=" + quantity + ", "
				+ "minQuantity=" + minQuantity + ", "
				+ "extractMode=" + extractMode + ", "
				+ "extractModeStrict=" + extractModeStrict + ", "
				+ "energyFromCountry=" + energyFromCountry + ", "
				+ "maxPrice=" + maxPrice + ", "
				+ "maxBudget=" + maxBudget + ", "
				+ "date=" + date
				+ '}';
	}

	/**
	 * @return le code converti en objet JSON
	 */
	public JSONObject toJSON() {
		JSONObject objet = new JSONObject();
		objet.put("code", code);
		objet.put("energyType", energyType);
		objet.put("quantity", quantity);
		objet.put("minQuantity", minQuantity);
		objet.put("extractMode", extractMode);
		objet.put("extractModeStrict", extractModeStrict);
		objet.put("energyFromCountry", energyFromCountry);
		objet.put("maxPrice", maxPrice);
		objet.put("maxBudget", maxBudget);
		objet.put("date", date);
		return objet;
	}

	/**
	 * Crée un auteur à partir d'un JSONObject
	 * 
	 * @param json
	 */
	public static CodeDeSuivi fromJSON(JSONObject json) {
		String code = Integer.toString(json.getInt("energyType"));
		code += "-" + Float.toString(json.getFloat("quantity"));
		code += "-" + Float.toString(json.getFloat("minQuantity"));
		code += "-" + Integer.toString(json.getInt("extractMode"));
		code += "-" + json.get("extractModeStrict");
		code += "-" + json.getString("energyFromCountry");
		code += "-" + Float.toString(json.getFloat("maxPrice"));
		code += "-" + Float.toString(json.getFloat("maxBudget"));
		code += "-" + Integer.toString(json.getInt("date"));
		return new CodeDeSuivi(code);
	}

	/**
	 * @return 1 si la quantité du premier code est supérieure à celle du second
	 * @return -1 si la quantité du premier code est inférieure à celle du second
	 * @return 0 si les deux codes ont la même quantité
	 */
	@Override
	public int compareTo(CodeDeSuivi code) {
		if (this.quantity > code.quantity) {
			return 1;
		}
		if (this.quantity < code.quantity) {
			return -1;
		}
		return 0;
	}
}

