#include "Enemy.h"
#include "TextureManager.h"

Enemy::Enemy(std::string fileNameAndType, EnemyType enemyType )
{
	TextureManager::Instance()->load("../Assets/textures/" + fileNameAndType, fileNameAndType);

	if (m_enemyType == JELLO)
	{
		for (int i = 1; i < 11; i++)
		{
			TextureManager::Instance()->load("../Assets/textures/Jello" + (std::to_string(i)) +
				static_cast<std::string>(".png"), "Jello" + (std::to_string(i)));
		}
	}
	
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

	if (enemyType != JELLO && enemyType != MUSHROOM)
	{
		auto size = TextureManager::Instance()->getTextureSize(m_fileName);
		setWidth(size.x);
		setHeight(size.y);
	}

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
	if (m_enemyType != JELLO && m_enemyType != MUSHROOM)
		TextureManager::Instance()->draw(m_fileName,
			getTransform()->position.x, getTransform()->position.y, 0, 255, false);

	if (m_enemyType == MUSHROOM)
	{
		if (m_mushroomFrameCounter < 3)
		{
			TextureManager::Instance()->draw("mushroom1",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("mushroom1.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_mushroomFrameCounter < 6)
		{
			TextureManager::Instance()->draw("mushroom2",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("mushroom2.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_mushroomFrameCounter < 9)
		{
			TextureManager::Instance()->draw("mushroom3",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("mushroom3.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_mushroomFrameCounter < 12)
		{
			TextureManager::Instance()->draw("mushroom4",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("mushroom4.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_mushroomFrameCounter < 15)
		{
			TextureManager::Instance()->draw("mushroom5",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("mushroom5.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_mushroomFrameCounter < 18)
		{
			TextureManager::Instance()->draw("mushroom6",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("mushroom6.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_mushroomFrameCounter < 21)
		{
			TextureManager::Instance()->draw("mushroom7",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("mushroom7.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_mushroomFrameCounter < 24)
		{
			TextureManager::Instance()->draw("mushroom8",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("mushroom8.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_mushroomFrameCounter < 27)
		{
			TextureManager::Instance()->draw("mushroom9",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("mushroom9.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_mushroomFrameCounter < 30)
		{
			TextureManager::Instance()->draw("mushroom10",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("mushroom10.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_mushroomFrameCounter < 33)
		{
			TextureManager::Instance()->draw("mushroom11",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("mushroom11.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_mushroomFrameCounter < 36)
		{
			TextureManager::Instance()->draw("mushroom12",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("mushroom12.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_mushroomFrameCounter < 39)
		{
			TextureManager::Instance()->draw("mushroom13",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("mushroom13.png");
			setWidth(size.x);
			setHeight(size.y);
		}
	}
	if (m_enemyType == JELLO)
	{
		if (m_jelloFrameCounter < 5)
		{
			TextureManager::Instance()->draw("Jello1",
				getTransform()->position.x, getTransform()->position.y, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("Jello1.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_jelloFrameCounter < 10)
		{
			TextureManager::Instance()->draw("Jello2",
				getTransform()->position.x, getTransform()->position.y + 12, 0, 255, false);

			auto size = TextureManager::Instance()->getTextureSize("Jello2.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_jelloFrameCounter < 15)
		{
			TextureManager::Instance()->draw("Jello3",
				getTransform()->position.x, getTransform()->position.y + 15, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("Jello3.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_jelloFrameCounter < 20)
		{
			TextureManager::Instance()->draw("Jello4",
				getTransform()->position.x, getTransform()->position.y + 4, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("Jello4.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_jelloFrameCounter < 25)
		{
			TextureManager::Instance()->draw("Jello5",
				getTransform()->position.x, getTransform()->position.y - 23, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("Jello5.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_jelloFrameCounter < 30)
		{
			TextureManager::Instance()->draw("Jello6",
				getTransform()->position.x, getTransform()->position.y - 39, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("Jello6.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_jelloFrameCounter < 35)
		{
			TextureManager::Instance()->draw("Jello7",
				getTransform()->position.x, getTransform()->position.y - 57, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("Jello7.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_jelloFrameCounter < 40)
		{
			TextureManager::Instance()->draw("Jello8",
				getTransform()->position.x, getTransform()->position.y - 39, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("Jello8.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_jelloFrameCounter < 45)
		{
			TextureManager::Instance()->draw("Jello9",
				getTransform()->position.x, getTransform()->position.y - 23, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("Jello9.png");
			setWidth(size.x);
			setHeight(size.y);
		}
		else if (m_jelloFrameCounter < 50)
		{
			TextureManager::Instance()->draw("Jello10",
				getTransform()->position.x, getTransform()->position.y - 8, 0, 255, false);
			auto size = TextureManager::Instance()->getTextureSize("Jello10.png");
			setWidth(size.x);
			setHeight(size.y);
		}
	}

}

void Enemy::update()
{
	if (m_mushroomFrameCounter > 37)
		m_mushroomFrameCounter = -1;
	if (m_jelloFrameCounter > 48)
		m_jelloFrameCounter = 0;

	m_jelloFrameCounter++;
	m_mushroomFrameCounter++;
}

void Enemy::clean()
{
}