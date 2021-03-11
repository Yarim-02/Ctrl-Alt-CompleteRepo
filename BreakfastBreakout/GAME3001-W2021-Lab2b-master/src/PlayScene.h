#pragma once
#ifndef __PLAY_SCENE__
#define __PLAY_SCENE__
#define NUM_OF_PLATFORMS_ 3
#define NUM_OF_HAZARDS_ 1
#define NUM_OF_BUTTER_ 1

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
#include "Camera.h"
#include "Background.h"

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

	Platform* m_pPlatform[NUM_OF_PLATFORMS_];

	Floor* m_pFloor;

	Hazard* m_pHazard[NUM_OF_HAZARDS_];

	Butter* m_pButter[NUM_OF_BUTTER_];

	Camera* m_pCamera;

	Background* m_pBackground;
	
	// UI Items
	
};

#endif /* defined (__PLAY_SCENE__) */