#pragma once
#ifndef __PLAY_SCENE__
#define __PLAY_SCENE__
#define NUM_OF_PLATFORMS_ 11
#define NUM_OF_HAZARDS_ 3
#define NUM_OF_BUTTER_ 2
#define NUM_OF_WALL_ 3
#define NUM_OF_FLOOR_ 3
#define NUM_OF_BAD_FRUIT_ 2

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
#include "Wall.h"
#include "BadFruit.h"

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
	bool m_playerFacingRight;

	Platform* m_pPlatform[NUM_OF_PLATFORMS_];

	Wall* m_pWall[NUM_OF_WALL_];

	Floor* m_pFloor[NUM_OF_FLOOR_];

	Hazard* m_pHazard[NUM_OF_HAZARDS_];

	Butter* m_pButter[NUM_OF_BUTTER_];

	BadFruit* m_pBadFruit[NUM_OF_BAD_FRUIT_];

	Camera* m_pCamera;

	Background* m_pBackground;
	
	// UI Items
	
};

#endif /* defined (__PLAY_SCENE__) */