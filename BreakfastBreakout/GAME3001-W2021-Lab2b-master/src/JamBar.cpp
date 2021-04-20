#include "JamBar.h"
#include "TextureManager.h"

JamBar::JamBar()
{
	TextureManager::Instance()->load("../Assets/textures/JamBar.png", "jambar");
	// w6768 h900

	setWidth(200);
	setHeight(50);

	getTransform()->position = glm::vec2(000.0f, 000.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(BACKGROUND);


}

JamBar::~JamBar()
= default;

void JamBar::draw()
{
	TextureManager::Instance()->draw("jambar",
		getTransform()->position.x, getTransform()->position.y, 0, 255, false);

}

void JamBar::update()
{
}

void JamBar::clean()
{
}