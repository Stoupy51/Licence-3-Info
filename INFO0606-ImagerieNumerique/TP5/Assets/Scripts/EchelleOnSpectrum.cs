using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class EchelleOnSpectrum : MonoBehaviour
{
    public GameObject Objet;
    //public EtatBeat Beat = EtatBeat.Offbeat;
    public float delais = 1.0f;
    
    public Vector3 AxeEchelle = new Vector3(0, 0, 1.0f);
    public Vector3 TailleEchelle = new Vector3(2.0f, 2.0f, 2.0f );
    Vector3 DefautEchelle;

    // Start is called before the first frame update
    void Start()
    {
        Vector3 DefautEchelle = Objet.transform.localScale;
        Debug.Log(DefautEchelle);
    }
    void Update()
    {

    }


    public void onSpectrum(float[] spectrum)
    {
        Objet.transform.localScale = new Vector3(TailleEchelle.x * spectrum[0], TailleEchelle.y * spectrum[0], TailleEchelle.z * spectrum[0]);
        //Objet.transform.localScale = new Vector3(DefautEchelle.x * spectrum[0], DefautEchelle.y * spectrum[0], DefautEchelle.z * spectrum[0]);
        //Debug.Log(DefautEchelle);
    }
}
