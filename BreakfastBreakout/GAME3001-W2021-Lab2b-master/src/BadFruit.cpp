#include "BadFruit.h"
#include "TextureManager.h"

BadFruit::BadFruit()
{
	TextureManager::Instance()->load("../Assets/textures/enemy.jpg", "badfruit");

	auto size = TextureManager::Instance()->getTextureSize("badfruit");
	setWidth(size.x);
	setHeight(size.y);

	getTransform()->position = glm::vec2(400.0f, 300.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(HAZARD);


}

BadFruit::~BadFruit()
= default;

void BadFruit::draw()
{
	TextureManager::Instance()->draw("badfruit",
		getTransform()->position.x, getTransform()->position.y, 0, 255, false);

}

void BadFruit::update()
{
}

void BadFruit::clean()
{
}