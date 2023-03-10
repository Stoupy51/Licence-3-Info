
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/**
 * ControlGrue class : TODO
 *
 * @brief TODO
 *
 * @author COLLIGNON Alexandre
 */
public class ControlGrue : MonoBehaviour {
	
	// Public variables
	public float torque = 250f;			// TODO
	public float forceChariot = 500f;	// TODO
	public float forceMoufle = 500f;	// TODO
	public ArticulationBody pivot;		// TODO
	public ArticulationBody chariot;	// TODO
	public ArticulationBody moufle;		// TODO

	/**
	 * Start method, called at the beginning of the game
	 *
	 * @brief Initialize the private variables
	 */
	void Start() {
		;
	}

	/**
	 * Update method, called once per frame
	 *
	 * @brief TODO
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

