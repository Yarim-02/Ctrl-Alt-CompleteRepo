#pragma once
#ifndef __PLATFORM__
#define __PLATFORM__

#include "DisplayObject.h"
#include "TextureManager.h"

class Platform final : public DisplayObject
{
public:
	Platform();
	~Platform();

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
