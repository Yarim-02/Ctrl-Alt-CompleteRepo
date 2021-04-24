#include "Level2.h"
#include "Game.h"
#include "EventManager.h"

// required for IMGUI
#include "imgui.h"
#include "imgui_sdl.h"
#include "Renderer.h"
#include "Util.h"

Level2::Level2()
{
	Level2::start();

	// Background Music
	SoundManager::Instance().load("../Assets/audio/soundtrack/diners_den.mp3", "BGM_table", SOUND_MUSIC);
	SoundManager::Instance().playMusic("BGM_table", -1, 0);
	SoundManager::Instance().setMusicVolume(32);
}

Level2::~Level2()
= default;

void Level2::draw()
{
	if (EventManager::Instance().isIMGUIActive())
	{
		GUI_Function();
	}

	drawDisplayList();
	SDL_SetRenderDrawColor(Renderer::Instance()->getRenderer(), 255, 255, 255, 255);
}

void Level2::update()
{
	updateDisplayList();

	m_pCamera->getTransform()->position += m_pCamera->getRigidBody()->velocity;

	/*for (int i = 0; i < _NUM_OF_PLATFORMS_; i++)
	{
		CollisionManager::PlatformCheckSide(m_pPlayer, m_pPlatform[i]);

		if (m_pPlayer->getLeft() == true || m_pPlayer->getRight() == true)
			break;
	}*/

	for (int i = 0; i < NUM_OF_PLATFORM_2_; i++)
	{
		m_pPlatform[i]->getTransform()->position = m_pCamera->getTransform()->position + m_pPlatform[i]->getOffset();

		if (CollisionManager::PlatformCheck(m_pPlayer, m_pPlatform[i], m_pCamera) == true)
		{
			if (m_pPlayer->getJam())
			{
				m_pCamera->getRigidBody()->velocity.y = 0;
				m_pPlayer->setGrounded(true);
			}

		}

		if (m_pPlayer->getGrounded() == true)
			break;
	}

	for (int i = 0; i < NUM_OF_WALL_2_; i++)
	{
		m_pWall[i]->getTransform()->position = m_pCamera->getTransform()->position + m_pWall[i]->getOffset();
	}

	for (int i = 0; i < NUM_OF_FLOOR_2_; i++)
	{
		m_pFloor[i]->getTransform()->position = m_pCamera->getTransform()->position + m_pFloor[i]->getOffset();
	}
	for (int i = 0; i < NUM_OF_BACKGROUND_2_; i++)
	{
		m_pBackground[i]->getTransform()->position = m_pCamera->getTransform()->position + m_pBackground[i]->getOffset();
	}

	for (int i = 0; i < NUM_OF_HAZARD_2_; i++)
	{
		m_pHazard[i]->getTransform()->position = m_pCamera->getTransform()->position + m_pHazard[i]->getOffset();
		CollisionManager::HazardCheck(m_pPlayer, m_pHazard[i], m_pCamera);
	}

	for (int i = 0; i < NUM_OF_NI_OBJECT_2_; i++)
	{
		m_pNonInteractiveObjects[i]->getTransform()->position = m_pCamera->getTransform()->position + m_pNonInteractiveObjects[i]->getOffset();
	}

	for (int i = 0; i < NUM_OF_ENEMY_2_; i++)
	{
		m_pEnemy[i]->getTransform()->position = m_pCamera->getTransform()->position + m_pEnemy[i]->getOffset();
		CollisionManager::HazardCheck(m_pPlayer, m_pEnemy[i], m_pCamera);
	}

	for (int i = 0; i < NUM_OF_BUTTER_2_; i++)
	{
		m_pButter[i]->getTransform()->position = m_pCamera->getTransform()->position + m_pButter[i]->getOffset();

		if (m_pButter[i]->getHideTimer() > 0)
			m_pButter[i]->setOffset(glm::vec2(-1000.0f, 150.0f));
		else
		{
			switch (i)
			{
			case 0:
				m_pButter[i]->setOffset(glm::vec2(2300.0f, -250.0f));
				break;
			case 1:
				m_pButter[i]->setOffset(glm::vec2(4520.0f, -250.0f));
				break;
			}
		}
		CollisionManager::ButterCheck(m_pPlayer, m_pButter[i]);
	}

	for (int i = 0; i < NUM_OF_JAM_2_; i++)
	{
		m_pJam[i]->getTransform()->position = m_pCamera->getTransform()->position + m_pJam[i]->getOffset();

		if (m_pJam[i]->getHideTimer() > 0)
			m_pJam[i]->setOffset(glm::vec2(-1000.0f, 683.0f));
		else
		{
			switch (i)
			{
			case 0:
				m_pJam[i]->setOffset(glm::vec2(700.0f, 683.0f));
				break;
			case 1:
				m_pJam[i]->setOffset(glm::vec2(2150.0f, 683.0f));
				break;
			}
		}
		if (CollisionManager::JamCheck(m_pPlayer, m_pJam[i]) == true)
		{
			m_pJamBar->getTransform()->position.x = 0;
		}
	}

	for (int i = 0; i < NUM_OF_COLLECTABLE_2_; i++) // Num of Collectables
	{
		m_pCollecatables[i]->getTransform()->position = m_pCamera->getTransform()->position + m_pCollecatables[i]->getOffset();
		if (CollisionManager::HazardCheck(m_pPlayer, m_pCollecatables[i], m_pCamera) == true)
		{
			SoundManager::Instance().load("../Assets/audio/sound effects/tag_collect.wav", "collectable", SOUND_SFX);
			SoundManager::Instance().playSound("collectable", 0);
			SoundManager::Instance().setSoundVolume(32);
			m_pCollecatables[i]->setOffset(glm::vec2(1000, 1000));
		}
	}

	/*for (int i = 0; i < NUM_OF_PLATFORMS_; i++)
	{
		CollisionManager::PlatformCheck(m_pPlayer, m_pPlatform[i], m_pCamera);

		if (m_pPlayer->getGrounded() == true)
			break;
	}*/

	if (m_pPlayer->getGrounded() == false)
	{
		for (int i = 0; i < NUM_OF_WALL_2_; i++)
		{
			if (CollisionManager::PlatformCheck(m_pPlayer, m_pWall[i], m_pCamera))
			{
				if (m_pPlayer->getJam())
				{
					m_pCamera->getRigidBody()->velocity.y = 0;
					m_pPlayer->setGrounded(true);
				}

			}

			if (m_pPlayer->getGrounded() == true)
				break;
		}
	}

	

	if (m_pPlayer->getGrounded() == false)
	{
		for (int i = 0; i < NUM_OF_FLOOR_2_; i++)
		{
			CollisionManager::PlatformCheck(m_pPlayer, m_pFloor[i], m_pCamera);

			if (m_pPlayer->getGrounded() == true)
				break;
		}

	}

	if (m_pPlayer->getButter() != true)
	{
		if (m_pCamera->getRigidBody()->velocity.x > 1)
		{
			std::cout << "slowing" << std::endl;
			m_pCamera->getRigidBody()->velocity.x -= 0.05;
		}			
		else if (m_pCamera->getRigidBody()->velocity.x < -1)
		{
			std::cout << "slowing" << std::endl;
			m_pCamera->getRigidBody()->velocity.x += 0.05;
		}
		else
		m_pCamera->getRigidBody()->velocity.x = 0;
	}
		
	m_pButterBar->getTransform()->position.x = m_pPlayer->getButterTime() - 500;
	if(m_pPlayer->getJam() == true)
	m_pJamBar->getTransform()->position.x -= 2.5f;

	//// Butter placement
	//for (int i = 0; i < NUM_OF_BUTTER_; i++)
	//{
	//	if (m_pButter[i]->getHideTimer() > 0)
	//		m_pButter[i]->setOffset(glm::vec2(-1000.0f, 150.0f));
	//	else
	//	{
	//		switch (i)
	//		{
	//		case 0:
	//			m_pButter[i]->setOffset(glm::vec2(2300.0f, -250.0f));
	//			break;
	//		case 1:
	//			m_pButter[i]->setOffset(glm::vec2(4520.0f, -250.0f));
	//			break;
	//		}
	//	}
	//}



	//std::cout << m_pPlayer->getCurPlatform() << std::endl;

	if (m_pPlayer->getGrounded() == true)
	{
		//std::cout << "on the ground" << std::endl;
		m_pCamera->getRigidBody()->velocity.y = 0;

	}
	else
		m_pCamera->getRigidBody()->velocity.y -= 1.0f;

	/*for (int i = 0; i < NUM_OF_HAZARDS_; i++)
	{
		CollisionManager::HazardCheck(m_pPlayer, m_pHazard[i], m_pCamera);
	}*/

	/*for (int i = 0; i < NUM_OF_ENEMY_; i++)
	{
		CollisionManager::HazardCheck(m_pPlayer, m_pEnemy[i], m_pCamera);
	}*/

	/*for (int i = 0; i < NUM_OF_BUTTER_; i++)
	{
		CollisionManager::ButterCheck(m_pPlayer, m_pButter[i]);
	}*/

	//std::cout << m_pPlayer->getGrounded() << std::endl;

	if (m_pCamera->getTransform()->position.y < -450)
	{
		SoundManager::Instance().load("../Assets/audio/sound effects/fall.mp3", "fall", SOUND_SFX);
		SoundManager::Instance().playSound("fall", 0);
		SoundManager::Instance().setSoundVolume(32);

		m_pCamera->getTransform()->position = glm::vec2(0.0f, 0.0f);
	}

	if (m_pCamera->getTransform()->position.x < -4700)
	{
		SoundManager::Instance().load("../Assets/audio/sound effects/win.wav", "win", SOUND_SFX);
		SoundManager::Instance().playSound("win", 0);
		SoundManager::Instance().setSoundVolume(32);

		TheGame::Instance()->changeSceneState(LEVEL3);
	}


	//std::cout << m_pCamera->getTransform()->position.x << ", " << m_pCamera->getTransform()->position.y << std::endl;
	std::cout << m_pPlayer->getJamTime() << std::endl;

	//std::cout << m_pPlayer->getJamTime() << std::endl;

	if (m_frameCounter > 5000)
		m_frameCounter = 0;

	m_frameCounter++;

	/*if (m_frameCounter % 3 == 0 || m_frameCounter % 3 == 1 || m_frameCounter % 3 == 2)
	{
		if (m_ChopTracker == false)
		{
			m_pHazard[1]->setOffset(m_pHazard[1]->getOffset() + (glm::vec2(0.0f, 2.0f)));

			if (m_pHazard[1]->getOffset() == glm::vec2(650.0f, 598.0f))
			{
				m_ChopTracker = true;
			}
		}
		if (m_ChopTracker == true)
		{
			m_pHazard[1]->setOffset(m_pHazard[1]->getOffset() - (glm::vec2(0.0f, 2.0f)));

			if (m_pHazard[1]->getOffset() == glm::vec2(650.0f, 468.0f))
			{
				m_ChopTracker = false;
			}
		}
	}*/

}

void Level2::clean()
{
	removeAllChildren();
}

void Level2::handleEvents()
{
	EventManager::Instance().update();

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->quit();
	}

	if (m_pPlayer->getLeft() == false)
	{
		if (m_pPlayer->getButter())
		{
			if (EventManager::Instance().isKeyDown(SDL_SCANCODE_A))
			{
				//if (m_pPlayer->getTransform()->position.x - 720.0f > m_pFloor[0]->getTransform()->position.x)
				//{
				m_pCamera->getRigidBody()->velocity.x += 0.5f;
				//}
				m_pPlayer->setAnimationState(PLAYER_BUTTER_LEFT);
				m_playerFacingRight = false;
			}

		}
		else if (m_pPlayer->getJam())
		{
			if (EventManager::Instance().isKeyDown(SDL_SCANCODE_A))
			{
				//if (m_pPlayer->getTransform()->position.x - 720.0f > m_pFloor[0]->getTransform()->position.x)
				//{
				m_pCamera->getTransform()->position += glm::vec2(7, 0);
				//}
				m_pPlayer->setAnimationState(PLAYER_JAM_LEFT);
				m_playerFacingRight = false;
			}
		}
		else
		{
			if (EventManager::Instance().isKeyDown(SDL_SCANCODE_A))
			{
				//if (m_pPlayer->getTransform()->position.x - 720.0f > m_pFloor[0]->getTransform()->position.x)
				//{
				m_pCamera->getTransform()->position += glm::vec2(7, 0);
				//}
				m_pPlayer->setAnimationState(PLAYER_RUN_LEFT);
				m_playerFacingRight = false;
			}
		}
	}
	if (m_pPlayer->getRight() == false)
	{
		if (m_pPlayer->getButter() == false)
		{
			if (EventManager::Instance().isKeyDown(SDL_SCANCODE_D))
			{
				//if (m_pPlayer->getTransform()->position.x + 720.0f < m_pBackground[2]->getTransform()->position.x + 6048.0f)
				//{
					m_pCamera->getTransform()->position -= glm::vec2(7, 0);
				//}
				if (m_pPlayer->getJam())
				{
					m_pPlayer->setAnimationState(PLAYER_JAM_RIGHT);
				}
				else
				{
					m_pPlayer->setAnimationState(PLAYER_RUN_RIGHT);
				}
				m_playerFacingRight = true;
			}
		}
		else
		{
			if (EventManager::Instance().isKeyDown(SDL_SCANCODE_D))
			{
				m_pCamera->getRigidBody()->velocity.x -= 0.5f;
				m_pPlayer->setAnimationState(PLAYER_BUTTER_RIGHT);
				m_playerFacingRight = true;
			}
		}
	}

	if (!EventManager::Instance().isKeyDown(SDL_SCANCODE_D) && !EventManager::Instance().isKeyDown(SDL_SCANCODE_A))
	{
		if (m_playerFacingRight)
		{
			if (m_pPlayer->getButter())
				m_pPlayer->setAnimationState(PLAYER_BUTTER_IDLE_RIGHT);

			else if (m_pPlayer->getJam())
				m_pPlayer->setAnimationState(PLAYER_JAM_IDLE_RIGHT);

			else
				m_pPlayer->setAnimationState(PLAYER_IDLE_RIGHT);
		}
		else
		{
			if (m_pPlayer->getButter())
				m_pPlayer->setAnimationState(PLAYER_BUTTER_IDLE_LEFT);

			else if (m_pPlayer->getJam())
				m_pPlayer->setAnimationState(PLAYER_JAM_IDLE_LEFT);

			else
				m_pPlayer->setAnimationState(PLAYER_IDLE_LEFT);
		}
	}




	if (m_pPlayer->getGrounded() == true)
	{
		if (EventManager::Instance().isKeyDown(SDL_SCANCODE_SPACE))
		{

			m_pCamera->getTransform()->position.y += 2;
			std::cout << "jumping" << std::endl;
			m_pCamera->getRigidBody()->velocity.y += 23.0f;
			m_pPlayer->setGrounded(false);

			if (m_pPlayer->getJam())
			{
				if (m_pPlayer->getLeft())
					m_pCamera->getRigidBody()->velocity.x -= 5.0f;
				if (m_pPlayer->getRight())
					m_pCamera->getRigidBody()->velocity.x += 5.0f;
			}

			SoundManager::Instance().load("../Assets/audio/sound effects/jump.wav", "jump", SOUND_SFX);
			SoundManager::Instance().playSound("jump", 0);
			SoundManager::Instance().setSoundVolume(32);
		}
	}

}

void Level2::start()
{
	// Set GUI Title
	m_guiTitle = "Play Scene";

	

	m_pBackground[1] = new Background("Level2BackgroundExtension.png", "Level2BackgroundExtension");
	m_pBackground[1]->setOffset(glm::vec2(0, 750));
	addChild(m_pBackground[1]);

	m_pBackground[2] = new Background("Level2BackgroundExtension.png", "Level2BackgroundExtension");
	m_pBackground[2]->setOffset(glm::vec2(-6768, 750));
	addChild(m_pBackground[2]);

	m_pBackground[3] = new Background("Level2BackgroundExtension.png", "Level2BackgroundExtension");
	m_pBackground[3]->setOffset(glm::vec2(-6768, -150));
	addChild(m_pBackground[3]);

	m_pBackground[4] = new Background("Level2BackgroundExtension.png", "Level2BackgroundExtension");
	m_pBackground[4]->setOffset(glm::vec2(0, -1050));
	addChild(m_pBackground[4]);

	m_pBackground[5] = new Background("Level2BackgroundExtension.png", "Level2BackgroundExtension");
	m_pBackground[5]->setOffset(glm::vec2(-6768, -1050));
	addChild(m_pBackground[5]);

	m_pBackground[0] = new Background("Level2Background.png", "Level2Background"); // w6768 h900
	m_pBackground[0]->setOffset(glm::vec2(0, -150));
	addChild(m_pBackground[0]);

	m_pNonInteractiveObjects[0] = new NonInteractiveObject("SinkHazard.png"); 
	addChild(m_pNonInteractiveObjects[0]);
	m_pNonInteractiveObjects[0]->setOffset(glm::vec2(2335.0f, 570.0f));

	m_pHazard[0] = new Hazard("Fondue.png");
	addChild(m_pHazard[0]);
	m_pHazard[0]->setOffset(glm::vec2(2535.0f, 434.0f));

	m_pHazard[1] = new Hazard("Water.png");
	addChild(m_pHazard[1]);
	m_pHazard[1]->setOffset(glm::vec2(4385.0f, 733.0f));

	//Walls
	m_pWall[0] = new Wall("VerticalMilk.png");
	addChild(m_pWall[0]);
	m_pWall[0]->setOffset(glm::vec2(1456.0f, 522.0f));
	
	m_pWall[1] = new Wall("VerticalMilk.png");
	addChild(m_pWall[1]);
	m_pWall[1]->setOffset(glm::vec2(2825.0f, 266.0f));

	m_pWall[2] = new Wall("HorizontalMilk.png");
	addChild(m_pWall[2]);
	m_pWall[2]->setOffset(glm::vec2(1785.0f, 649.0f));

	m_pWall[3] = new Wall("CrackersVertical.png");
	addChild(m_pWall[3]);
	m_pWall[3]->setOffset(glm::vec2(2825.0f, 493.0f));

	m_pWall[4] = new Wall("Cup.png");
	addChild(m_pWall[4]);
	m_pWall[4]->setOffset(glm::vec2(4690.0f, 691.0f));

	m_pWall[5] = new Wall("Flowers.png");
	addChild(m_pWall[5]);
	m_pWall[5]->setOffset(glm::vec2(4740.0f, 393.0f));

	m_pWall[6] = new Wall("PepperMill.png");
	addChild(m_pWall[6]);
	m_pWall[6]->setOffset(glm::vec2(850.0f, 248.0f));
	
	m_pWall[7] = new Wall("PepperMill.png");
	addChild(m_pWall[7]);
	m_pWall[7]->setOffset(glm::vec2(2470.0f, 248.0f));
	
	m_pWall[8] = new Wall("PepperMill.png");
	addChild(m_pWall[8]);
	m_pWall[8]->setOffset(glm::vec2(3350.0f, 248.0f));

	for (int i = 0; i < NUM_OF_COLLECTABLE_2_; i++)					// COLLECTABLES START
	{
		m_pCollecatables[i] = new Collectable();
	}
	m_pCollecatables[0]->setOffset(glm::vec2(70.0f, 70.0f)); // on small shelf
	addChild(m_pCollecatables[0]);

	m_pCollecatables[1]->setOffset(glm::vec2(1140.0f, -120.0f)); // on small cupboard
	addChild(m_pCollecatables[1]);

	m_pCollecatables[2]->setOffset(glm::vec2(3100.0f, 180.0f)); // on small cupboard
	addChild(m_pCollecatables[2]);

	m_pPlayer = new Player();
	m_pPlayer->getTransform()->position = glm::vec2(400.0f, 600.0f);
	addChild(m_pPlayer);


	for (int i = 0; i < 1; i++)
	{
		m_pEnemy[i] = new Enemy("Jello1.png", JELLO); // w72 h100
		addChild(m_pEnemy[i]);
	}
	m_pEnemy[0]->setOffset(glm::vec2(1860.0f, 559.0f));
	//m_pEnemy[1]->setOffset(glm::vec2(4200.0f, -300.0f));

	//for (int i = 2; i < 4; i++)
	//{
	//	m_pEnemy[i] = new Enemy("mushroom1.png", MUSHROOM);
	//	addChild(m_pEnemy[i]);
	//}
	//m_pEnemy[2]->setOffset(glm::vec2(1000.0f, 690.0f));
	//m_pEnemy[3]->setOffset(glm::vec2(2850.0f, 690.0f));




	for (int i = 0; i < NUM_OF_BUTTER_2_; i++)
	{
		m_pButter[i] = new Butter();
		addChild(m_pButter[i]);
	}
	m_pButter[0]->setOffset(glm::vec2(2110.0f, 683.0f));

	for (int i = 0; i < NUM_OF_JAM_2_; i++)
	{
		m_pJam[i] = new Jam();
		addChild(m_pJam[i]);
	}
	m_pJam[0]->setOffset(glm::vec2(1100.0f, 683.0f));

	m_pJam[1]->setOffset(glm::vec2(2150.0f, 683.0f));


	//m_pButter->setOffset(glm::vec2(350.0f, 150.0f));
	for (int i = 0; i < 12; i++)
	{
		m_pPlatform[i] = new Platform("SmallPlate.png"); 
		addChild(m_pPlatform[i]);
		m_pPlatform[i]->setPlatformID(i);
	}
	m_pPlatform[0]->setOffset(glm::vec2(70.0f, 140.0f));
	m_pPlatform[1]->setOffset(glm::vec2(1140.0f, -50.0f));
	m_pPlatform[2]->setOffset(glm::vec2(1150.0f, 290.0f));
	m_pPlatform[3]->setOffset(glm::vec2(1400.0f, 40.0f));
	m_pPlatform[4]->setOffset(glm::vec2(1660.0f, 100.0f));
	m_pPlatform[5]->setOffset(glm::vec2(2080.0f, 320.0f));
	m_pPlatform[6]->setOffset(glm::vec2(2440.0f, 10.0f));
	m_pPlatform[7]->setOffset(glm::vec2(3090.0f, 255.0f));
	m_pPlatform[8]->setOffset(glm::vec2(3655.0f, 545.0f));
	m_pPlatform[9]->setOffset(glm::vec2(3925.0f, 405.0f));
	m_pPlatform[10]->setOffset(glm::vec2(4285.0f, 405.0f));
	m_pPlatform[11]->setOffset(glm::vec2(4535.0f, 210.0f));

	for (int i = 12; i < 16; i++)
	{
		m_pPlatform[i] = new Platform("LargePlate.png"); 
		addChild(m_pPlatform[i]);
		m_pPlatform[i]->setPlatformID(i);
	}
	m_pPlatform[12]->setOffset(glm::vec2(460.0f,105.0f));
	m_pPlatform[13]->setOffset(glm::vec2(365.0f, 285.0f));
	m_pPlatform[14]->setOffset(glm::vec2(460.0f, 455.0f));
	m_pPlatform[15]->setOffset(glm::vec2(1840.0f, 20.0f));



	
	//m_pWall[2] = new Wall("Pancakes.png"); // w110 h70
	//addChild(m_pWall[2]);
	//m_pWall[2]->setOffset(glm::vec2(900.0f, 690.0f));

	for (int i = 0; i < NUM_OF_FLOOR_2_; i++)
	{
		m_pFloor[i] = new Floor(); //w3055 h20
		addChild(m_pFloor[i]);
	}

	m_pFloor[0]->setOffset(glm::vec2(-720.0f, 750.0f));
	m_pFloor[1]->setOffset(glm::vec2(2335.0f, 750.0f));
	   	  

	/*m_pFloor[1]->setOffset(glm::vec2(2150.0f, 0.0f));
	m_pFloor[2]->setOffset(glm::vec2(7300.0f, -150.0f));*/

	m_pJamBar = new JamBar();
	addChild(m_pJamBar);
	m_pJamBar->getTransform()->position.y = 100;
	m_pJamBar->getTransform()->position.x = -500;

	m_pButterBar = new ButterBar();
	addChild(m_pButterBar);
	m_pButterBar->getTransform()->position.y = 100;
	m_pButterBar->getTransform()->position.x = -200;

	

	m_pCamera = new Camera();
	m_pCamera->getTransform()->position = glm::vec2(0.0f, 0.0f);

}

void Level2::GUI_Function() const
{
	// Always open with a NewFrame
	ImGui::NewFrame();

	// See examples by uncommenting the following - also look at imgui_demo.cpp in the IMGUI filter
	//ImGui::ShowDemoWindow();

	ImGui::Begin("GAME3001 - Lab 2", NULL, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_MenuBar);

	//static float speed = 10.0f;
	//if(ImGui::SliderFloat("MaxSpeed", &speed, 0.0f, 100.0f))
	//{
	//	m_pSpaceShip->setMaxSpeed(speed);
	//}

	//static float acceleration_rate = 2.0f;
	//if(ImGui::SliderFloat("Acceleration Rate", &acceleration_rate, 0.0f, 50.0f))
	//{
	//	m_pSpaceShip->setAccelerationRate(acceleration_rate);
	//}

	//static float angleInRadians = m_pSpaceShip->getRotation();
	//if(ImGui::SliderAngle("Orientation Angle", &angleInRadians))
	//{
	//	m_pSpaceShip->setRotation(angleInRadians * Util::Rad2Deg);
	//}

	//static float turn_rate = 5.0f;
	//if(ImGui::SliderFloat("Turn Rate", &turn_rate, 0.0f, 20.0f))
	//{
	//	m_pSpaceShip->setTurnRate(turn_rate);
	//}
	//
	//if(ImGui::Button("Start"))
	//{
	//	m_pSpaceShip->setEnabled(true);
	//}

	//ImGui::SameLine();
	//
	//if (ImGui::Button("Reset"))
	//{
	//	m_pSpaceShip->getTransform()->position = glm::vec2(100.0f, 100.0f);
	//	m_pSpaceShip->setEnabled(false);
	//	m_pSpaceShip->getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	//	m_pSpaceShip->setRotation(0.0f); // set Angle to 0 degrees
	//	turn_rate = 5.0f;
	//	acceleration_rate = 2.0f;
	//	speed = 10.0f;
	//	angleInRadians = m_pSpaceShip->getRotation();
	//}

	//ImGui::Separator();

	//static float targetPosition[2] = { m_pTarget->getTransform()->position.x, m_pTarget->getTransform()->position.y};
	//if(ImGui::SliderFloat2("Target", targetPosition, 0.0f, 800.0f))
	//{
	//	m_pTarget->getTransform()->position = glm::vec2(targetPosition[0], targetPosition[1]);
	//	m_pSpaceShip->setDestination(m_pTarget->getTransform()->position);
	//}

	ImGui::End();

	// Don't Remove this
	ImGui::Render();
	ImGuiSDL::Render(ImGui::GetDrawData());
	ImGui::StyleColorsDark();
}
