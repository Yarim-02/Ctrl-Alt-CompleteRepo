#pragma once
#ifndef __MENU_BACKGROUND__
#define __MENU_BACKGROUND__

#include "DisplayObject.h"
#include "TextureManager.h"

class MenuBackground final : public DisplayObject
{
public:
	MenuBackground();
	~MenuBackground();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	// setters



private:

};

#endif#pragma once