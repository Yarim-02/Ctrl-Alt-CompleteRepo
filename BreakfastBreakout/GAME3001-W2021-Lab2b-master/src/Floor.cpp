#include "Floor.h"
#include "TextureManager.h"

Floor::Floor()
{
	TextureManager::Instance()->load("../Assets/textures/CounterTop1.png", "ground");

	auto size = TextureManager::Instance()->getTextureSize("ground");
	setWidth(size.x);
	setHeight(size.y);

	getTransform()->position = glm::vec2(400.0f, 300.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(FLOOR);


}

Floor::~Floor()
= default;

void Floor::draw()
{
	TextureManager::Instance()->draw("ground",
		getTransform()->position.x, getTransform()->position.y, 0, 255, false);

}

void Floor::update()
{
}

void Floor::clean()
{
}