
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/**
 * LestCommand class : Manage the deployment of the paws of the Lest
 *
 * @brief Press 'D' to deploy the paws
 *
 * @author COLLIGNON Alexandre
 */
public class LestCommand : MonoBehaviour {

	// Public variables
	public GameObject[] paws;		// Configured in the Unity Editor
	public int deployedState = 0;	// 0 = paws are not deployed, 1 = sub-paws are deploying, 2 = paws are deployed
	public bool moving = false;		// Boolean variable to optimize the code
	
	// Private variables
	private bool[] pawsDeployed;				// Array of boolean to know if the paw is deployed
	private GameObject[] pawsChild;				// Array of the first child of the paws to avoid using GetChild() each time
	private GameObject[] pawsChildChild;		// Array of the first child of the first child of the paws to avoid using GetChild() each time
	private float deployingTime = 2;
	private float deploymentSpeed = 50.0f;

	/**
	 * Start method, called at the beginning of the game
	 *
	 * @brief Initialize the private variables
	 */
	void Start() {
		// Initialize the pawsDeployed array
		this.pawsDeployed = new bool[4];
		for (int i = 0; i < 4; i++) {
			this.pawsDeployed[i] = false;
		}

		// Initialize the pawsChild and pawsChildChild arrays
		this.pawsChild = new GameObject[4];
		this.pawsChildChild = new GameObject[4];
		for (int i = 0; i < 4; i++) {
			this.pawsChild[i] = this.paws[i].transform.GetChild(0).gameObject;
			this.pawsChildChild[i] = this.pawsChild[i].transform.GetChild(0).gameObject;
		}
	}

	/**
	 * FixedUpdate method, called once per physics frame
	 *
	 * @brief Manage the deployment of the paws when the player press 'D'
	 */
	void FixedUpdate() {

		// If player press 'D', start deploying the paws
		if (!this.moving && Input.GetKey(KeyCode.D)) {
			Debug.Log("D pressed: deploying paws");
			this.moving = true;
		}

		// Deploying system
		if (this.moving) {
			// For each paws, rotate Z axis by 135 degree (but -135 for the second and third paws)
			if (this.deployedState == 0) {

				// Rotate the paws
				for (int i = 0; i < 4; i++) {
					// If the paw is not deployed
					if (!this.pawsDeployed[i]) {
						
						// Get the articulation body of the paw
						ArticulationBody articulation = this.paws[i].GetComponent<ArticulationBody>();
						float newDelta = this.deploymentSpeed * Time.fixedDeltaTime;
						if (i == 0 || i == 3)
							newDelta = -newDelta;
					
						articulation.zDrive = new ArticulationDrive {
							lowerLimit = articulation.zDrive.lowerLimit - newDelta,
							upperLimit = articulation.zDrive.upperLimit - newDelta
						};

						// If the paw is deployed, change the boolean value
						this.pawsDeployed[i] = (Mathf.Abs(articulation.zDrive.lowerLimit) >= 135);
					}
				}
				
				// If all the paws are deployed, change the state and set the deploying time
				bool allDeployed = true;
				for (int i = 0; i < 4; i++)
					allDeployed = allDeployed && this.pawsDeployed[i];

				if (allDeployed) {
					Debug.Log("All paws deployed, changing state to 1");
					this.deployedState = 1;
					this.deployingTime = 2;
				}
			}

			// For each paws, rotate X axis by -90 degree their first child and by 90 degree their child's child
			else if (this.deployedState == 1) {

				// Deploy for 2 seconds
				this.deployingTime -= Time.fixedDeltaTime;
				if (this.deployingTime <= 0) {
					Debug.Log("Deploying time finished, changing state to 2");
					this.deployedState = 2;
					this.moving = false;
				}

				// Rotate the paws
				for (int i = 0; i < 4; i++) {
					// Negative if the paw is the second or third
					int negative = i > 1 ? -1 : 1;

					// First child
					if (this.pawsChild[i].transform.rotation.eulerAngles.x < 340) {
						this.pawsChild[i].transform.Rotate(this.deploymentSpeed * Time.fixedDeltaTime * -negative, 0, 0);

						// Child's child
						this.pawsChildChild[i].transform.Rotate(1.7f * this.deploymentSpeed * Time.fixedDeltaTime * negative, 0, 0);
					}
				}
			}
		}
	}
}

