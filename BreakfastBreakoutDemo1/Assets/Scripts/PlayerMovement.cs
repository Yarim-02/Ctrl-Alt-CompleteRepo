using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class PlayerMovement : MonoBehaviour
{
    public PhysicsMaterial2D[] physMats;

    private float moveSpeed = 500f;

    private float jumpVelocity = 20f;
    private float jumpTimer;

    public float maxJamTime = 700f;
    public float jamTimer = 0 ;
    public JamBar jamBar;

    private float leftRight = 0;
    private bool isOnGround = true, jumping = false;

    private Rigidbody2D rb;
    private BoxCollider2D bc;
    private SpriteRenderer spr;
    private Vector2 m_velocity = Vector2.zero;

    Vector3 startPos = new Vector3(0, 0, 0);

    void Start()
    {

        rb = GetComponent<Rigidbody2D>();
        bc = GetComponent<BoxCollider2D>();
        spr = GetComponent<SpriteRenderer>();
        jamBar.SetMaxTime(300f);
    }

    void Update()
    {

        leftRight = Input.GetAxis("Horizontal");

        if (Input.GetButtonDown("Jump"))
        {
            if (isOnGround && !jumping)
                jumping = true;
        }
        if(this.transform.position.y < -10)
        {
            SceneManager.LoadScene(1);
        }
    }

    void FixedUpdate()
    {
        Vector2 targetVelocity = new Vector2(leftRight * moveSpeed * Time.deltaTime, rb.velocity.y);
        rb.velocity = targetVelocity;

        if (jumping)
        {
          //  Debug.Log("JumpStarted");
            isOnGround = false;
            if (Input.GetButton("Jump") && jumpTimer <= 20)
            {
               // Debug.Log("Jump being held");
                rb.velocity = new Vector2(leftRight * moveSpeed * Time.deltaTime, jumpVelocity);
                jumpTimer++;
            }
            else
            {
               // Debug.Log("Stopping jump");
                jumping = false;

            }
            

                       
        }

        if(jamTimer >= 0)
        {
            jamBar.SetJamLength(jamTimer);
            bc.sharedMaterial = physMats[1];
            spr.color = Color.red;
            jamTimer--;         
        }
        else
        {
            bc.sharedMaterial = physMats[0];
            moveSpeed = 500f;
            //jumpVelocity = 20f;
            spr.color = Color.white;
        }

        if(Input.GetAxis("Horizontal") < 0)
        {
            spr.flipX = true;
        }
        else
        {
            spr.flipX = false;
        }

    }

    void OnCollisionEnter2D(Collision2D other)
    {
        if (transform.position.y > other.collider.transform.position.y || jamTimer >=0 )
        {
            isOnGround = true;
            jumpTimer = 0;
        }
        if (other.gameObject.tag == "GameEnder")
        {
            SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex + 1);
        }

    }

    void OnCollisionExit2D(Collision2D other)
    {
        isOnGround = false;       
    }

    void OnTriggerEnter2D(Collider2D powerUp)
    {
        Debug.Log("Touched a power up");
        if(powerUp.tag == "Jam")
        {
            Debug.Log("Touching Jam");
            jamTimer = 300f;
            Destroy(powerUp.gameObject);
        }
    }
}