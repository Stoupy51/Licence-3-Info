
package src;

import java.io.Serializable;
import org.json.JSONObject;

/**
 * Classe correspondant a une requete entre l'AMI et le Marché de Gros.
 * Cette classe peut-être utilisée en mode
 * sérialisé standard ou en mode sérialisé JSON.
 */
public class RequeteAMIGros implements Serializable {
	private String nom;
	private String requete;

	public RequeteAMIGros(String nom, String requete) {
		this.nom = nom;
		this.requete = requete;
	}

	// Getter et setter pour tous les attributs
	public String getNom() { return nom; }
	public String getRequete() { return requete; }
	public void setNom(String nom) { this.nom = nom; }
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
	 * @return un JSONOBject décrivant la requête en cours
	 */
	public JSONObject toJSON() {
		JSONObject json = new JSONObject();
		json.put("nom", nom);
		json.put("requete", requete);
		return json;
	}

	/**
	 * Récupération d'un objet requête depuis sa version String JSON
	 * @param json La version String JSON de l'objet originel
	 * @return une instance de requête
	 */
	public static RequeteAMIGros fromJSON(String json) {
		return fromJSON(new JSONObject(json));
	}

	/**
	 * Récupération d'un objet requête depuis sa version JSONObject
	 * @param jsonObject La version JSONObject de l'objet originel
	 * @return une instance de requête
	 */
	public static RequeteAMIGros fromJSON(JSONObject jsonObject) {
		return new RequeteAMIGros(
				jsonObject.getString("nom"),
				jsonObject.getString("requete"));
	}
}
