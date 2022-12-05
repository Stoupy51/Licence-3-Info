
package src;

import java.security.Signature;
import java.security.SignatureException;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.io.FileInputStream;
import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.FileOutputStream;


/**
 * Classe permettant de :
 * - Créer une signature dans un fichier à partir de la clé privée.
 * - Vérifier la signature d'un fichier à partir de la clé publique.
 * 
 * @author Alexandre Collignon
 */
public class SignatureUtils {

	/**
	 * @param privateKeyFile nom du fichier contenant la clé privée
	 * @param fileToCheck nom du fichier à signer
	 * @param signatureFile nom du fichier dans lequel sauvegarder la signature
	 */
	public static boolean newSignature(String privateKeyFile, String fileToCheck, String signatureFile) {
		// Reconstruction de la clé
		PrivateKey clePrivee = GestionClesRSA.lectureClePrivee(privateKeyFile);

		// Création de la signature
		Signature signature = null;
		try {
			signature = Signature.getInstance("SHA256withRSA");
		} catch (NoSuchAlgorithmException e) {
			System.err.println("Erreur lors de l'initialisation de la signature : " + e);
			return false;
		}

		// Initialisation de la signature
		try {
			signature.initSign(clePrivee);
		} catch (InvalidKeyException e) {
			System.err.println("Clé privée invalide : " + e);
			return false;
		}

		// Mise-à-jour de la signature par rapport au contenu du fichier
		try {
			BufferedInputStream fichier = new BufferedInputStream(new FileInputStream(fileToCheck));
			byte[] tampon = new byte[1024];
			int n;
			while (fichier.available() != 0) {
				n = fichier.read(tampon);
				signature.update(tampon, 0, n);
			}
			fichier.close();
		} catch (IOException e) {
			System.err.println("Erreur lors de la lecture du fichier à signer : " + e);
			return false;
		} catch (SignatureException e) {
			System.err.println("Erreur lors de la mise-à-jour de la signature : " + e);
			return false;
		}

		// Sauvegarde de la signature du fichier
		try {
			FileOutputStream fichier = new FileOutputStream(signatureFile);
			fichier.write(signature.sign());
			fichier.close();
			return true;
		} catch (SignatureException e) {
			System.err.println("Erreur lors de la récupération de la signature : " + e);
			return false;
		} catch (IOException e) {
			System.err.println("Erreur lors de la sauvegarde de la signature : " + e);
			return false;
		}
	}

	/**
	 * @param fileToCheck nom du fichier dont on veut vérifier la signature
	 * @param signatureFile nom du fichier contenant la signature
	 * @param publicKeyFile nom du fichier contenant la clé publique
	 */
	public static boolean verify(String fileToCheck, String signatureFile, String publicKeyFile) {
		// Reconstruction de la clé
		PublicKey clePublique = GestionClesRSA.lectureClePublique(publicKeyFile);

		// Lecture de la signature
		byte[] signatureFournie = null;
		try {
			FileInputStream fichier = new FileInputStream(signatureFile);
			signatureFournie = new byte[fichier.available()];
			fichier.read(signatureFournie);
			fichier.close();
		} catch (IOException e) {
			System.err.println("Erreur lors de la lecture de la signature : " + e);
			return false;
		}

		// Création de la signature
		Signature signature = null;
		try {
			signature = Signature.getInstance("SHA256withRSA");
		} catch (NoSuchAlgorithmException e) {
			System.err.println("Erreur lors de l'initialisation de la signature : " + e);
			return false;
		}

		// Initialisation de la signature
		try {
			signature.initVerify(clePublique);
		} catch (InvalidKeyException e) {
			System.err.println("Cle publique invalide : " + e);
			return false;
		}

		// Mise-à-jour de la signature par rapport au contenu du fichier
		try {
			BufferedInputStream fichier = new BufferedInputStream(new FileInputStream(fileToCheck));
			byte[] tampon = new byte[1024];
			int n;
			while (fichier.available() != 0) {
				n = fichier.read(tampon);
				signature.update(tampon, 0, n);
			}
			fichier.close();
		} catch (IOException e) {
			System.err.println("Erreur lors de la lecture du fichier à vérifier : " + e);
			return false;
		} catch (SignatureException e) {
			System.err.println("Erreur lors de la mise-à-jour de la signature : " + e);
			return false;
		}

		// Comparaison des deux signatures
		try {
			if (signature.verify(signatureFournie))
				return true;
			else
				return false;
		} catch (SignatureException e) {
			System.err.println("Erreur lors de la vérification des signatures : " + e);
			return false;
		}
	}
}
