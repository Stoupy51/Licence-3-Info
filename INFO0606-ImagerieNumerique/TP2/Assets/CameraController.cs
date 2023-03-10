
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraController : MonoBehaviour {

	// Variables
	public Camera[] cameras;				// Array of cameras
	private int currentCameraIndex = 0;		// Current camera index

	/**
	 * Start method, called at the beginning of the game
	 *
	 * @brief Initialize the private variables
	 */
	void Start() {
		this.currentCameraIndex = 0;
		
		// Turn all cameras off, except the first default one
		for (int i = 1; i < cameras.Length; i++)
			cameras[i].gameObject.SetActive(false);
	}

	/**
	 * Update method, called once per frame
	 *
	 * @brief Switch camera when pressing 'C'
	 */
	void Update() {
		if (Input.GetKeyDown(KeyCode.C)) {

			// Turn off the current camera and turn on the next one
			cameras[currentCameraIndex].gameObject.SetActive(false);
			currentCameraIndex = (currentCameraIndex + 1) % cameras.Length;
			cameras[currentCameraIndex].gameObject.SetActive(true);

			Debug.Log("Camera: " + cameras[currentCameraIndex].name);
			Debug.Log("Camera Index: " + currentCameraIndex);
		}
	}
}

