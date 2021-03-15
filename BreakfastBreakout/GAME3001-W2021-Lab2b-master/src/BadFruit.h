#pragma once
#ifndef __BAD_FRUIT__
#define __BAD_FRUIT__

#include "DisplayObject.h"
#include "TextureManager.h"

class BadFruit final : public DisplayObject
{
public:
	BadFruit();
	~BadFruit();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	// setters



private:

};

#endif