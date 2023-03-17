
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/**
 * CameraController class : Allow to switch between cameras
 *
 * @brief Switch camera when pressing 'C'
 *
 * @author COLLIGNON Alexandre
 */
public class CameraController : MonoBehaviour {

	// Variables
	public Camera[] cameras;				// Array of cameras to switch between (Defined in the Unity Editor in the Inspector of the CameraController object)
											// Cameras are Camera objects placed in the scene (can be anywhere in the hierarchy)
	private int currentCameraIndex = 0;		// Current camera index

	/**
	 * Start method, called at the beginning of the game
	 *
	 * @brief Initialize the private variables
	 */
	void Start() {
		
		// Turn all cameras off, except the first default one
		this.currentCameraIndex = 0;
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

