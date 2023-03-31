
using UnityEngine;

//[RequireComponent(typeof(AudioSource))]
public class AudioVisu : MonoBehaviour {

	// Public variables
	public float[] spectrumH = new float[128];

	/**
	 * Update method, called once per frame
	 *
	 * @brief Get the current spectrum data
	 */
	void Update() {
		AudioListener.GetSpectrumData(spectrumH, 0, FFTWindow.BlackmanHarris);
	}
}

