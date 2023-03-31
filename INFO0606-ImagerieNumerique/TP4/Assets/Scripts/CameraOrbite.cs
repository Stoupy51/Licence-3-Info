
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/**
 * CameraOrbite class
 *
 * @brief Camera orbiting around a target when the player presses the arrow keys
 *
 * @author COLLIGNON Alexandre
 */
public class CameraOrbite : MonoBehaviour {

	// Public variables
	public GameObject cible;
	public float anglesParSeconde = 45.0f;

	/**
	 * Start method, called at the beginning of the game
	 *
	 * @brief Initialize the private variables
	 */
	void Start() {
		this.transform.transform.position = new Vector3(2, 0, 0);
		this.transform.transform.rotation = Quaternion.Euler(0, -90.0f, 0);
	}

	/**
	 * Update method, called once per frame
	 *
	 * @brief Manage the player inputs
	 */
	void Update() {

		// Left arrow key
		if (Input.GetKey(KeyCode.LeftArrow))
			this.transform.RotateAround(cible.transform.position, Vector3.up, -anglesParSeconde * Time.deltaTime);

		// Right arrow key
		if (Input.GetKey(KeyCode.RightArrow))
			this.transform.RotateAround(cible.transform.position, Vector3.up, anglesParSeconde * Time.deltaTime);

		// Up arrow key
		if (Input.GetKey(KeyCode.UpArrow))
			this.transform.RotateAround(cible.transform.position, Camera.main.transform.right, anglesParSeconde * Time.deltaTime);

		// Down arrow key
		if (Input.GetKey(KeyCode.DownArrow))
			this.transform.RotateAround(cible.transform.position, Camera.main.transform.right, -anglesParSeconde * Time.deltaTime);
	}
}

