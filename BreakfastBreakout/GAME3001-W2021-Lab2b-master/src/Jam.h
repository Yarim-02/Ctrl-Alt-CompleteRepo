#pragma once
#ifndef __JAM__
#define __JAM__

#include "DisplayObject.h"
#include "TextureManager.h"

class Jam final : public DisplayObject
{
public:
	Jam();
	~Jam();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	// setters
	void setHideTimer(int time);
	int getHideTimer();


private:
	int m_hideTimer;
	float m_xPos;
};

#endif
