
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Mouvement : MonoBehaviour {
	private Rigidbody r_body;
	private bool isGrounded;
	private float baseSpeed;
	private float maxSpeed;
	private float actualSpeed;

	/// <summary> Start method, called at the beginning of the game </summary>
	void Start() {
		r_body = GetComponent<Rigidbody>();
		isGrounded = true;
		baseSpeed = 3.0f;
		maxSpeed = 6.0f;
		actualSpeed = baseSpeed;
	}


	/// <summary>
	/// Update method, called once per frame
	/// Manage the inputs for the player :
	/// - UpArrow					move forward
	/// - DownArrow					move backward
	/// - LeftArrow					rotate left
	/// - RightArrow				rotate right
	/// - Space						jump
	/// - LeftShift	+ UpArrow		sprint
	/// - RightShift + UpArrow		sprint
	/// </summary>
	void Update() {

		// Going Backward or Forward
		if (Input.GetKey(KeyCode.DownArrow))
			r_body.AddForce(new Vector3(0, 0, -actualSpeed * Time.deltaTime));
		if (Input.GetKey(KeyCode.UpArrow))
			r_body.AddForce(new Vector3(0, 0, actualSpeed * Time.deltaTime));

		// Sprint System
		sprintingSystem();

		// Rotation System
		if (Input.GetKey(KeyCode.LeftArrow))
			transform.Rotate(Vector3.up, Time.deltaTime * -100);
		if (Input.GetKey(KeyCode.RightArrow))
			transform.Rotate(Vector3.up, Time.deltaTime * 100);
		
		// Jump System
		if (Input.GetKey(KeyCode.Space) && isGrounded) {
			Debug.Log("Jump");
			r_body.velocity += new Vector3(0, 10, 0);
			isGrounded = false;
		}
	}


	/// <summary> Check if the player is grounded </summary>
	/// <param name="collision"> The Collision data associated with this collision. </param>
	/// <remarks> The player is grounded if the collision is below him and not on the side </remarks>
	void OnCollisionEnter(Collision collision) {

		// If the player is not grounded : check if he is grounded
		if (!isGrounded) {

			// Calculate product between the normal and the up vector to get the angle between them
			float dot = Vector3.Dot(collision.contacts[0].normal, Vector3.up);

			// If the angle is less than 60° (cos(60°) = 0.5)
			if (dot > 0.5f) {
				Debug.Log("Grounded");
				isGrounded = true;
			}
		}
	}


	/// <summary> Manage the sprinting system </summary>
	/// <remarks> The player can sprint by pressing the UpArrow key and the LeftShift or RightShift key </remarks>
	/// <remarks> The sprinting speed is progressively increased until the max speed is reached </remarks>
	void sprintingSystem() {

		// If the player is sprinting
		if (Input.GetKey(KeyCode.UpArrow) && (Input.GetKey(KeyCode.LeftShift) || Input.GetKey(KeyCode.RightShift))) {

			// If the player is not already at max speed
			if (actualSpeed < maxSpeed) {
				actualSpeed += Time.deltaTime * 2.0f;

				// If the player is going too fast (max speed)
				if (actualSpeed > maxSpeed)
					actualSpeed = maxSpeed;
			}
		}

		// If the player is not sprinting
		else {

			// If the player is not already at base speed
			if (actualSpeed > baseSpeed) {
				actualSpeed -= Time.deltaTime * 2.0f;

				// If the player is going too slow (base speed)
				if (actualSpeed < baseSpeed)
					actualSpeed = baseSpeed;
			}
		}
	}
}

