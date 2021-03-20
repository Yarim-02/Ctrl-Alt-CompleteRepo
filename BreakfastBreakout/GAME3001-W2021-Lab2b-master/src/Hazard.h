#pragma once
#ifndef __HAZARD__
#define __HAZARD__

#include "DisplayObject.h"
#include "TextureManager.h"
#include <string>

class Hazard final : public DisplayObject
{
public:
	Hazard(std::string fileNameAndType);
	~Hazard();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	// setters



private:
	std::string fileName;
};

#endif
