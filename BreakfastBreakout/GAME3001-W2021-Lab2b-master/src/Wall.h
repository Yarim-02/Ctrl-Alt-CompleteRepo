#pragma once
#ifndef __WALL__
#define __WALL__

#include "DisplayObject.h"
#include "TextureManager.h"

class Wall final : public DisplayObject
{
public:
	Wall();
	~Wall();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	// setters

	int getPlatformID();
	void setPlatformID(int IDNum);


private:
	int m_platformID;

};

#endif /* defined (__PLAYER__) */