
package src.pone;

import java.io.Serializable;
import org.json.JSONObject;

/**
 * Classe correspondant a une requete destinée au marché de gros.
 * Cette classe peut-être utilisée en mode
 * sérialisé standard ou en mode sérialisé JSON.
 */
public class RequetePONEToGROS implements Serializable {
	private int type;
	private String nom;
	private String requete;

	public RequetePONEToGROS(int type, String nom, String requete) {
		this.type = type;
		this.nom = nom;
		this.requete = requete;
	}

	// Getter et setter pour tous les attributs
	public int getType() { return type; }
	public String getNom() { return nom; }
	public String getRequete() { return requete; }
	public void getType(int type) { this.type = type; }
	public void setNom(String nom) { this.nom = nom; }
	public void setRequete(String requete) { this.requete = requete; }

	@Override
	public String toString() {
		return nom + " propose un type " + type + " : " + requete;
	}

	// Récupération JSONObject décrivant la requête en cours
	public JSONObject toJSON() {
		JSONObject json = new JSONObject();
		json.put("type", type);
		json.put("nom", nom);
		json.put("requete", requete);
		return json;
	}

	// Récupération d'un objet requête depuis sa version String JSON
	public static RequetePONEToGROS fromJSON(String json) {
		return fromJSON(new JSONObject(json));
	}

	// Récupération d'un objet requête depuis sa version JSONObject
	public static RequetePONEToGROS fromJSON(JSONObject jsonObject) {
		return new RequetePONEToGROS(
			jsonObject.getInt("type"),
			jsonObject.getString("nom"),
			jsonObject.getString("requete")
		);
	}
}
