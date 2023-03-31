
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/**
 * MaFonctionOnSpectrum class
 *
 * @brief Manage onSpectrum event to change the scale of an object and color according to the spectrum
 *
 * @author COLLIGNON Alexandre
 */
public class MaFonctionOnSpectrum : MonoBehaviour {

	// Public variables
	public GameObject sphere; // The sphere to scale

	/**
	 * Called by the AudioProcessor when a spectrum is detected
	 *
	 * @brief Change the scale of an object and color according to the spectrum
	 */
	public void onSpectrum(float[] spectrum) {

		// Calculate the average of the spectrum
		float spectrumMoyen = 0.0f;
		foreach (float val in spectrum)
			spectrumMoyen += val;
		spectrumMoyen /= spectrum.Length;

		// Search the index of the most present frequency
		int indexMax = 0;
		for (int i = 1; i < spectrum.Length; i++)
			if (spectrum[i] > spectrum[indexMax])
				indexMax = i;

		// Change the color of the sphere according to the most present frequency
		Renderer renderer = sphere.GetComponent<Renderer>();
		float red = 1 - ((float)indexMax / (float)spectrum.Length) * spectrumMoyen * 100.0f;
		float green = ((float)indexMax / (float)spectrum.Length) * spectrumMoyen * 100.0f;
		float blue = 1.0f;
		renderer.material.color = new Color(red, green, blue);

		// Change the scale of the sphere
		spectrumMoyen *= 20.0f;
		sphere.transform.localScale = new Vector3(spectrumMoyen, spectrumMoyen, spectrumMoyen);
	}
}

