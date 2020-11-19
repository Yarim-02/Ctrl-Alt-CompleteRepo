using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMovement : MonoBehaviour
{

    public float moveSpeed = 100f;

    public float jumpVelocity = 100f;


    private float leftRight = 0;
    private bool isOnGround = true, jumping = false;

    private Rigidbody2D rb;
    private Vector2 m_velocity = Vector2.zero;

    Vector3 startPos = new Vector3(0, 0, 0);

    void Start()
    {

        rb = GetComponent<Rigidbody2D>();
    }

    void Update()
    {

        leftRight = Input.GetAxis("Horizontal");

        if (Input.GetButtonDown("Jump"))
        {
            if (isOnGround && !jumping)
                jumping = true;
        }
        if(this.transform.position.y < -50)
        {
            this.gameObject.transform.position = startPos;
        }
    }

    void FixedUpdate()
    {
        Vector2 targetVelocity = new Vector2(leftRight * moveSpeed * Time.deltaTime, rb.velocity.y);
        rb.velocity = targetVelocity;

        if (jumping)
        {

            jumping = false;
            isOnGround = false;

            rb.AddForce(new Vector2(0, 1) * jumpVelocity);
        }

    }

    void OnCollisionEnter2D(Collision2D other)
    {
        if (other.gameObject.tag == "Ground")
            Debug.Log("landed");
            isOnGround = true;
        
    }
}