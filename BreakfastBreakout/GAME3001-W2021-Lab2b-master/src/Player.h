#pragma once
#ifndef __PLAYER__
#define __PLAYER__

#include "PlayerAnimationState.h"
#include "Sprite.h"

class Player final : public Sprite
{
public:
	Player();
	~Player();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	// getters/setters

	void setAnimationState(PlayerAnimationState new_state);
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
	void setJam(bool jam);
	bool getJam();
	void setJamTime(int time);
	bool getJamTime();
	

private:
	void m_buildAnimations();
	PlayerAnimationState m_currentAnimationState;

	bool m_grounded = false;
	bool m_onLeft = false;
	bool m_onRight = false;
	bool m_bullshit;
	bool m_butter;
	bool m_jam;

	int m_platform;
	int m_butterTime;
	int m_jamTime;
	int m_frameCounter;

};

#endif /* defined (__PLAYER__) */