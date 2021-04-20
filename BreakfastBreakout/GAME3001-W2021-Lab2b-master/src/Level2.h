#pragma once
#ifndef __LEVEL2__
#define __LEVEL2__
#define NUM_OF_PLATFORM_2_ 16
#define NUM_OF_HAZARD_2_ 2
#define NUM_OF_BUTTER_2_ 1
#define NUM_OF_JAM_2_ 2
#define NUM_OF_WALL_2_ 9
#define NUM_OF_FLOOR_2_ 2
#define NUM_OF_ENEMY_2_ 1
#define NUM_OF_BACKGROUND_2_ 6
#define NUM_OF_NI_OBJECT_2_ 1
#define NUM_OF_COLLECTABLE_2_ 3

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
#include "Enemy.h"
#include "NonInteractiveObject.h"
#include "EnemyType.h"
#include "Jam.h"
#include "ButterBar.h"
#include "JamBar.h"
#include "Collectable.h"

class Level2 : public Scene
{
public:
	Level2();
	~Level2();

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

	Platform* m_pPlatform[NUM_OF_PLATFORM_2_];

	Wall* m_pWall[NUM_OF_WALL_2_];

	Floor* m_pFloor[NUM_OF_FLOOR_2_];

	Hazard* m_pHazard[NUM_OF_HAZARD_2_];

	Butter* m_pButter[NUM_OF_BUTTER_2_];

	ButterBar* m_pButterBar;
	JamBar* m_pJamBar;

	Jam* m_pJam[NUM_OF_JAM_2_];

	Enemy* m_pEnemy[NUM_OF_ENEMY_2_];

	Camera* m_pCamera;

	Background* m_pBackground[NUM_OF_BACKGROUND_2_];

	NonInteractiveObject* m_pNonInteractiveObjects[NUM_OF_NI_OBJECT_2_];

	Collectable* m_pCollecatables[NUM_OF_COLLECTABLE_2_];

	// UI Items
	int m_frameCounter;
	bool m_ChopTracker = false;

};

#endif /* defined (__LEVEL2__) */
