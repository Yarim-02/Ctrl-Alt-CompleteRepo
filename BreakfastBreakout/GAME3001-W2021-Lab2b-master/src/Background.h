#pragma once
#ifndef __BACKGROUND__
#define __BACKGROUND__

#include "DisplayObject.h"
#include "TextureManager.h"

class Background final : public DisplayObject
{
public:
	Background(std::string fileNameAndType, std::string name);
	~Background();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	// setters



private:
	std::string fileName;
};

#endif#pragma once