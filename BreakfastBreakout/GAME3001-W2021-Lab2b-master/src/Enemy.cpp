#include "Enemy.h"
#include "TextureManager.h"

Enemy::Enemy(std::string fileNameAndType, EnemyType enemyType )
{
	TextureManager::Instance()->load("../Assets/textures/" + fileNameAndType, fileNameAndType);

	m_fileName = fileNameAndType;
	m_enemyType = enemyType; // use to determine which behavior to use
	
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

}

void Enemy::update()
{
}

void Enemy::clean()
{
}