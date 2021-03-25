#include "Enemy.h"
#include "TextureManager.h"

Enemy::Enemy(std::string fileNameAndType, EnemyType enemyType )
{
	TextureManager::Instance()->load("../Assets/textures/" + fileNameAndType, fileNameAndType);

	m_fileName = fileNameAndType;
	m_enemyType = enemyType; // use to determine which behavior to use

	TextureManager::Instance()->load("../Assets/textures/mushroom1.png", "mushroom1");
	TextureManager::Instance()->load("../Assets/textures/mushroom2.png", "mushroom2");
	TextureManager::Instance()->load("../Assets/textures/mushroom3.png", "mushroom3");
	TextureManager::Instance()->load("../Assets/textures/mushroom4.png", "mushroom4");
	TextureManager::Instance()->load("../Assets/textures/mushroom5.png", "mushroom5");
	TextureManager::Instance()->load("../Assets/textures/mushroom6.png", "mushroom6");
	TextureManager::Instance()->load("../Assets/textures/mushroom7.png", "mushroom7");
	TextureManager::Instance()->load("../Assets/textures/mushroom8.png", "mushroom8");
	TextureManager::Instance()->load("../Assets/textures/mushroom9.png", "mushroom9");
	TextureManager::Instance()->load("../Assets/textures/mushroom10.png", "mushroom10");
	TextureManager::Instance()->load("../Assets/textures/mushroom11.png", "mushroom11");
	TextureManager::Instance()->load("../Assets/textures/mushroom12.png", "mushroom12");
	TextureManager::Instance()->load("../Assets/textures/mushroom13.png", "mushroom13");
	
	auto size = TextureManager::Instance()->getTextureSize(m_fileName);
	setWidth(size.x);
	setHeight(size.y);

	getTransform()->position = glm::vec2(400.0f, 300.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(HAZARD);


}

Enemy::~Enemy()
= default;

void Enemy::draw()
{
	TextureManager::Instance()->draw(m_fileName,
		getTransform()->position.x, getTransform()->position.y, 0, 255, false);

	if (m_enemyType == MUSHROOM)
	{
		if (m_frameCounter < 5)
		{
			TextureManager::Instance()->draw("mushroom1",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("mushroom1.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_frameCounter < 10)
		{
			TextureManager::Instance()->draw("mushroom2",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("mushroom2.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_frameCounter < 15)
		{
			TextureManager::Instance()->draw("mushroom3",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("mushroom3.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_frameCounter < 20)
		{
			TextureManager::Instance()->draw("mushroom4",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("mushroom4.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_frameCounter < 25)
		{
			TextureManager::Instance()->draw("mushroom5",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("mushroom5.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_frameCounter < 30)
		{
			TextureManager::Instance()->draw("mushroom6",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("mushroom6.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_frameCounter < 35)
		{
			TextureManager::Instance()->draw("mushroom7",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("mushroom7.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_frameCounter < 40)
		{
			TextureManager::Instance()->draw("mushroom8",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("mushroom8.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_frameCounter < 45)
		{
			TextureManager::Instance()->draw("mushroom9",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("mushroom9.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_frameCounter < 50)
		{
			TextureManager::Instance()->draw("mushroom10",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("mushroom10.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_frameCounter < 55)
		{
			TextureManager::Instance()->draw("mushroom11",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("mushroom11.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_frameCounter < 60)
		{
			TextureManager::Instance()->draw("mushroom12",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("mushroom12.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_frameCounter < 65)
		{
			TextureManager::Instance()->draw("mushroom13",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("mushroom13.png");
			setWidth(size.x);
			setHeight(size.y);
		}
	}

}

void Enemy::update()
{
	if (m_frameCounter > 48)
		m_frameCounter = 0;

	m_frameCounter++;
}

void Enemy::clean()
{
}