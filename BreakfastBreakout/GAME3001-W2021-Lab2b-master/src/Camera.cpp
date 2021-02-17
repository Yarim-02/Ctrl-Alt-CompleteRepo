#include "Camera.h"
#include "TextureManager.h"

Camera::Camera()
{


	auto size = TextureManager::Instance()->getTextureSize("Toast_Plain");
	setWidth(5);
	setHeight(5);

	getTransform()->position = glm::vec2(400.0f, 300.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(PLAYER);

}

Camera::~Camera()
= default;


void Camera::update()
{
	getTransform()->position += getRigidBody()->velocity;

}

void Camera::draw()
{


}

void Camera::clean()
{
}

