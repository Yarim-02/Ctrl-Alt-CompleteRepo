#include "Collectable.h"
#include "Background.h"
#include "TextureManager.h"

Collectable::Collectable()
{
	TextureManager::Instance()->load("../Assets/textures/BreadClip1.png", "BreadClip1");
	TextureManager::Instance()->load("../Assets/textures/BreadClip2.png", "BreadClip2");
	TextureManager::Instance()->load("../Assets/textures/BreadClip3.png", "BreadClip3");
	TextureManager::Instance()->load("../Assets/textures/BreadClip4.png", "BreadClip4");
	TextureManager::Instance()->load("../Assets/textures/BreadClip5.png", "BreadClip5");
	TextureManager::Instance()->load("../Assets/textures/BreadClip6.png", "BreadClip6");
	TextureManager::Instance()->load("../Assets/textures/BreadClip7.png", "BreadClip7");

	auto size = TextureManager::Instance()->getTextureSize(fileName);
	setWidth(size.x);
	setHeight(size.y);

	getTransform()->position = glm::vec2(000.0f, 000.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(BACKGROUND);

	m_frameCounter = 0;
}

Collectable::~Collectable()
= default;

void Collectable::draw()
{
	if (m_frameCounter < 10)
	{
		TextureManager::Instance()->draw("BreadClip1",
			getTransform()->position.x, getTransform()->position.y, 0, 255, false);
		auto size = TextureManager::Instance()->getTextureSize("BreadClip1.png");
		setWidth(size.x);
		setHeight(size.y);
	}
	else if (m_frameCounter < 20)
	{
		TextureManager::Instance()->draw("BreadClip2",
			getTransform()->position.x, getTransform()->position.y, 0, 255, false);
		auto size = TextureManager::Instance()->getTextureSize("BreadClip2.png");
		setWidth(size.x);
		setHeight(size.y);
	}
	else if (m_frameCounter < 30)
	{
		TextureManager::Instance()->draw("BreadClip3",
			getTransform()->position.x, getTransform()->position.y, 0, 255, false);
		auto size = TextureManager::Instance()->getTextureSize("BreadClip3.png");
		setWidth(size.x);
		setHeight(size.y);
	}
	else if (m_frameCounter < 40)
	{
		TextureManager::Instance()->draw("BreadClip4",
			getTransform()->position.x, getTransform()->position.y, 0, 255, false);
		auto size = TextureManager::Instance()->getTextureSize("BreadClip4.png");
		setWidth(size.x);
		setHeight(size.y);
	}
	else if (m_frameCounter < 50)
	{
		TextureManager::Instance()->draw("BreadClip5",
			getTransform()->position.x, getTransform()->position.y, 0, 255, false);
		auto size = TextureManager::Instance()->getTextureSize("BreadClip5.png");
		setWidth(size.x);
		setHeight(size.y);
	}
	else if (m_frameCounter < 60)
	{
		TextureManager::Instance()->draw("BreadClip6",
			getTransform()->position.x, getTransform()->position.y, 0, 255, false);
		auto size = TextureManager::Instance()->getTextureSize("BreadClip6.png");
		setWidth(size.x);
		setHeight(size.y);
	}
	else if (m_frameCounter < 70)
	{
		TextureManager::Instance()->draw("BreadClip7",
			getTransform()->position.x, getTransform()->position.y, 0, 255, false);
		auto size = TextureManager::Instance()->getTextureSize("BreadClip7.png");
		setWidth(size.x);
		setHeight(size.y);
	}
}

void Collectable::update()
{
	if (m_frameCounter > 68)
		m_frameCounter = 0;
	
	m_frameCounter++;
}

void Collectable::clean()
{
}