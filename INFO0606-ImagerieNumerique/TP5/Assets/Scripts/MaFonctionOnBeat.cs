
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/**
 * MaFonctionOnBeat class
 *
 * @brief Manage onBeatDetected event to emit a particle
 *
 * @author COLLIGNON Alexandre
 */
public class MaFonctionOnBeat : MonoBehaviour {

	// Public variables
	public ParticleSystem[] particleSystems;

	/**
	 * Called by the AudioProcessor when a beat is detected
	 *
	 * @brief Make the particle system emit a particle
	 */
	public void onBeatDetected() {
		foreach (ParticleSystem particleSystem in particleSystems)
			particleSystem.Emit(1);
	}
}

