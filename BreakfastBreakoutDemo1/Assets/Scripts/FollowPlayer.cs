using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FollowPlayer : MonoBehaviour
{
    public Transform playerTransform;
    private float zoom;
    private float yFix;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if(transform.position.y - playerTransform.position.y <= -3)
        {
            yFix += 0.05f;
        }
        if(transform.position.y - playerTransform.position.y >= 3)
        {
            yFix -= 0.05f;
        }
        transform.position = new Vector3(playerTransform.position.x,yFix,-30);
    }
}
