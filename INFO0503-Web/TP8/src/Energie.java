
package src;

import java.io.Serializable;
import org.json.JSONObject;

/**
 * Classe définissant l'énergie
 * 
 * @author Alexandre Collignon
 */
public class Energie implements Serializable {
	private int type;
    private float quantity;
	private String signature;

	public Energie(int type, float quantity, String signature) {
		this.type = type;
		this.quantity = quantity;
		this.signature = signature;
	}

	// Getters & Setters
	public int getType() { return type; }
	public float getQuantity() { return quantity; }
	public String getSignature() { return signature; }
	public void setType(int type) { this.type = type; }
	public void setQuantity(float quantity) { this.quantity = quantity; }
	public void setSignature(String signature) { this.signature = signature; }

	/**
     * @return l'energie convertie en objet JSON
     */
    public JSONObject toJSON() {
        JSONObject objet = new JSONObject();
        objet.put("type", type);
        objet.put("quantity", quantity);
        objet.put("signature", signature);
        return objet;
    }
	
	/**
     * Crée une énergie à partir d'un JSONObject
     * @param json
     */
    public static Energie fromJSON(JSONObject json) {
        return new Energie(
			json.getInt("type"),
			json.getFloat("quantity"),
			json.getString("signature")
		);
    }
}

