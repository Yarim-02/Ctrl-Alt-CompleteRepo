#include "Cage.h"
#include "TextureManager.h"

Cage::Cage()
{
	TextureManager::Instance()->load("../Assets/textures/Cage.png", "cage"); // w100 h28


	//auto size = TextureManager::Instance()->getTextureSize("../Assets/textures/Leaf.png");
	setWidth(226);
	setHeight(68);

	m_active = false;

	getTransform()->position = glm::vec2(400.0f, 300.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(PLATFORM);


}

Cage::~Cage()
= default;

void Cage::draw()
{
	TextureManager::Instance()->draw("cage",
		getTransform()->position.x, getTransform()->position.y, 0, 255, false);

}

void Cage::update()
{
	if (m_active)
	{
		if (getOffset().y < 335)
			setOffset(glm::vec2(getOffset().x, getOffset().y + 20));

		//setOffset(glm::vec2(getOffset().x, getOffset().y + 2));
	}
}

void Cage::clean()
{
}

int Cage::getPlatformID()
{
	return m_platformID;
}

void Cage::setPlatformID(int IDNum)
{
	m_platformID = IDNum;
}

void Cage::setActive(bool state)
{
	m_active = state;
}