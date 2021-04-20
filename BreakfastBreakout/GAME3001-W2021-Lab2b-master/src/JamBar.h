#pragma once
#ifndef __JAMBAR__
#define __JAMBAR__

#include "DisplayObject.h"
#include "TextureManager.h"

class JamBar final : public DisplayObject
{
public:
	JamBar();
	~JamBar();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	// setters



private:
	std::string fileName;
};

#endif
