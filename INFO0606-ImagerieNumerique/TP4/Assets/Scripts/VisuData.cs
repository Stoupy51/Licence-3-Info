
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/**
 * VisuData class
 *
 * @brief Create a cube at the given position to visualize the data
 *
 * @author WONG Hua (adapted from COLLIGNON Alexandre)
 */
public class VisuData : MonoBehaviour {

	// Public variables
	public Transform cible;
	public GameObject visuCube;
	public float multiplier;

	/**
	 * @brief Convert a latitude and longitude to a 3D position
	 *
	 * @param lat Latitude
	 * @param lon Longitude
	 *
	 * @return 3D position (x, y, z)
	 */
	Vector3 latloncart(float lat, float lon) {
		Vector3 pos;

		float x = 0.5f * Mathf.Cos(lon) * Mathf.Cos(lat);
		float y = 0.5f * Mathf.Cos(lon) * Mathf.Sin(lat);
		float z = 0.5f * Mathf.Sin(lon);

		pos.x = 0.5f * Mathf.Cos((lon) * Mathf.Deg2Rad) * Mathf.Cos(lat * Mathf.Deg2Rad);
		pos.y = 0.5f * Mathf.Sin(lat * Mathf.Deg2Rad);
		pos.z = 0.5f * Mathf.Sin((lon) * Mathf.Deg2Rad) * Mathf.Cos(lat * Mathf.Deg2Rad);

		return pos;
	}

	/**
	 * @brief Instantiate a prefab "VisuCube" at the given position
	 * @brief Change color depending on the value of echelle.z
	 *
	 * @param lat Latitude
	 * @param lon Longitude
	 * @param val Value
	 * @param multiplier Multiplier
	 */
	public void VisualCube(float lat, float lon, float val, float multiplier) {
		GameObject cube = GameObject.Instantiate(this.visuCube);
		Vector3 pos;

		pos = latloncart(lat, lon);
		cube.transform.position = new Vector3(pos.x, pos.y, pos.z);
		cube.transform.LookAt(this.cible, Vector3.back);

		Vector3 echelle = cube.transform.localScale;
		echelle.z = val * multiplier;
		cube.transform.localScale = echelle;

		// Change color depending on the value of echelle.z progressively from green to red
		GameObject child = cube.transform.GetChild(0).gameObject;
		Renderer rend = child.GetComponent<Renderer>();
		if (echelle.z > 0.01f)
			rend.material.color = new Color(echelle.z * 2.5f, 1 - echelle.z * 2.5f, 0);
		else
			rend.material.color = new Color(0, 0.25f, 0);
	}
}

