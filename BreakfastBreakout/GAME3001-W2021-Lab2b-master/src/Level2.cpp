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

	for (int i = 0; i < NUM_OF_PLATFORMS_; i++)
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

	for (int i = 0; i < NUM_OF_WALL_; i++)
	{
		m_pWall[i]->getTransform()->position = m_pCamera->getTransform()->position + m_pWall[i]->getOffset();
	}

	for (int i = 0; i < NUM_OF_FLOOR_; i++)
	{
		m_pFloor[i]->getTransform()->position = m_pCamera->getTransform()->position + m_pFloor[i]->getOffset();
	}
	for (int i = 0; i < NUM_OF_BACKGROUND_; i++)
	{
		m_pBackground[i]->getTransform()->position = m_pCamera->getTransform()->position + m_pBackground[i]->getOffset();
	}

	for (int i = 0; i < NUM_OF_HAZARDS_; i++)
	{
		m_pHazard[i]->getTransform()->position = m_pCamera->getTransform()->position + m_pHazard[i]->getOffset();
		CollisionManager::HazardCheck(m_pPlayer, m_pHazard[i], m_pCamera);
	}

	for (int i = 0; i < NUM_OF_NON_INTERACTIVE_OBJECTS_; i++)
	{
		m_pNonInteractiveObjects[i]->getTransform()->position = m_pCamera->getTransform()->position + m_pNonInteractiveObjects[i]->getOffset();
	}

	for (int i = 0; i < NUM_OF_ENEMY_; i++)
	{
		m_pEnemy[i]->getTransform()->position = m_pCamera->getTransform()->position + m_pEnemy[i]->getOffset();
		CollisionManager::HazardCheck(m_pPlayer, m_pEnemy[i], m_pCamera);
	}

	for (int i = 0; i < NUM_OF_BUTTER_; i++)
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

	for (int i = 0; i < NUM_OF_JAM_; i++)
	{
		m_pJam[i]->getTransform()->position = m_pCamera->getTransform()->position + m_pJam[i]->getOffset();

		if (m_pJam[i]->getHideTimer() > 0)
			m_pJam[i]->setOffset(glm::vec2(-1000.0f, 150.0f));
		else
		{
			switch (i)
			{
			case 0:
				m_pJam[i]->setOffset(glm::vec2(650.0f, 100.0f));
				break;
			case 1:
				m_pJam[i]->setOffset(glm::vec2(4520.0f, -250.0f));
				break;
			}
		}
		CollisionManager::JamCheck(m_pPlayer, m_pJam[i]);
	}

	/*for (int i = 0; i < NUM_OF_PLATFORMS_; i++)
	{
		CollisionManager::PlatformCheck(m_pPlayer, m_pPlatform[i], m_pCamera);

		if (m_pPlayer->getGrounded() == true)
			break;
	}*/

	if (m_pPlayer->getGrounded() == false)
	{
		for (int i = 0; i < NUM_OF_WALL_; i++)
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
		for (int i = 0; i < NUM_OF_FLOOR_; i++)
		{
			CollisionManager::PlatformCheck(m_pPlayer, m_pFloor[i], m_pCamera);

			if (m_pPlayer->getGrounded() == true)
				break;
		}

	}

	if (m_pPlayer->getButter() == false)
		m_pCamera->getRigidBody()->velocity.x = 0;


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

		TheGame::Instance()->cleanSceneState(LEVEL2);
	}

	if (m_pCamera->getTransform()->position.x < -4700)
	{
		SoundManager::Instance().load("../Assets/audio/sound effects/win.wav", "win", SOUND_SFX);
		SoundManager::Instance().playSound("win", 0);
		SoundManager::Instance().setSoundVolume(32);

		TheGame::Instance()->changeSceneState(END_SCENE);
	}


	std::cout << m_pCamera->getTransform()->position.x << ", " << m_pCamera->getTransform()->position.y << std::endl;
	std::cout << "level 2" << std::endl;

	//std::cout << m_pPlayer->getJamTime() << std::endl;

	if (m_frameCounter > 5000)
		m_frameCounter = 0;

	m_frameCounter++;

	if (m_frameCounter % 3 == 0 || m_frameCounter % 3 == 1 || m_frameCounter % 3 == 2)
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
	}

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
		if (m_pPlayer->getButter() == false)
		{
			if (EventManager::Instance().isKeyDown(SDL_SCANCODE_A))
			{
				if (m_pPlayer->getTransform()->position.x - 720.0f > m_pFloor[0]->getTransform()->position.x)
				{
					m_pCamera->getTransform()->position += glm::vec2(7, 0);
				}
				m_pPlayer->setAnimationState(PLAYER_RUN_LEFT);
				m_playerFacingRight = false;
			}
		}
		else
		{
			if (EventManager::Instance().isKeyDown(SDL_SCANCODE_A))
			{
				if (m_pPlayer->getTransform()->position.x - 720.0f > m_pFloor[0]->getTransform()->position.x)
				{
					m_pCamera->getRigidBody()->velocity.x += 0.5f;
				}
				m_pPlayer->setAnimationState(PLAYER_BUTTER_LEFT);
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
				if (m_pPlayer->getTransform()->position.x + 720.0f < m_pBackground[2]->getTransform()->position.x + 6048.0f)
				{
					m_pCamera->getTransform()->position -= glm::vec2(7, 0);
				}
				m_pPlayer->setAnimationState(PLAYER_RUN_RIGHT);
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

			else
				m_pPlayer->setAnimationState(PLAYER_IDLE_RIGHT);
		}
		else
		{
			if (m_pPlayer->getButter())
				m_pPlayer->setAnimationState(PLAYER_BUTTER_IDLE_LEFT);

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

	m_pBackground[0] = new Background(); // w6768 h900
	m_pBackground[0]->setOffset(glm::vec2(-720, -450));
	addChild(m_pBackground[0]);

	m_pBackground[1] = new Background();
	m_pBackground[1]->setOffset(glm::vec2(-720, 450));
	addChild(m_pBackground[1]);

	m_pBackground[2] = new Background();
	m_pBackground[2]->setOffset(glm::vec2(6048, -450));
	addChild(m_pBackground[2]);

	m_pBackground[3] = new Background();
	m_pBackground[3]->setOffset(glm::vec2(6048, 450));
	addChild(m_pBackground[3]);

	m_pBackground[4] = new Background();
	m_pBackground[4]->setOffset(glm::vec2(-720, -1350));
	addChild(m_pBackground[4]);

	m_pBackground[5] = new Background();
	m_pBackground[5]->setOffset(glm::vec2(6048, -1350));
	addChild(m_pBackground[5]);

	m_pNonInteractiveObjects[0] = new NonInteractiveObject("KitchenSink.png"); // w400 h200
	addChild(m_pNonInteractiveObjects[0]);
	m_pNonInteractiveObjects[0]->setOffset(glm::vec2(2335.0f, 570.0f));

	m_pHazard[0] = new Hazard("SinkHazard.png");
	addChild(m_pHazard[0]);
	m_pHazard[0]->setOffset(glm::vec2(2350.0f, 760.0f));

	m_pHazard[1] = new Hazard("ChoppingKnife.png"); // w114 h121
	addChild(m_pHazard[1]);
	m_pHazard[1]->setOffset(glm::vec2(650.0f, 468.0f));

	m_pNonInteractiveObjects[3] = new NonInteractiveObject("LongShelfBrackets.png"); // w586 h61
	addChild(m_pNonInteractiveObjects[3]);
	m_pNonInteractiveObjects[3]->setOffset(glm::vec2(1150.0f, 214.0f));

	m_pNonInteractiveObjects[4] = new NonInteractiveObject("ExtraLongShelfBrackets.png"); // w586 h61
	addChild(m_pNonInteractiveObjects[4]);
	m_pNonInteractiveObjects[4]->setOffset(glm::vec2(122.0f, 434.0f));

	m_pPlayer = new Player();
	m_pPlayer->getTransform()->position = glm::vec2(400.0f, 600.0f);
	addChild(m_pPlayer);


	for (int i = 0; i < 2; i++)
	{
		m_pEnemy[i] = new Enemy("Jello1.png", JELLO); // w72 h100
		addChild(m_pEnemy[i]);
	}
	m_pEnemy[0]->setOffset(glm::vec2(2100.0f, 660.0f));
	m_pEnemy[1]->setOffset(glm::vec2(4200.0f, -300.0f));

	for (int i = 2; i < 4; i++)
	{
		m_pEnemy[i] = new Enemy("mushroom1.png", MUSHROOM);
		addChild(m_pEnemy[i]);
	}
	m_pEnemy[2]->setOffset(glm::vec2(1000.0f, 690.0f));
	m_pEnemy[3]->setOffset(glm::vec2(2850.0f, 690.0f));




	for (int i = 0; i < NUM_OF_BUTTER_; i++)
	{
		m_pButter[i] = new Butter();
		addChild(m_pButter[i]);
	}

	for (int i = 0; i < NUM_OF_JAM_; i++)
	{
		m_pJam[i] = new Jam();
		addChild(m_pJam[i]);
	}

	//m_pButter->setOffset(glm::vec2(350.0f, 150.0f));

	m_pPlatform[0] = new Platform("LongShelf.png"); // w586 h21
	addChild(m_pPlatform[0]);
	m_pPlatform[0]->setPlatformID(0);
	m_pPlatform[0]->setOffset(glm::vec2(1150.0f, 194.0f));

	m_pNonInteractiveObjects[2] = new NonInteractiveObject("LongShelfShadow.png"); // w586 h37
	addChild(m_pNonInteractiveObjects[2]);
	m_pNonInteractiveObjects[2]->setOffset(glm::vec2(1150.0f, 215.0f));


	m_pPlatform[1] = new Platform("CuttingBoard.png"); // w274 h21
	addChild(m_pPlatform[1]);
	m_pPlatform[1]->setPlatformID(1);
	m_pPlatform[1]->setOffset(glm::vec2(550.0f, 729.0f));

	m_pPlatform[2] = new Platform("ExtraLongShelf.png"); // w1032 h20
	addChild(m_pPlatform[2]);
	m_pPlatform[2]->setPlatformID(2);
	m_pPlatform[2]->setOffset(glm::vec2(122.0f, 414.0f));

	m_pNonInteractiveObjects[5] = new NonInteractiveObject("ExtraLongShelfShadow.png"); // w1032 h30
	addChild(m_pNonInteractiveObjects[5]);
	m_pNonInteractiveObjects[5]->setOffset(glm::vec2(122, 434.0f));

	m_pWall[0] = new Wall("CrackersHorizontal.png"); //w257 h110
	addChild(m_pWall[0]);
	m_pWall[0]->setOffset(glm::vec2(1400.0f, 640.0f));

	m_pWall[1] = new Wall("CrackersVertical.png"); //w110 h257
	addChild(m_pWall[1]);
	m_pWall[1]->setOffset(glm::vec2(1471.0f, 383.0f));

	m_pWall[2] = new Wall("LargeCupboard.png"); //w778 h565
	addChild(m_pWall[2]);
	m_pWall[2]->setOffset(glm::vec2(1786.0f, -139.0f));

	m_pNonInteractiveObjects[1] = new NonInteractiveObject("LargeCupboardShadow.png"); // w778 h59
	addChild(m_pNonInteractiveObjects[1]);
	m_pNonInteractiveObjects[1]->setOffset(glm::vec2(1786.0f, 426.0f));

	//m_pWall[2] = new Wall("Pancakes.png"); // w110 h70
	//addChild(m_pWall[2]);
	//m_pWall[2]->setOffset(glm::vec2(900.0f, 690.0f));

	for (int i = 0; i < NUM_OF_FLOOR_; i++)
	{
		m_pFloor[i] = new Floor(); //w3055 h20
		addChild(m_pFloor[i]);
	}

	m_pFloor[0]->setOffset(glm::vec2(-720.0f, 750.0f));
	m_pFloor[1]->setOffset(glm::vec2(2735.0f, 750.0f));








	/*m_pFloor[1]->setOffset(glm::vec2(2150.0f, 0.0f));
	m_pFloor[2]->setOffset(glm::vec2(7300.0f, -150.0f));*/

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
