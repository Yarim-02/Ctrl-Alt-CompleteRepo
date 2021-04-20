#pragma once
#ifndef __PLAY_SCENE__
#define __PLAY_SCENE__
#define NUM_OF_PLATFORM_1_ 13
#define NUM_OF_BUTTER_1_ 1
#define NUM_OF_JAM_1_ 1
#define NUM_OF_WALL_1_ 9
#define NUM_OF_FLOOR_1_ 3
#define NUM_OF_ENEMY_1_ 4
#define NUM_OF_BACKGROUND_1_ 6
#define NUM_OF_NI_OBJECT_1_ 39
#define NUM_OF_HAZARD_1_ 18
#define NUM_OF_COLLECTABLE_1_ 4


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
#include "Collectable.h"
#include "ButterBar.h"

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

	Platform* m_pPlatform[NUM_OF_PLATFORM_1_];

	Wall* m_pWall[NUM_OF_WALL_1_];

	Floor* m_pFloor[NUM_OF_FLOOR_1_];

	Hazard* m_pHazard[NUM_OF_HAZARD_1_];

	Butter* m_pButter[NUM_OF_BUTTER_1_];

	ButterBar* m_pButterBar;

	//Jam* m_pJam[NUM_OF_JAM_1_];

	Enemy* m_pEnemy[NUM_OF_ENEMY_1_];

	Camera* m_pCamera;

	Background* m_pBackground[NUM_OF_BACKGROUND_1_];

	NonInteractiveObject* m_pNonInteractiveObjects[NUM_OF_NI_OBJECT_1_];

	Collectable* m_pCollecatables[NUM_OF_COLLECTABLE_1_];
	
	// UI Items
	int m_frameCounter;
	bool m_ChopTracker = false;
	bool m_spice1Falling = false;
	bool m_spice2Falling = false;
	bool m_spice3Falling = false;
	bool m_spice4Falling = false;
	bool m_spice5Falling = false;
	bool m_spice6Falling = false;
	bool m_spice7Falling = false;
	bool m_spice8Falling = false;
	bool m_spice9Falling = false;
	bool m_spice10Falling = false;
	bool m_spice11Falling = false;
	bool m_spice12Falling = false;
	bool m_spice13Falling = false;
	bool m_spice14Falling = false;
	
};

#endif /* defined (__PLAY_SCENE__) */