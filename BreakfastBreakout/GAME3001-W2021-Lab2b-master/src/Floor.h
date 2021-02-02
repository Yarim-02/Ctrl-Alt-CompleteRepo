#pragma once
#ifndef __FLOOR__
#define __FLOOR__

#include "DisplayObject.h"
#include "TextureManager.h"

class Floor final : public DisplayObject
{
public:
	Floor();
	~Floor();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	// setters



private:

};

#endif
