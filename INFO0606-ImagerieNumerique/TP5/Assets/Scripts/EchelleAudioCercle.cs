using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EchelleAudioCercle : MonoBehaviour
{
    public AudioVisu AV;
    public GameObject VisuCube;
    public Vector3 Echelle = new Vector3(1f,1f,1f);
    public Transform Cible;

    private GameObject VC;
    private List<GameObject> VCs = new List<GameObject>();

    public int nombreObjets;
    public float radius = 1;

    // Start is called before the first frame update
    void Start()
    {
        for (var i = 0; i < nombreObjets; i++)
        {
            var angle = i * Mathf.PI * 2 / nombreObjets;
            Vector3 pos = new Vector3(Mathf.Cos(angle), 0, Mathf.Sin(angle)) * radius;
            VC = Instantiate(VisuCube);
            VC.transform.localPosition = pos;
            VC.transform.LookAt(Cible, Vector3.back);
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
            VCs[i].transform.LookAt(Cible, Vector3.back);
        }
    }
}