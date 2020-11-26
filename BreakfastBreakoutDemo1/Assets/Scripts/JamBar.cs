using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class JamBar : MonoBehaviour
{

    public Slider slider;
    // Start is called before the first frame update

    public void SetMaxTime(float jamLength)
    {
        slider.maxValue = jamLength;
    }
    public void SetJamLength(float jamTime)
    {
        slider.value = jamTime;
    }
}
