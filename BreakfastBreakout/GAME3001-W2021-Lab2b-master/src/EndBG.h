#pragma once
#ifndef __END_BACKGROUND__
#define __END_BACKGROUND__

#include "DisplayObject.h"
#include "TextureManager.h"

class EndBackground final : public DisplayObject
{
public:
	EndBackground();
	~EndBackground();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	// setters



private:

};

#endif#pragma once