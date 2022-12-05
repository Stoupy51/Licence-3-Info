
package src;

import java.security.PublicKey;
import java.security.PrivateKey;
import java.security.NoSuchAlgorithmException;
import java.security.InvalidKeyException;

import javax.crypto.NoSuchPaddingException;
import javax.crypto.BadPaddingException;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.Cipher;

public class ChiffrementRSA {
	public static final String privateKeyFile = "privateKey.bin";
	public static final String publicKeyFile = "publicKey.bin";

	public static byte[] chiffrement(byte[] data) {
		// Recuperation de la cle publique
		PublicKey clePublique = GestionClesRSA.lectureClePublique(publicKeyFile);

		System.err.println("\n\nChiffrementRSA.chiffrement() : " + new String(data) + "\n\n");

		// Chiffrement du message
		byte[] bytes = null;
		try {
			Cipher chiffreur = Cipher.getInstance("RSA");
			chiffreur.init(Cipher.ENCRYPT_MODE, clePublique);
			bytes = chiffreur.doFinal(data);
		} catch (	NoSuchAlgorithmException | NoSuchPaddingException | InvalidKeyException |
					IllegalBlockSizeException | BadPaddingException e) {
			System.err.println("Erreur lors du chiffrement : " + e);
			System.exit(0);
		}
		return bytes;
	}

	public static byte[] dechiffrement(byte[] data) {
		// Récupération de la clé privée
		PrivateKey clePrivee = GestionClesRSA.lectureClePrivee(privateKeyFile);

		// Déchiffrement du message
		byte[] bytes = null;
		try {
			Cipher dechiffreur = Cipher.getInstance("RSA");
			dechiffreur.init(Cipher.DECRYPT_MODE, clePrivee);
			bytes = dechiffreur.doFinal(data);
		} catch (	NoSuchAlgorithmException | NoSuchPaddingException | InvalidKeyException |
					IllegalBlockSizeException | BadPaddingException e) {
			System.err.println("Erreur lors du déchiffrement : " + e);
			System.exit(0);
		}
		return bytes;
	}
}
