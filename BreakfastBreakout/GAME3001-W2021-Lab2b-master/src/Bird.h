#pragma once
#ifndef __BIRD__
#define __BIRD__

#include "DisplayObject.h"
#include "TextureManager.h"

class Bird final : public DisplayObject
{
public:
	Bird();
	~Bird();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	// setters

	int getPlatformID();
	void setPlatformID(int IDNum);

	bool getActive();
	void setActive(bool state);


private:
	int m_platformID;
	int m_animationFrame;
	bool m_active;
	std::string m_fileName;

};
#endif /* defined (__PLAYER__) */