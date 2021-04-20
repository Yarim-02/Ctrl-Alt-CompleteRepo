#pragma once
#ifndef __CAGE__
#define __CAGE__

#include "DisplayObject.h"
#include "TextureManager.h"

class Cage final : public DisplayObject
{
public:
	Cage();
	~Cage();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	// setters

	int getPlatformID();
	void setPlatformID(int IDNum);

	void setActive(bool state);


private:
	int m_platformID;
	bool m_active;
	std::string m_fileName;

};

#endif /* defined (__PLAYER__) */
