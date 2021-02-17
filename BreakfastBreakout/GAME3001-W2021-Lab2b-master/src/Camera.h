#pragma once
#ifndef __CAMERA__
#define __CAMERA__

#include "DisplayObject.h"
#include "TextureManager.h"

class Camera final : public DisplayObject
{
public:
	Camera();
	~Camera();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	// getters/setters



private:

};

#endif /* defined (__PLAYER__) */