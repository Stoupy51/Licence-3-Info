
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LestCommand : MonoBehaviour {
	// Public variables (pattes de la grue en anglais)
	public GameObject[] paws;
	public GameObject[] pawsChild;
	public GameObject[] pawsChildChild;
	
	// Private variables
	private Boolean moving = false;
	private int deployedState = 0;

	// Start is called before the first frame update
	void Start() {
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
			this.moving = true;
		}

		// Deploying system
		if (this.moving) {
			// For each paws, rotate Z axis by 135 degree (but -135 for the second and third paws)
			if (this.deployedState == 0) {
				
				// Number of paws finished to deploy
				int numberDeployed = 4;

				// First paw
				if (this.paws[0].transform.rotation.z < 135) {
					this.paws[0].transform.Rotate(0, 0, 135 * Time.deltaTime);
					numberDeployed--;
				}

				// Second paw
				if (this.paws[1].transform.rotation.z > -135) {
					this.paws[1].transform.Rotate(0, 0, -135 * Time.deltaTime);
					numberDeployed--;
				}

				// Third paw
				if (this.paws[2].transform.rotation.z > -135) {
					this.paws[2].transform.Rotate(0, 0, -135 * Time.deltaTime);
					numberDeployed--;
				}

				// Fourth paw
				if (this.paws[3].transform.rotation.z < 135) {
					this.paws[3].transform.Rotate(0, 0, 135 * Time.deltaTime);
					numberDeployed--;
				}
				
				// If all the paws are deployed, change the state
				if (numberDeployed == 4) {
					this.deployedState = 4;
				}
			}

			// For each paws, rotate X axis by -90 degree their first child and by 90 degree their child's child
			else if (this.deployedState >= 2) {
				// Deploy for 2 seconds
				this.deployedState -= Time.deltaTime;

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

