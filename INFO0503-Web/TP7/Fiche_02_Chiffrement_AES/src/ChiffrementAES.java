
package src;

import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import java.security.NoSuchAlgorithmException;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.BadPaddingException;
import javax.crypto.IllegalBlockSizeException;
import java.security.InvalidKeyException;

/**
 * Classe permettant de tester le chiffrement et le dechiffrement avec AES.
 */
public class ChiffrementAES {
	public static final String motDePasse = "0123456789012345";
	public static final SecretKeySpec specification = new SecretKeySpec(motDePasse.getBytes(), "AES");

	public static byte[] chiffrement(String data) {
		byte[] bytes = null;
		try {
			Cipher chiffreur = Cipher.getInstance("AES");
			chiffreur.init(Cipher.ENCRYPT_MODE, specification);
			bytes = chiffreur.doFinal(data.getBytes());
		} catch (NoSuchAlgorithmException | NoSuchPaddingException | InvalidKeyException | IllegalBlockSizeException | BadPaddingException e) {
			System.err.println("Erreur lors du chiffrement : " + e);
			System.exit(0);
		}
		return bytes;
	}

	public static byte[] dechiffrement(byte[] data) {
		byte[] bytes = null;
		try {
			Cipher dechiffreur = Cipher.getInstance("AES");
			dechiffreur.init(Cipher.DECRYPT_MODE, specification);
			bytes = dechiffreur.doFinal(data);
		} catch (NoSuchAlgorithmException | NoSuchPaddingException | InvalidKeyException | IllegalBlockSizeException | BadPaddingException e) {
			System.err.println("Erreur lors du chiffrement : " + e);
			System.exit(0);
		}
		return bytes;
	}
}
