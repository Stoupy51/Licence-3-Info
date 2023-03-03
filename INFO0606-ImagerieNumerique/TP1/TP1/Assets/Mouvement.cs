
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Mouvement : MonoBehaviour {
    private bool isGrounded;
    private Rigidbody r_body;

    // Start is called before the first frame update
    void Start() {
        isGrounded = true;
        r_body = GetComponent<Rigidbody>();
    }

    /**
     * Update is called once per frame
     *
     * @brief Inputs for the player :
     * - UpArrow : move forward
     * - DownArrow : move backward
     * - LeftArrow : rotate left
     * - RightArrow : rotate right
     * - Space : jump
     */
    void Update() {

        // Inputs
        if (Input.GetKey(KeyCode.DownArrow))
            transform.Translate(Vector3.forward * Time.deltaTime * 3);
        if (Input.GetKey(KeyCode.UpArrow))
            transform.Translate(Vector3.back * Time.deltaTime * 3);
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

    /**
     * OnCollisionEnter is called when this collider/rigidbody has begun
     * touching another rigidbody/collider.
     *
     * @brief Check if the player is grounded
     */
    void OnCollisionEnter(Collision collision) {
        if (!isGrounded && collision.gameObject.transform.position.y < transform.position.y) {
            Debug.Log("Collision");
            isGrounded = true;
        }
    }
}

