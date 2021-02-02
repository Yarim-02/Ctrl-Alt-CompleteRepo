#pragma once
#ifndef __PLAY_SCENE__
#define __PLAY_SCENE__
#define _NUM_OF_PLATFORMS_ 3

#include "Scene.h"
#include "Button.h"
#include "Label.h"
#include "Obstacle.h"
#include "SpaceShip.h"
#include "Target.h"
#include "Player.h"
#include "Platform.h"
#include "Floor.h"
#include "Hazard.h"
#include "Butter.h"

class PlayScene : public Scene
{
public:
	PlayScene();
	~PlayScene();

	// Scene LifeCycle Functions
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

private:
	// IMGUI Function
	void GUI_Function() const;
	std::string m_guiTitle;
	
	glm::vec2 m_mousePosition;

	Player* m_pPlayer;

	Platform* m_pPlatform[_NUM_OF_PLATFORMS_];

	Floor* m_pFloor;

	Hazard* m_pHazard;

	Butter* m_pButter;
	
	// UI Items
	
};

#endif /* defined (__PLAY_SCENE__) */