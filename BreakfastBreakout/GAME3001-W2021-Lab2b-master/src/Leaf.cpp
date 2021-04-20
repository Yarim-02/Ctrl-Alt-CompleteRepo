#include "Leaf.h"
#include "TextureManager.h"

Leaf::Leaf()
{
	TextureManager::Instance()->load("../Assets/textures/Leaf.png", "leaf"); // w100 h28


	//auto size = TextureManager::Instance()->getTextureSize("../Assets/textures/Leaf.png");
	setWidth(226);
	setHeight(68);

	getTransform()->position = glm::vec2(400.0f, 300.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(PLATFORM);


}

Leaf::~Leaf()
= default;

void Leaf::draw()
{
	TextureManager::Instance()->draw("leaf",
		getTransform()->position.x, getTransform()->position.y, 0, 255, false);

}

void Leaf::update()
{
	if (getOffset().y >= 750)
		setOffset(glm::vec2(getOffset().x, -1000));

	setOffset(glm::vec2(getOffset().x, getOffset().y + 2));
}

void Leaf::clean()
{
}

int Leaf::getPlatformID()
{
	return m_platformID;
}

void Leaf::setPlatformID(int IDNum)
{
	m_platformID = IDNum;
}
