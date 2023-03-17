
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/**
 * ControlGrue class : Control the grue
 *
 * @brief Manage the commands for the grue (left, right, up, down, left shift, left control)
 *
 * @author COLLIGNON Alexandre
 */
public class ControlGrue : MonoBehaviour {
	
	// Public variables
	public float torque = 500f;			// Value of the torque applied to the 'pivot' when the player press the left or right arrow
	public float forceChariot = 500f;	// Value of the force applied to the 'chariot' when the player press the up or down arrow
	public float forceMoufle = 500f;	// Value of the force applied to the 'moufle' when the player press the left shift or left control
	public ArticulationBody pivot;		// Variable to store the 'pivot' ArticulationBody
	public ArticulationBody chariot;	// Variable to store the 'chariot' ArticulationBody
	public ArticulationBody moufle;		// Variable to store the 'moufle' ArticulationBody

	/**
	 * Update method, called once per frame
	 *
	 * @brief Manage the commands for the grue (left, right, up, down, left shift, left control)
	 */
	void Update() {
		
		// Commands for 'pivot'
		if (Input.GetKey(KeyCode.LeftArrow))
			pivot.AddTorque(transform.up * -torque);
		if (Input.GetKey(KeyCode.RightArrow))
			pivot.AddTorque(transform.up * torque);

		// Commands for 'chariot'
		if (Input.GetKey(KeyCode.UpArrow))
			chariot.AddRelativeForce(transform.right * forceChariot);
		if (Input.GetKey(KeyCode.DownArrow))
			chariot.AddRelativeForce(transform.right * -forceChariot);
		
		// Commands for 'moufle'
		if (Input.GetKey(KeyCode.LeftShift))
			moufle.AddRelativeForce(transform.up * forceMoufle);
		if (Input.GetKey(KeyCode.LeftControl))
			moufle.AddRelativeForce(transform.up * -forceMoufle);
	}
}

