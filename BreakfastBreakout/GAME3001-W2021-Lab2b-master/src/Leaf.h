#pragma once
#ifndef __LEAF__
#define __LEAF__

#include "DisplayObject.h"
#include "TextureManager.h"

class Leaf final : public DisplayObject
{
public:
	Leaf();
	~Leaf();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	// setters

	int getPlatformID();
	void setPlatformID(int IDNum);


private:
	int m_platformID;
	std::string m_fileName;

};

#endif /* defined (__PLAYER__) */
