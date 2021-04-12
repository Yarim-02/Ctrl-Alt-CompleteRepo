#include "Jam.h"
#include "TextureManager.h"

Jam::Jam()
{
	TextureManager::Instance()->load("../Assets/textures/JellyDonut.png", "jam");

	auto size = TextureManager::Instance()->getTextureSize("jam");
	setWidth(size.x);
	setHeight(size.y);

	getTransform()->position = glm::vec2(0.0f, 0.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(JAM);


}

Jam::~Jam()
= default;

void Jam::draw()
{
	TextureManager::Instance()->draw("jam",
		getTransform()->position.x, getTransform()->position.y, 0, 255, false);

}

void Jam::update()
{
	if (getTransform()->position.x < 0)
	{
		//std::cout << "hi" << std::endl;
		m_hideTimer -= 1;
	}

}

void Jam::clean()
{
}

void Jam::setHideTimer(int time)
{
	m_hideTimer = time;
}

int Jam::getHideTimer()
{
	return m_hideTimer;
}