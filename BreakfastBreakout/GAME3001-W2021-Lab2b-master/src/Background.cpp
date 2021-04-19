#include "Background.h"
#include "TextureManager.h"

Background::Background(std::string fileNameAndType, std::string name)
{
	TextureManager::Instance()->load("../Assets/textures/" + fileNameAndType, name);
	// w6768 h900
		auto size = TextureManager::Instance()->getTextureSize(name);
	setWidth(size.x);
	setHeight(size.y);

	getTransform()->position = glm::vec2(000.0f, 000.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(BACKGROUND);

	fileName = name;
}

Background::~Background()
= default;

void Background::draw()
{
	TextureManager::Instance()->draw(fileName,
		getTransform()->position.x, getTransform()->position.y, 0, 255, false);

}

void Background::update()
{
}

void Background::clean()
{
}