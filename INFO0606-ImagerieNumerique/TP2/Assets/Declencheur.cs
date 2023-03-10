
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/**
 * Grappin class : TODO
 *
 * @brief TODO
 *
 * @author COLLIGNON Alexandre
 */
public class Declencheur : MonoBehaviour {

	/**
	 * OnTriggerEnter method, called by Unity when something enters the trigger
	 *
	 * @brief TODO
	 *
	 * @param other The Collider data associated.
	 */
	private void OnTriggerEnter(Collider other) {
		Debug.Log("Declenché");
	}
}

