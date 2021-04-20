#pragma once
#ifndef __BUTTERBAR__
#define __BUTTERBAR__

#include "DisplayObject.h"
#include "TextureManager.h"

class ButterBar final : public DisplayObject
{
public:
	ButterBar();
	~ButterBar();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	// setters



private:
	std::string fileName;
};

#endif