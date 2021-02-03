#include "Platform.h"
#include "TextureManager.h"

Platform::Platform()
{
	TextureManager::Instance()->load("../Assets/textures/platform.png", "platform");

	auto size = TextureManager::Instance()->getTextureSize("platform");
	setWidth(size.x);
	setHeight(size.y);

	getTransform()->position = glm::vec2(400.0f, 300.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(PLATFORM);
	

}

Platform::~Platform()
= default;

void Platform::draw()
{
	TextureManager::Instance()->draw("platform",
		getTransform()->position.x, getTransform()->position.y, 0, 255, false);

}

void Platform::update()
{
}

void Platform::clean()
{
}

int Platform::getPlatformID()
{
	return m_platformID;
}

void Platform::setPlatformID(int IDNum)
{
	m_platformID = IDNum;
}
