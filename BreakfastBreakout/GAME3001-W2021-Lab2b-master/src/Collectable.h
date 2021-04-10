
#pragma once
#ifndef __COLLECTABLE__
#define __COLLECTABLE__

#include "DisplayObject.h"
#include "TextureManager.h"
#include <string>

class Collectable final : public DisplayObject
{
public:
	Collectable();
	~Collectable();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	// setters



private:
	std::string fileName;
	int m_frameCounter;
};

#endif
