
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/**
 * Mouvement class : manage the player input to move the object
 *
 * @brief The object can move forward, backward, rotate left and right
 *
 * @author COLLIGNON Alexandre
 */
public class Mouvement : MonoBehaviour {

	// Public variables
	public GameObject lest;		// Configured in the Unity Editor to know when the paws are deployed

	// Private variables
	private Rigidbody r_body;			// The rigidbody of the object
	private float actualSpeed;			// The actual speed of the object
	private LestCommand lestCommand;	// The LestCommand script of the Lest

	/**
	 * Start method, called at the beginning of the game
	 *
	 * @brief Initialize the private variables
	 */
	void Start() {
		this.r_body = GetComponent<Rigidbody>();
		this.actualSpeed = 1.0f;
		this.lestCommand = this.lest.GetComponent<LestCommand>();
	}

	/**
	 * Update method, called once per frame
	 *
	 * @brief Manage the inputs for the object :
	 * - UpArrow					move forward
	 * - DownArrow					move backward
	 * - LeftArrow					rotate left
	 * - RightArrow					rotate right
	 */
	void Update() {
		// If the paws are deployed, the object can't move
		if (!this.lestCommand.moving && this.lestCommand.deployedState == 0) {

			// Going Forward or Backward System
			forwardBackwardSystem();

			// Rotating system
			rotationSystem();
		}
	}



	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////// Private Methods Below ///////////////////////////
	/////////////////////////////////////////////////////////////////////////////



	/**
	 * @brief Manage the forward and backward system
	 */
	private void forwardBackwardSystem() {
		if (Input.GetKey(KeyCode.UpArrow))
			this.transform.Translate(Vector3.forward * -this.actualSpeed * Time.deltaTime);
		if (Input.GetKey(KeyCode.DownArrow))
			this.transform.Translate(Vector3.forward * this.actualSpeed * Time.deltaTime);
	}

	/**
	 * Manage the rotation system
	 *
	 * @brief The object can rotate left and right
	 */
	private void rotationSystem() {
		if (Input.GetKey(KeyCode.LeftArrow))
			this.transform.Rotate(Vector3.up, Time.deltaTime * -50);
		if (Input.GetKey(KeyCode.RightArrow))
			this.transform.Rotate(Vector3.up, Time.deltaTime * 50);

		// Remove rotation velocity just in case (Experienced some weird behavior without this)
		//this.r_body.angularVelocity = Vector3.zero;
	}
}

