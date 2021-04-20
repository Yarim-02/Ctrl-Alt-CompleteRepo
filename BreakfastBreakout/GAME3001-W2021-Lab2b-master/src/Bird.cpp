#include "Bird.h"
#include "TextureManager.h"

Bird::Bird()
{
	TextureManager::Instance()->load("../Assets/textures/Bird1.png", "bird1"); 
	TextureManager::Instance()->load("../Assets/textures/Bird2.png", "bird2"); 
	TextureManager::Instance()->load("../Assets/textures/Bird3png", "bird3"); 
	TextureManager::Instance()->load("../Assets/textures/Bird4.png", "bird4"); 
	TextureManager::Instance()->load("../Assets/textures/Bird5.png", "bird5"); 
	TextureManager::Instance()->load("../Assets/textures/Bird6.png", "bird6"); 
	TextureManager::Instance()->load("../Assets/textures/Bird7.png", "bird7"); 
	TextureManager::Instance()->load("../Assets/textures/Bird8.png", "bird8"); 
	TextureManager::Instance()->load("../Assets/textures/Bird9.png", "bird9"); 
	TextureManager::Instance()->load("../Assets/textures/Bird10.png", "bird10"); 
	TextureManager::Instance()->load("../Assets/textures/Bird11.png", "bird11"); 
	TextureManager::Instance()->load("../Assets/textures/Bird12.png", "bird12"); 
	TextureManager::Instance()->load("../Assets/textures/Bird13.png", "bird13"); 


	//auto size = TextureManager::Instance()->getTextureSize("../Assets/textures/Leaf.png");
	setWidth(300);
	setHeight(275);

	m_active = false;

	getTransform()->position = glm::vec2(400.0f, 300.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(BIRD);


}

Bird::~Bird()
= default;

void Bird::draw()
{
	if (m_active)
	{
		if (m_animationFrame < 3)
		{
			TextureManager::Instance()->draw("bird1",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
		}
		else if (m_animationFrame < 6)
		{
			TextureManager::Instance()->draw("bird2",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
		}
		else if (m_animationFrame < 9)
		{
			TextureManager::Instance()->draw("bird3",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
		}
		else if (m_animationFrame < 12)
		{
			TextureManager::Instance()->draw("bird4",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
		}
		else if (m_animationFrame < 15)
		{
			TextureManager::Instance()->draw("bird5",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
		}
		else if (m_animationFrame < 18)
		{
			TextureManager::Instance()->draw("bird6",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
		}
		else if (m_animationFrame < 21)
		{
			TextureManager::Instance()->draw("bird7",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
		}
		else if (m_animationFrame < 24)
		{
			TextureManager::Instance()->draw("bird8",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
		}
		else if (m_animationFrame < 27)
		{
			TextureManager::Instance()->draw("bird9",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
		}
		else if (m_animationFrame < 30)
		{
			TextureManager::Instance()->draw("bird10",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
		}
		else if (m_animationFrame < 33)
		{
			TextureManager::Instance()->draw("bird11",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
		}
		else if (m_animationFrame < 36)
		{
			TextureManager::Instance()->draw("bird12",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
		}
		else if (m_animationFrame < 39)
		{
			TextureManager::Instance()->draw("bird13",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
		}
	}
	else
	{
		TextureManager::Instance()->draw("bird9",
			getTransform()->position.x, getTransform()->position.y, 0, 255, false, SDL_FLIP_HORIZONTAL);
	}
}

void Bird::update()
{
	if (m_active)
	{
		if (getOffset().y >= 750)
			setOffset(glm::vec2(getOffset().x, -1560));

		setOffset(glm::vec2(getOffset().x, getOffset().y + 2));

		if (m_animationFrame > 38)
			m_animationFrame = 0;
		m_animationFrame++;
	}
}

void Bird::clean()
{
}

int Bird::getPlatformID()
{
	return m_platformID;
}

void Bird::setPlatformID(int IDNum)
{
	m_platformID = IDNum;
}

bool Bird::getActive()
{
	return m_active;
}

void Bird::setActive(bool state)
{
	m_active = state;
}
