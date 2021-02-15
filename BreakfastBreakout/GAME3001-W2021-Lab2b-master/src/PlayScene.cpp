#include "PlayScene.h"
#include "Game.h"
#include "EventManager.h"

// required for IMGUI
#include "imgui.h"
#include "imgui_sdl.h"
#include "Renderer.h"
#include "Util.h"

PlayScene::PlayScene()
{
	PlayScene::start();
}

PlayScene::~PlayScene()
= default;

void PlayScene::draw()
{
	if(EventManager::Instance().isIMGUIActive())
	{
		GUI_Function();
	}

	drawDisplayList();
	SDL_SetRenderDrawColor(Renderer::Instance()->getRenderer(), 255, 255, 255, 255);
}

void PlayScene::update()
{
	updateDisplayList();

	/*for (int i = 0; i < _NUM_OF_PLATFORMS_; i++)
	{
		CollisionManager::PlatformCheckSide(m_pPlayer, m_pPlatform[i]);

		if (m_pPlayer->getLeft() == true || m_pPlayer->getRight() == true)
			break;
	}*/

	for (int i = 0; i < _NUM_OF_PLATFORMS_; i++)
	{

		

		CollisionManager::PlatformCheck(m_pPlayer, m_pPlatform[i]);
		
		if (m_pPlayer->getGrounded() == true)
			break;
	}

	

	if (m_pPlayer->getGrounded() == false)
	{
		CollisionManager::PlatformCheck(m_pPlayer, m_pFloor);
		
	}

	

	//std::cout << m_pPlayer->getCurPlatform() << std::endl;

	if (m_pPlayer->getGrounded() == true)
	{
		//std::cout << "on the ground" << std::endl;
		m_pPlayer->getRigidBody()->velocity.y = 0;		
		
	}
	CollisionManager::HazardCheck(m_pPlayer, m_pHazard);
	CollisionManager::ButterCheck(m_pPlayer, m_pButter);

	

}

void PlayScene::clean()
{
	removeAllChildren();
}

void PlayScene::handleEvents()
{
	EventManager::Instance().update();

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->quit();
	}

	if (m_pPlayer->getTransform()->position.x > 0)
	{
		if (m_pPlayer->getButter() == false)
		{
			if (EventManager::Instance().isKeyDown(SDL_SCANCODE_A))
			{
				m_pPlayer->getTransform()->position -= glm::vec2(5, 0);
			}
		}
		else
		{
			if (EventManager::Instance().isKeyDown(SDL_SCANCODE_A))
			{
				m_pPlayer->getRigidBody()->velocity.x -= 0.3f;
			}
		}
	}

	if (m_pPlayer->getTransform()->position.x < (800 - m_pPlayer->getWidth()))
	{
		if (m_pPlayer->getButter() == false)
		{
			if (EventManager::Instance().isKeyDown(SDL_SCANCODE_D))
			{
				m_pPlayer->getTransform()->position += glm::vec2(5, 0);
			}
		}
		else
		{
			if (EventManager::Instance().isKeyDown(SDL_SCANCODE_D))
			{
				m_pPlayer->getRigidBody()->velocity.x += 0.3f;
			}
		}
	}
	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_1))
	{
		m_pPlayer->getTransform()->position = glm::vec2(100.0f, 0.0f);
	}

	

	if (m_pPlayer->getGrounded() == true)
	{
		if (EventManager::Instance().isKeyDown(SDL_SCANCODE_SPACE))
		{
			
			m_pPlayer->getTransform()->position.y -= 2;
			std::cout << "jumping" << std::endl;
			m_pPlayer->getRigidBody()->velocity.y -= 25;
			m_pPlayer->setGrounded(false);
		}
	}

}

void PlayScene::start()
{
	// Set GUI Title
	m_guiTitle = "Play Scene";


	m_pPlayer = new Player();
	m_pPlayer->getTransform()->position = glm::vec2(50.0f, 0.0f);
	addChild(m_pPlayer);

	m_pHazard = new Hazard();
	m_pHazard->getTransform()->position = glm::vec2(650.0f, 400.0f);
	addChild(m_pHazard);

	m_pButter = new Butter();
	m_pButter->getTransform()->position = glm::vec2(300.0f, 75.0f);
	addChild(m_pButter);

	for (int i = 0; i < _NUM_OF_PLATFORMS_; i++)
	{
		m_pPlatform[i] = new Platform();
		addChild(m_pPlatform[i]);
		m_pPlatform[i]->setPlatformID(i);
	}
	
	m_pPlatform[0]->getTransform()->position = glm::vec2(50.0f, 350.0f);
	m_pPlatform[1]->getTransform()->position = glm::vec2(100.0f, 350.0f);
	m_pPlatform[2]->getTransform()->position = glm::vec2(150.0f, 500.0f);

	m_pFloor = new Floor();
	m_pFloor->getTransform()->position = glm::vec2(0.0f, 550.0f);
	addChild(m_pFloor);
	
}

void PlayScene::GUI_Function() const
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
