#include "Player.h"
#include "TextureManager.h"

Player::Player()
{	
	TextureManager::Instance()->load("../Assets/textures/TheToast.png", "Toast_Plain");
	TextureManager::Instance()->load("../Assets/textures/Buttery.png", "Toast_Buttery");

	auto size = TextureManager::Instance()->getTextureSize("Toast_Plain");
	setWidth(size.x);
	setHeight(size.y);

	getTransform()->position = glm::vec2(400.0f, 300.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(PLAYER);

}

Player::~Player()
= default;

void Player::draw()
{
	if (m_butter == false)
	{
		TextureManager::Instance()->draw("Toast_Plain",
			getTransform()->position.x, getTransform()->position.y, 0, 255, false);
	}
	else
	{
		TextureManager::Instance()->draw("Toast_Buttery",
			getTransform()->position.x, getTransform()->position.y, 0, 255, false);
	}
	
}

void Player::update()
{
	/*if (m_grounded == false)
	{
		getRigidBody()->velocity += glm::vec2(0, 0.8);
	}
	getTransform()->position += getRigidBody()->velocity;

	if (getRigidBody()->velocity.x >= 9)
		getRigidBody()->velocity.x = 9;
		*/
	if (m_butterTime > 0)
	{
		m_butter = true;
		m_butterTime -= 1;
	}
	else		
		m_butter = false;

	if(m_butter == false)
		getRigidBody()->velocity.x = 0;

}

void Player::clean()
{
}

void Player::setGrounded(bool onGround)
{
	m_grounded = onGround;
}

bool Player::getGrounded()
{
	return m_grounded;
}

void Player::setLeft(bool onWall)
{
	m_onLeft = onWall;
}

bool Player::getLeft()
{
	return m_onLeft;
}

void Player::setRight(bool onWall)
{
	m_onRight = onWall;
}

bool Player::getRight()
{
	return m_onRight;
}

void Player::setCurPlatform(int platformNum)
{
	m_platform = platformNum;
}

int Player::getCurPlatform()
{
	return  m_platform;
}

void Player::setBullshit(bool bullshit)
{
}

bool Player::getBullshit()
{
	return false;
}

void Player::setButter(bool butter)
{
	m_butter = butter;
}

bool Player::getButter()
{
	return m_butter;;
}

void Player::setButterTime(int time)
{
	m_butterTime = time;
}

int Player::getButterTime()
{
	return m_butterTime;
}



