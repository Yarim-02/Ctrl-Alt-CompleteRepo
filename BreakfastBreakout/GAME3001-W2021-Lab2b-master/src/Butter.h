#pragma once
#ifndef __BUTTER__
#define __BUTTER__

#include "DisplayObject.h"
#include "TextureManager.h"

class Butter final : public DisplayObject
{
public:
	Butter();
	~Butter();

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
