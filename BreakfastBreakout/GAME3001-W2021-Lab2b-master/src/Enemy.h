#pragma once
#ifndef __Enemy__
#define __Enemy__

#include "DisplayObject.h"
#include "TextureManager.h"
#include <string>
#include "EnemyType.h"

class Enemy final : public DisplayObject
{
public:
	Enemy(std::string fileNameAndType, EnemyType enemyType);
	~Enemy();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	// setters



private:
	std::string m_fileName;
	EnemyType m_enemyType;
};

#endif