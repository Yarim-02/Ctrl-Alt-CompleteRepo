#pragma once
#ifndef __PLAYER__
#define __PLAYER__

#include "DisplayObject.h"
#include "TextureManager.h"

class Player final : public DisplayObject
{
public:
	Player();
	~Player();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	// getters/setters

	void setGrounded(bool onGround);
	bool getGrounded();
	void setLeft(bool onWall);
	bool getLeft();
	void setRight(bool onWall);
	bool getRight();
	void setCurPlatform(int platformNum);
	int getCurPlatform();
	void setBullshit(bool bullshit);
	bool getBullshit();
	void setButter(bool butter);
	bool getButter();
	void setButterTime(int time);
	int getButterTime();
	

private:
	void m_buildAnimations();

	bool m_grounded = false;
	bool m_onLeft = false;
	bool m_onRight = false;
	bool m_bullshit;
	bool m_butter;

	int m_platform;
	int m_butterTime;

};

#endif /* defined (__PLAYER__) */