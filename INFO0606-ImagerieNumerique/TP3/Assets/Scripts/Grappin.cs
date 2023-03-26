
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/**
 * Grappin class
 *
 * @brief Create a FixedJoint between the Grappin and the object it collides with
 * @brief Destroy the FixedJoint if the player press the space bar
 * @brief Apply a force to the Grappin when the player press the left shift or left control
 *
 * @author COLLIGNON Alexandre
 */
public class Grappin : MonoBehaviour {

	// Private variables
	private float forceCrochet = 5.0f;	// Value of the force applied when the player press the left shift or left control
	private ArticulationBody crochet;

	/**
	 * Start method, called at the beginning of the game
	 *
	 * @brief Initialize the private variables
	 */
	void Start() {
		crochet = this.gameObject.GetComponent<ArticulationBody>();
	}

	/**
	 * FixedUpdate method, called once per physics frame
	 *
	 * @brief Destroy the FixedJoint if the player press the space bar
	 */
	void FixedUpdate() {

		// Destroy the FixedJoint if the player press the space bar
		if (Input.GetKey(KeyCode.Space))
			Destroy(this.gameObject.GetComponent<FixedJoint>());
		
		// Commands for 'crochet'
		if (Input.GetKey(KeyCode.LeftShift))
			crochet.AddRelativeForce(transform.up * forceCrochet);
		if (Input.GetKey(KeyCode.LeftControl))
			crochet.AddRelativeForce(transform.up * -forceCrochet);
	}

	/**
	 * OnCollisionEnter method, called by Unity when the player collides with something (ground, wall, ...)
	 *
	 * @brief Create a FixedJoint between the grappin and the collision if the collision is has an ArticulationBody
	 *
	 * @param collision The Collision data associated with this collision.
	 */
	void OnCollisionEnter(Collision collision) {

		// If the collision is has an ArticulationBody
		if (collision.gameObject.GetComponent<ArticulationBody>() != null) {

			// Create a FixedJoint between the grappin and the collision
			FixedJoint joint = this.gameObject.AddComponent<FixedJoint>();
			joint.connectedArticulationBody = collision.articulationBody;
		}
	}
}

