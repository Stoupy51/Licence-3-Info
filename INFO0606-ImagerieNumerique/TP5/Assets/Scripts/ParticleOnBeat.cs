using System.Collections;
using System.Collections.Generic;
using UnityEngine;

//public enum EtatBeat { Offbeat = 0, Onbeat = 1 };

public class ParticleOnBeat : MonoBehaviour
{
    public ParticleSystem Particules;
    public EtatBeat Beat = EtatBeat.Offbeat;
    public float delais = 1.0f;
    public Vector3 RGBOnBeat = new Vector3(0.75f,0.4f,0);
    public Vector3 RGBOffBeat = new Vector3(1.0f, 1.0f, 0);

    // Start is called before the first frame update
    void Start()
    {

    }
    void Update()
    {

    }


    public void onOnbeatDetected()
    {
        Beat = EtatBeat.Onbeat;
        StartCoroutine("ChangeCouleur");
    }

    IEnumerator ChangeCouleur()
    {
        var main = Particules.main;
        
        main.startColor = new Color(RGBOnBeat.x, RGBOnBeat.y, RGBOnBeat.z);
        yield return new WaitForSeconds(delais);
        main.startColor = new Color(RGBOffBeat.x, RGBOffBeat.y, RGBOffBeat.z);
        Beat = EtatBeat.Offbeat;
    }
}
