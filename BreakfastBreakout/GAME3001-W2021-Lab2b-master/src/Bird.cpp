#include "Bird.h"
#include "TextureManager.h"

Bird::Bird()
{
	TextureManager::Instance()->load("../Assets/textures/BirdCopy.png", "bird"); // w100 h28


	//auto size = TextureManager::Instance()->getTextureSize("../Assets/textures/Leaf.png");
	setWidth(300);
	setHeight(165);

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
	TextureManager::Instance()->draw("bird",
		getTransform()->position.x, getTransform()->position.y, 0, 255, false);

}

void Bird::update()
{
	if (m_active)
	{
		if (getOffset().y >= 750)
			setOffset(glm::vec2(getOffset().x, -1560));

		setOffset(glm::vec2(getOffset().x, getOffset().y + 2));
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
