using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EchelleAudio : MonoBehaviour
{
    public AudioVisu AV;
    public GameObject VisuCube;
    public Vector3 Echelle = new Vector3(1f,1f,1f);

    private GameObject VC;
    private List<GameObject> VCs = new List<GameObject>();

    // Start is called before the first frame update
    void Start()
    {
        for (int i = 0; i < AV.spectrumH.Length; i++)
        {
            VC = Instantiate(VisuCube);
            VC.transform.localPosition = new Vector3(i*0.001f,0,0);
            VCs.Add(VC);
            VC.transform.SetParent(transform);
        }
        transform.localScale = Echelle;
        Debug.Log(transform.name);
    }

    // Update is called once per frame
    void Update()
    {
        for (int i = 0; i < AV.spectrumH.Length; i++)
        {
            VCs[i].transform.localScale = new Vector3(0.1f, 0.1f, 1/Mathf.Log(AV.spectrumH[i]));
        }
    }
}
