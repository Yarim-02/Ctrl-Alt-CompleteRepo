#include "Background.h"
#include "TextureManager.h"

Background::Background()
{
	TextureManager::Instance()->load("../Assets/textures/Background.png", "Background");

	auto size = TextureManager::Instance()->getTextureSize("Background");
	setWidth(size.x);
	setHeight(size.y);

	getTransform()->position = glm::vec2(000.0f, 000.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(BACKGROUND);


}

Background::~Background()
= default;

void Background::draw()
{
	TextureManager::Instance()->draw("Background",
		getTransform()->position.x, getTransform()->position.y, 0, 255, false);

}

void Background::update()
{
}

void Background::clean()
{
}