
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/**
 * Grappin class
 *
 * @brief Create a FixedJoint between the Grappin and the object it collides with
 * @brief Destroy the FixedJoint if the player press the space bar
 *
 * @author COLLIGNON Alexandre
 */
public class Grappin : MonoBehaviour {

	/**
	 * Update method, called once per frame
	 *
	 * @brief Destroy the FixedJoint if the player press the space bar
	 */
	void Update() {

		// Destroy the FixedJoint if the player press the space bar
		if (Input.GetKey(KeyCode.Space))
			Destroy(this.gameObject.GetComponent<FixedJoint>());
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

