#include "Player.h"
#include "TextureManager.h"

Player::Player() : m_currentAnimationState(PLAYER_IDLE_RIGHT)
{	
	TextureManager::Instance()->loadSpriteSheet(
		"../Assets/sprites/atlas.txt",
		"../Assets/sprites/atlas.png",
		"spritesheet");

	TextureManager::Instance()->load("../Assets/textures/Player_Walking_0.png", "walking0");
	TextureManager::Instance()->load("../Assets/textures/Player_Walking_1.png", "walking1");
	TextureManager::Instance()->load("../Assets/textures/Buttered_Walking_0.png", "buttered0");
	TextureManager::Instance()->load("../Assets/textures/Buttered_Walking_1.png", "buttered1");
	TextureManager::Instance()->load("../Assets/textures/JellyToast1.png", "jam1");
	TextureManager::Instance()->load("../Assets/textures/JellyToast2.png", "jam2");

	setSpriteSheet(TextureManager::Instance()->getSpriteSheet("spritesheet"));

	//auto size = TextureManager::Instance()->getTextureSize("Toast_Plain");

	setWidth(46);
	setHeight(70);

	getTransform()->position = glm::vec2(400.0f, 300.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(PLAYER);

	m_buildAnimations();
}

Player::~Player()
= default;

void Player::draw()
{
	/*if (m_butter == false)
	{
		TextureManager::Instance()->draw("Toast_Plain",
			getTransform()->position.x, getTransform()->position.y, 0, 255, false);
	}
	else
	{
		TextureManager::Instance()->draw("Toast_Buttery",
			getTransform()->position.x, getTransform()->position.y, 0, 255, false);
	}*/

	const auto x = getTransform()->position.x;
	const auto y = getTransform()->position.y;

	// draw the player according to animation state
	switch (m_currentAnimationState)
	{
	case PLAYER_IDLE_RIGHT:
		TextureManager::Instance()->draw("walking0",
			getTransform()->position.x, getTransform()->position.y, 0, 255, false);
		break;
	case PLAYER_IDLE_LEFT:
		TextureManager::Instance()->draw("walking0",
			getTransform()->position.x, getTransform()->position.y, 0, 255, false, SDL_FLIP_HORIZONTAL);
		break;
	case PLAYER_BUTTER_IDLE_RIGHT:
		TextureManager::Instance()->draw("buttered0",
			getTransform()->position.x, getTransform()->position.y, 0, 255, false);
		break;
	case PLAYER_BUTTER_IDLE_LEFT:
		TextureManager::Instance()->draw("buttered0",
			getTransform()->position.x, getTransform()->position.y, 0, 255, false, SDL_FLIP_HORIZONTAL);
		break;
	case PLAYER_JAM_IDLE_RIGHT:
		TextureManager::Instance()->draw("jam1",
			getTransform()->position.x, getTransform()->position.y, 0, 255, false);
		break;
	case PLAYER_JAM_IDLE_LEFT:
		TextureManager::Instance()->draw("jam1",
			getTransform()->position.x, getTransform()->position.y, 0, 255, false, SDL_FLIP_HORIZONTAL);
		break;
	case PLAYER_RUN_RIGHT:
		if (m_frameCounter % 20 >= 0&& m_frameCounter % 20 <= 10)
			TextureManager::Instance()->draw("walking0",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
		else
			TextureManager::Instance()->draw("walking1",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
		break;
	case PLAYER_RUN_LEFT:
		if (m_frameCounter % 20 >= 0 && m_frameCounter % 20 <= 10)
			TextureManager::Instance()->draw("walking0",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false, SDL_FLIP_HORIZONTAL);
		else
			TextureManager::Instance()->draw("walking1",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false, SDL_FLIP_HORIZONTAL);
		break;
	case PLAYER_BUTTER_RIGHT:
		if (m_frameCounter % 20 >= 0 && m_frameCounter % 20 <= 10)
			TextureManager::Instance()->draw("buttered0",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
		else
			TextureManager::Instance()->draw("buttered1",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
		break;
	case PLAYER_BUTTER_LEFT:
		if (m_frameCounter % 20 >= 0 && m_frameCounter % 20 <= 10)
			TextureManager::Instance()->draw("buttered0",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false, SDL_FLIP_HORIZONTAL);
		else
			TextureManager::Instance()->draw("buttered1",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false, SDL_FLIP_HORIZONTAL);
		break;
	case PLAYER_JAM_RIGHT:
		if (m_frameCounter % 20 >= 0 && m_frameCounter % 20 <= 10)
			TextureManager::Instance()->draw("jam1",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
		else
			TextureManager::Instance()->draw("jam2",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
		break;
	case PLAYER_JAM_LEFT:
		if (m_frameCounter % 20 >= 0 && m_frameCounter % 20 <= 10)
			TextureManager::Instance()->draw("jam1",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false, SDL_FLIP_HORIZONTAL);
		else
			TextureManager::Instance()->draw("jam2",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false, SDL_FLIP_HORIZONTAL);
		break;
	default:
		break;
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

	if (m_jamTime > 0)
	{
		m_jam = true;
		m_jamTime -= 1;
	}
	else
		m_jam = false;

	if (m_frameCounter > 5000)
		m_frameCounter = 0;

	m_frameCounter++;

}

void Player::setAnimationState(const PlayerAnimationState new_state)
{
	m_currentAnimationState = new_state;
}

void Player::m_buildAnimations()
{
	Animation idleAnimation = Animation();

	idleAnimation.name = "idle";
	idleAnimation.frames.push_back(getSpriteSheet()->getFrame("islande"));
	/*idleAnimation.frames.push_back(getSpriteSheet()->getFrame("megaman-idle-1"));
	idleAnimation.frames.push_back(getSpriteSheet()->getFrame("megaman-idle-2"));
	idleAnimation.frames.push_back(getSpriteSheet()->getFrame("megaman-idle-3"));*/

	setAnimation(idleAnimation);

	Animation runAnimation = Animation();

	runAnimation.name = "run";
	runAnimation.frames.push_back(getSpriteSheet()->getFrame("megaman-run-0"));
	runAnimation.frames.push_back(getSpriteSheet()->getFrame("megaman-run-1"));
	runAnimation.frames.push_back(getSpriteSheet()->getFrame("megaman-run-2"));
	runAnimation.frames.push_back(getSpriteSheet()->getFrame("megaman-run-3"));

	setAnimation(runAnimation);
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

void Player::setJam(bool jam)
{
	m_jam = jam;
}

bool Player::getJam()
{
	return m_jam;
}

void Player::setJamTime(int time)
{
	m_jamTime = time;
}

bool Player::getJamTime()
{
	return m_jamTime;
}



