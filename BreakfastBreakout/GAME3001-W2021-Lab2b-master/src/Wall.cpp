#include "Wall.h"
#include "TextureManager.h"

Wall::Wall()
{
	TextureManager::Instance()->load("../Assets/textures/Wall.png", "wall");

	auto size = TextureManager::Instance()->getTextureSize("wall");
	setWidth(size.x);
	setHeight(size.y);

	getTransform()->position = glm::vec2(400.0f, 300.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(PLATFORM);


}

Wall::~Wall()
= default;

void Wall::draw()
{
	TextureManager::Instance()->draw("wall",
		getTransform()->position.x, getTransform()->position.y, 0, 255, false);

}

void Wall::update()
{
}

void Wall::clean()
{
}

int Wall::getPlatformID()
{
	return m_platformID;
}

void Wall::setPlatformID(int IDNum)
{
	m_platformID = IDNum;
}
