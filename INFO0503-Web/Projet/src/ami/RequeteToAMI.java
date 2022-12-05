
package src.ami;

import java.io.Serializable;
import org.json.JSONObject;

/**
 * TODOO : à évoluer pour être capable de répondre aux requêtes :
 * - création et signature de CRADO
 * - création et signature de CRACHA
 * - vérification de la signature de CRADO
 * - vérification de la signature de CRACHA
*/

/**
 * Classe correspondant a une requete destinée à l'AMI.
 * Cette classe peut-être utilisée en mode
 * sérialisé standard ou en mode sérialisé JSON.
 */
public class RequeteToAMI implements Serializable {
	private int type;
	private String nom;
	private String requete;

	public RequeteToAMI(int type, String nom, String requete) {
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
	public static RequeteToAMI fromJSON(String json) {
		return fromJSON(new JSONObject(json));
	}

	// Récupération d'un objet requête depuis sa version JSONObject
	public static RequeteToAMI fromJSON(JSONObject jsonObject) {
		return new RequeteToAMI(
			jsonObject.getInt("type"),
			jsonObject.getString("nom"),
			jsonObject.getString("requete")
		);
	}
}
