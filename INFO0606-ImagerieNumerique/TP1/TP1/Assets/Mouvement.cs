
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

// I miss macros and C/C++ comments in C# 😭😭😭

/**
 * Mouvement class : manage the movement of the player
 *
 * @brief The player can move forward, backward, rotate left and right, jump and sprint
 *
 * @author COLLIGNON Alexandre
 */
public class Mouvement : MonoBehaviour {

	// Private variables
	private Rigidbody r_body;	// The rigidbody of the player
	private bool isGrounded;	// True if the player is grounded, false otherwise
	private float baseSpeed;	// The base speed of the player (not a constant for future uses)
	private float maxSpeed;		// The max speed of the player	(not a constant for future uses)
	private float actualSpeed;	// The actual speed of the player (can be modified by sprinting)

	// Constants
	private const float AIR_CONTROL = 0.2f;				// Manage the air control of the player when he is in the air
	private const float JUMP_FORCE = 7.5f;				// Manage the velocity applied to the player when he jumps
	private const float SPRINT_ACCELERATION = 1.0f;		// Manage the acceleration of the player when he is sprinting

	/**
	 * Start method, called at the beginning of the game
	 *
	 * @brief Initialize the private variables
	 */
	void Start() {
		this.r_body = GetComponent<Rigidbody>();
		this.isGrounded = true;
		this.baseSpeed = 10.0f;
		this.maxSpeed = 30.0f;
		this.actualSpeed = this.baseSpeed;
	}

	/**
	 * Update method, called once per frame
	 *
	 * @brief Manage the inputs for the player :
	 * - UpArrow					move forward
	 * - DownArrow					move backward
	 * - LeftArrow					rotate left (shift to rotate faster)
	 * - RightArrow					rotate right (shift to rotate faster)
	 * - Space						jump
	 * - LeftShift	+ UpArrow		sprint
	 * - RightShift + UpArrow		sprint
	 */
	void Update() {

		// Sprint System
		sprintingSystem();

		// Going Forward or Backward System
		forwardBackwardSystem();

		// Rotation System (Faster if the player is shifting)
		rotationSystem();
		
		// Jump System
		jumpingSystem();
	}

	/**
	 * OnCollisionEnter method, called by Unity when the player collides with something (ground, wall, ...)
	 *
	 * @brief If the player is not grounded, check if he is grounded by calculating the angle between the player and the collision
	 *
	 * @param collision The Collision data associated with this collision.
	 */
	void OnCollisionEnter(Collision collision) {
		if (!this.isGrounded) {

			// Calculate product between the normal and the up vector to get the angle between the player and the collision
			float dot = Vector3.Dot(collision.contacts[0].normal, Vector3.up);
			dot = Mathf.Abs(dot);

			// If the angle is less than 60° (cos(60°) = 0.5), the player is grounded allowing him to jump again
			if (dot > 0.5f)
				this.isGrounded = true;
		}
	}



	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////// Private Methods Below ///////////////////////////
	/////////////////////////////////////////////////////////////////////////////



	/**
	 * Manage the forward and backward system
	 *
	 * @brief The player can go forward and backward normally if he is grounded
	 * @brief Else, the air control make the player go slower in the air
	 */
	private void forwardBackwardSystem() {
		if (this.isGrounded) {
			if (Input.GetKey(KeyCode.UpArrow))
				this.transform.Translate(Vector3.forward * -this.actualSpeed * Time.deltaTime);
			if (Input.GetKey(KeyCode.DownArrow))
				this.transform.Translate(Vector3.forward * this.actualSpeed * Time.deltaTime);
		}
		else {
			if (Input.GetKey(KeyCode.UpArrow))
				this.transform.Translate(Vector3.forward * -this.actualSpeed * Mouvement.AIR_CONTROL * Time.deltaTime);
			if (Input.GetKey(KeyCode.DownArrow))
				this.transform.Translate(Vector3.forward * this.actualSpeed * Mouvement.AIR_CONTROL * Time.deltaTime);
		}
	}

	/**
	 * Manage the rotation system
	 *
	 * @brief The player can rotate left and right
	 * @brief If the player is pressing shift, the rotation is faster
	 * @brief Remove the rotation velocity just in case
	 */
	private void rotationSystem() {

		// Fast rotation if the player is pressing shift
		if (Input.GetKey(KeyCode.LeftShift) || Input.GetKey(KeyCode.RightShift)) {
			if (Input.GetKey(KeyCode.LeftArrow))
				this.transform.Rotate(Vector3.up, Time.deltaTime * -300);
			if (Input.GetKey(KeyCode.RightArrow))
				this.transform.Rotate(Vector3.up, Time.deltaTime * 300);
		}
		// Normal rotation
		else {
			if (Input.GetKey(KeyCode.LeftArrow))
				this.transform.Rotate(Vector3.up, Time.deltaTime * -100);
			if (Input.GetKey(KeyCode.RightArrow))
				this.transform.Rotate(Vector3.up, Time.deltaTime * 100);
		}

		// Remove rotation velocity just in case (Experienced some weird behavior without this)
		this.r_body.angularVelocity = Vector3.zero;
	}

	/**
	 * Manage the sprinting system
	 *
	 * @brief The player can sprint by pressing the UpArrow key and the LeftShift or RightShift key
	 * @brief The sprinting speed is progressively increased until the max speed is reached
	 */
	private void sprintingSystem() {

		// If the player is sprinting
		if (Input.GetKey(KeyCode.UpArrow) && (Input.GetKey(KeyCode.LeftShift) || Input.GetKey(KeyCode.RightShift))) {

			// If the player is not already at max speed
			if (this.actualSpeed < this.maxSpeed) {
				this.actualSpeed += Time.deltaTime * this.maxSpeed * Mouvement.SPRINT_ACCELERATION;

				// If the player is going too fast (max speed)
				if (this.actualSpeed > this.maxSpeed)
					this.actualSpeed = this.maxSpeed;
			}
		}

		// If the player is not sprinting
		else {

			// If the player is not already at base speed
			if (this.actualSpeed > this.baseSpeed) {
				this.actualSpeed -= Time.deltaTime * this.maxSpeed * Mouvement.SPRINT_ACCELERATION;

				// If the player is going too slow (base speed)
				if (this.actualSpeed < this.baseSpeed)
					this.actualSpeed = this.baseSpeed;
			}
		}
	}

	/**
	 * Manage the jumping system
	 *
	 * @brief Verify if the player is really grounded to avoid jumping while falling
	 * @brief If the player is going forward, apply another velocity to maintain the movement during the jump
	 */
	private void jumpingSystem() {
		if (this.isGrounded && Input.GetKey(KeyCode.Space)) {

			// Check if the player is really grounded by raycasting below him
			// If the player is grounded, apply a velocity to the player to make him jump
			if (Physics.Raycast(this.transform.position, Vector3.down, 1.1f)) {
				this.r_body.velocity += new Vector3(0, Mouvement.JUMP_FORCE, 0);

				// Except, If the player is going forward and jump, apply another velocity to the player to maintain the speed during the jump
				if (Input.GetKey(KeyCode.UpArrow))
					this.r_body.velocity += transform.forward * -this.actualSpeed * Mouvement.JUMP_FORCE * 0.05f;
			}

			// The player is not grounded anymore in both case (jump or not)
			this.isGrounded = false;
		}
	}
}

