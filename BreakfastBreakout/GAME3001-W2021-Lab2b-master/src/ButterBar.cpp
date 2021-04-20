#include "ButterBar.h"
#include "TextureManager.h"

ButterBar::ButterBar()
{
	TextureManager::Instance()->load("../Assets/textures/ButterBar.png", "butterbar");
	// w6768 h900
	
	setWidth(200);
	setHeight(50);

	getTransform()->position = glm::vec2(000.0f, 000.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(BACKGROUND);


}

ButterBar::~ButterBar()
= default;

void ButterBar::draw()
{
	TextureManager::Instance()->draw("butterbar",
		getTransform()->position.x, getTransform()->position.y, 0, 255, false);

}

void ButterBar::update()
{
}

void ButterBar::clean()
{
}