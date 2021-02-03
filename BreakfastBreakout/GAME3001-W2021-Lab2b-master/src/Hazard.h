#pragma once
#ifndef __HAZARD__
#define __HAZARD__

#include "DisplayObject.h"
#include "TextureManager.h"

class Hazard final : public DisplayObject
{
public:
	Hazard();
	~Hazard();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	// setters



private:

};

#endif
