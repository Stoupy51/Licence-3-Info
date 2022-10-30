
package src;

import java.io.Serializable;
import org.json.JSONObject;

/**
 * Classe correspondant a une requete pour le ServeurGROS.
 * Cette classe peut-être utilisée en mode
 * sérialisé standard ou en mode sérialisé JSON.
 * 
 * @author Alexandre COLLIGNON
 * @version 1.0
 */
public class Requete implements Serializable {
	enum Type { REQUETE_TARE, REQUETE_PONE };
	private String nom;
	private CodeDeSuivi codeDeSuivi;
	private Type type;
	private String requete;

	public Requete(String nom, CodeDeSuivi codeDeSuivi, Type type, String requete) {
		this.nom = nom;
		this.codeDeSuivi = codeDeSuivi;
		this.type = type;
		this.requete = requete;
	}

	public Requete(String nom, String codeDeSuivi, Type type, String requete) {
		this.nom = nom;
		this.codeDeSuivi = new CodeDeSuivi(codeDeSuivi);
		this.type = type;
		this.requete = requete;
	}

	public Requete(String nom, Type type, String requete) {
		this.nom = nom;
		this.type = type;
		this.requete = requete;
	}

	/**
	 * @ Getter et setter pour tous les attributs
	 */
	public String getNom() { return nom; }
	public CodeDeSuivi getCodeDeSuivi() { return codeDeSuivi; }
	public Type getType() { return type; }
	public String getRequete() { return requete; }
	public void setNom(String nom) { this.nom = nom; }
	public void setCodeDeSuivi(CodeDeSuivi codeDeSuivi) { this.codeDeSuivi = codeDeSuivi; }
	public void setCodeDeSuivi(String codeDeSuivi) { this.codeDeSuivi = new CodeDeSuivi(codeDeSuivi); }
	public void setType(Type type) { this.type = type; }
	public void setRequete(String requete) { this.requete = requete; }

	/**
	 * Transforme la requête en String
	 * @return une chaine de caractères contenant la requête
	 */
	@Override
	public String toString() {
		return nom + " propose " + requete;
	}

	/**
	 * Transformation en JSONObject (pour obtenir ensuite un String JSON)
	 * avec les getters actuel on pourrait se passer de cette méthode.
	 * 
	 * @return un JSONOBject décrivant la requête en cours
	 */
	public JSONObject toJSON() {
		JSONObject json = new JSONObject();

		json.put("nom", nom);
		json.put("codeDeSuivi", codeDeSuivi.toJSON());
		json.put("type", type);
		json.put("requete", requete);

		return json;
	}

	/**
	 * Récupération d'un objet requête depuis sa version String JSON
	 * @param json La version String JSON de l'objet originel
	 * @return une instance de requête
	 */
	public static Requete fromJSON(String json) {
		return fromJSON(new JSONObject(json));
	}

	/**
	 * Récupération d'un objet requête depuis sa version JSONObject
	 * @param jsonObject La version JSONObject de l'objet originel
	 * @return une instance de requête
	 */
	public static Requete fromJSON(JSONObject jsonObject) {
		return new Requete(
			jsonObject.getString("nom"),
			CodeDeSuivi.fromJSON(jsonObject.getJSONObject("codeDeSuivi")),
			Type.valueOf(jsonObject.getString("type")),
			jsonObject.getString("requete")
		);
	}
}

