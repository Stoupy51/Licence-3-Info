
using System.IO;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/**
 * LectureData class
 *
 * @brief Read the JSON file and instantiate a prefab "VisuCube" at the given position for each city
 *
 * @author WONG Hua (adapted from COLLIGNON Alexandre)
 */
public class LectureData : MonoBehaviour {

	// Public variables
	public TextAsset jsonFile;
	public VisuData Visualize;

	// Start is called before the first frame update
	void Start() {
		Cities employeesInJson = JsonUtility.FromJson<Cities>(jsonFile.text);

		// For each city
		foreach (City cities in employeesInJson.cities) {
			// Skip if small population to avoid too many cubes
			if (cities.population < 100000)
				continue;

			// Instantiate a prefab "VisuCube" with position, population and multiplier
			Visualize.VisualCube(
				cities.lat,
				cities.lng,
				cities.population,
				Visualize.multiplier
			);
		}
	}
}

