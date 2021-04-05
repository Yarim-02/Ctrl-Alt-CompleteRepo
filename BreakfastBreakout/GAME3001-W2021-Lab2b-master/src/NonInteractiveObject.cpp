#include "NonInteractiveObject.h"

#include "Background.h"
#include "TextureManager.h"

NonInteractiveObject::NonInteractiveObject(std::string fileNameAndType)
{
	TextureManager::Instance()->load("../Assets/textures/" + fileNameAndType, fileNameAndType);

	fileName = fileNameAndType;
	
	auto size = TextureManager::Instance()->getTextureSize(fileName);
	setWidth(size.x);
	setHeight(size.y);

	getTransform()->position = glm::vec2(000.0f, 000.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(NON_INTERACTIVE);


}

NonInteractiveObject::~NonInteractiveObject()
= default;

void NonInteractiveObject::draw()
{
	TextureManager::Instance()->draw(fileName,
		getTransform()->position.x, getTransform()->position.y, 0, 255, false);

}

void NonInteractiveObject::update()
{
}

void NonInteractiveObject::clean()
{
}