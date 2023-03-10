
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
public class Grappin : MonoBehaviour {

	// Private variables
	private FixedJoint joint;	// Joint between the grappin and the collision

	/**
	 * Start method, called at the beginning of the game
	 *
	 * @brief Initialize the private variables
	 */
	void Start() {
		joint = null;
	}

	/**
	 * Update method, called once per frame
	 *
	 * @brief TODO
	 */
	void Update() {

		// Destroy the FixedJoint if the player press the space bar
		if (joint != null && Input.GetKey(KeyCode.Space))
			Destroy(joint);
	}

	/**
	 * OnCollisionEnter method, called by Unity when the player collides with something (ground, wall, ...)
	 *
	 * @brief TODO
	 *
	 * @param collision The Collision data associated with this collision.
	 */
	void OnCollisionEnter(Collision collision) {

		// If the collision is has an ArticulationBody
		if (collision.gameObject.GetComponent<ArticulationBody>() != null) {

			// Create a FixedJoint between the grappin and the collision
			joint = this.gameObject.AddComponent<FixedJoint>();
			joint.connectedArticulationBody = collision.articulationBody;
		}
	}
}

