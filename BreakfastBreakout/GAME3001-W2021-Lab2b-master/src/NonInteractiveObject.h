#pragma once
#ifndef __NON_INTERACTIVE_OBJECT__
#define __NON_INTERACTIVE_OBJECT__

#include "DisplayObject.h"
#include "TextureManager.h"
#include <string>

class NonInteractiveObject final : public DisplayObject
{
public:
	NonInteractiveObject(std::string fileNameAndType);
	~NonInteractiveObject();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	// setters



private:
	std::string fileName;
};

#endif
