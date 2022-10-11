package prog_web;

import org.json.JSONObject;

public class CodeDeSuivi {
    private String code;
   
    /**
     * Crée un Code de suivi avec un code
     * @param code le code
     * @param dateDeNaissance la date de naissance
     */
    public CodeDeSuivi(String code) {
        this.code = code;
    }
    
    /**
     * @return le code
     */
    public String getCode() {
        return code;
    }
    
    /**
     * @return une chaine de caractères au format "code;code;code"
     */
    @Override
    public String toString() {
        return code;
    }

    /**
     * @return l'auteur converti en objet JSON
     */
    public JSONObject toJSON() {
        JSONObject objet = new JSONObject();
        objet.put("code", code);
        return objet;
    }

    /**
     * Crée un auteur à partir d'un JSONObject
     * @param json
     */
    public static CodeDeSuivi fromJSON(JSONObject json) {
        return new CodeDeSuivi(
            json.getString("code")
        );
    }
}

