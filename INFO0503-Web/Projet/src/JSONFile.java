
package src;

import org.json.JSONObject;

/**
 * Classe permettant de créer/gérer un fichier JSON.
 */
public class JSONFile {
	private final String nomFichier;
	private JSONObject jsonObject;

	/**
	 * Ouverture d'un fichier.
	 * 
	 * @param nomFichier le nom du fichier
	 */
	public JSONFile(String nomFichier) {
		this.nomFichier = nomFichier;
		charger();
	}

	/**
	 * Ouverture/création d'un fichier.
	 * 
	 * @param nomFichier Le nom du fichier.
	 * @param creation   Si true, crée un nouveau fichier vide.
	 */
	public JSONFile(String nomFichier, boolean creation) {
		if (!creation) {
			this.nomFichier = nomFichier;
			charger();
		} else {
			this.nomFichier = nomFichier;
			jsonObject = new JSONObject();
		}
	}

	/**
	 * Indique si un fichier existe.
	 * 
	 * @param nomFichier le nom du fichier
	 * @return 'true' s'il existe
	 */
	public static boolean fichierExiste(String nomFichier) {
		return new java.io.File(nomFichier).exists();
	}

	/**
	 * Getter et Setter du JSON Object
	 */
	public JSONObject getJSON() { return jsonObject; }
	public void setJSON(JSONObject json) { jsonObject = json; }

	/**
	 * Charge un fichier en mémoire.
	 */
	private void charger() {
		String json = null;
		try {
			json = new String(java.nio.file.Files.readAllBytes(new java.io.File(nomFichier).toPath()));
			jsonObject = new JSONObject(json);
		} catch (java.io.IOException ioe) {
			System.err.println("An I/O error occurs reading from the stream");
			System.err.println(ioe);
			System.exit(110);
		} catch (OutOfMemoryError ome) {
			System.err.println(
					"An array of the required size cannot be allocated, for example the file is larger that 2GB");
			System.err.println(ome);
			System.exit(120);
		} catch (SecurityException se) {
			System.err.println(
					"In the case of the default provider, and a security manager is installed, the checkRead method is invoked to check read access to the file.");
			System.err.println(se);
			System.exit(130);
		}
	}

	/**
	 * Sauvegardu fichier actuelle dans le fichier indiqué par
	 * <em>nomFichier</em>.
	 */
	public void sauvegarder() {
		try {
			java.nio.file.Files.write(new java.io.File(nomFichier).toPath(), jsonObject.toString(2).getBytes());
		} catch (IllegalArgumentException iae) {
			System.err.println("Options contains an invalid combination of options...");
			System.err.println(iae);
			System.exit(10);
		} catch (java.io.IOException ioe) {
			System.err.println("An I/O error occurs writing to or creating the file");
			System.err.println(ioe);
			System.exit(20);
		} catch (UnsupportedOperationException uoe) {
			System.err.println("An unsupported option is specified");
			System.err.println(uoe);
			System.exit(30);
		} catch (SecurityException se) {
			System.err.println(
					"In the case of the default provider, and a security manager is installed, the checkWrite method is invoked to check write access to the file. The checkDelete method is invoked to check delete access if the file is opened with the DELETE_ON_CLOSE option.An unsupported option is specified");
			System.err.println(se);
			System.exit(40);
		}
	}
}
