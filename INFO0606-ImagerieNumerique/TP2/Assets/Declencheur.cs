
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/**
 * Declencheur class
 *
 * @brief Print "Declenché" when something enters the trigger of the object
 *
 * @author COLLIGNON Alexandre
 */
public class Declencheur : MonoBehaviour {

	// Private variables
	private int count = 0;	// Count of destroyed objects

	/**
	 * OnTriggerEnter method, called by Unity when something enters the trigger
	 *
	 * @brief Print "Declenché" in the console and destroy the object
	 *
	 * @param other The Collider data associated.
	 */
	private void OnTriggerEnter(Collider other) {

		// Debug console
		Debug.Log("Declenché");

		// Destroy the collider base object if it has destroy tag
		if (other.gameObject.tag == "destroy") {
			Debug.Log("Destroy");
			Destroy(other.gameObject);

			// Increment the count of destroyed objects and print it
			count++;
			Debug.Log("Count: " + count);
		}
	}
}

