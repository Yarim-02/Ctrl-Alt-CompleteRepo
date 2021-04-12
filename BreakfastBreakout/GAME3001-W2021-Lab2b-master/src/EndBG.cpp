#include "EndBG.h"
#include "TextureManager.h"

EndBackground::EndBackground()
{
	TextureManager::Instance()->load("../Assets/textures/endBG.png", "endBG");

	auto size = TextureManager::Instance()->getTextureSize("endBG");
	setWidth(size.x);
	setHeight(size.y);

	getTransform()->position = glm::vec2(-250.0f, 000.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(END_BACKGROUND);


}

EndBackground::~EndBackground()
= default;

void EndBackground::draw()
{
	TextureManager::Instance()->draw("endBG",
		getTransform()->position.x, getTransform()->position.y, 0, 255, false);

}

void EndBackground::update()
{
}

void EndBackground::clean()
{
}