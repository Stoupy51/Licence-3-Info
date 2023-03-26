
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LestCommand : MonoBehaviour {
	// Public variables (pattes de la grue en anglais)
	public GameObject[] paws;
	public bool[] pawsDeployed;
	public GameObject[] pawsChild;
	public GameObject[] pawsChildChild;
	
	// Private variables
	private bool moving = false;
	private int deployedState = 0;
	private float deployingTime = 2;

	// Start is called before the first frame update
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

	// Update is called once per frame
	void Update() {

		// If player press 'D', start deploying the paws
		if (Input.GetKeyDown(KeyCode.D)) {
			Debug.Log("D pressed");
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

						if (i == 0 || i == 3) {
							articulation.zDrive = new ArticulationDrive {
								lowerLimit = articulation.zDrive.lowerLimit - 135 * Time.deltaTime,
								upperLimit = articulation.zDrive.upperLimit + 135 * Time.deltaTime
							};
							this.pawsDeployed[i] = (articulation.zDrive.lowerLimit <= -135);
						}
						else {						
							articulation.zDrive = new ArticulationDrive {
								lowerLimit = articulation.zDrive.lowerLimit + 135 * Time.deltaTime,
								upperLimit = articulation.zDrive.upperLimit - 135 * Time.deltaTime
							};
							this.pawsDeployed[i] = (articulation.zDrive.lowerLimit >= 135);
						}
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
				this.deployingTime -= Time.deltaTime;
				if (this.deployingTime <= 0) {
					Debug.Log("Deploying time finished, changing state to 2");
					this.deployedState = 2;
					this.moving = false;
				}

				// Rotate the paws
				for (int i = 0; i < 4; i++) {
					// First child
					if (this.pawsChild[i].transform.rotation.x > -90)
						this.pawsChild[i].transform.Rotate(-90 * Time.deltaTime, 0, 0);

					// Child's child
					if (this.pawsChildChild[i].transform.rotation.x < 90)
						this.pawsChildChild[i].transform.Rotate(90 * Time.deltaTime, 0, 0);
				}
			}
		}
	}
}

