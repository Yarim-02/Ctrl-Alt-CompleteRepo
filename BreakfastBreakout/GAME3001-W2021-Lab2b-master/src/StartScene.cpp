#include "StartScene.h"
#include <algorithm>
#include "Game.h"
#include "glm/gtx/string_cast.hpp"
#include "EventManager.h"

StartScene::StartScene()
{
	StartScene::start();
}

StartScene::~StartScene()
= default;

void StartScene::draw()
{
	drawDisplayList();
}

void StartScene::update()
{
	updateDisplayList();
}

void StartScene::clean()
{
	removeAllChildren();
}

void StartScene::handleEvents()
{
	EventManager::Instance().update();

	// Keyboard Events
	if(EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->quit();
	}

	if(EventManager::Instance().isKeyDown(SDL_SCANCODE_1))
	{
		TheGame::Instance()->changeSceneState(PLAY_SCENE);
	}
}

void StartScene::start()
{
	const SDL_Color blue = { 0, 0, 255, 255 };
<<<<<<< Updated upstream
	m_pStartLabel = new Label("START SCENE", "Consolas", 80, blue, glm::vec2(400.0f, 40.0f));
=======
	m_pStartLabel = new Label("~BreakFast Breakout~", "Consolas", 85, blue, glm::vec2(750.0f, 40.0f));
>>>>>>> Stashed changes
	m_pStartLabel->setParent(this);
	addChild(m_pStartLabel);

	m_pInstructionsLabel = new Label("Press 1 to Play", "Consolas", 40, blue, glm::vec2(400.0f, 120.0f));
	m_pInstructionsLabel->setParent(this);
	addChild(m_pInstructionsLabel);

<<<<<<< Updated upstream

	m_pShip = new Ship();
	m_pShip->getTransform()->position = glm::vec2(400.0f, 300.0f); 
	addChild(m_pShip); 

	// Start Button
	m_pStartButton = new Button();
	m_pStartButton->getTransform()->position = glm::vec2(400.0f, 400.0f); 

	m_pStartButton->addEventListener(CLICK, [&]()-> void
	{
		m_pStartButton->setActive(false);
		TheGame::Instance()->changeSceneState(PLAY_SCENE);
	});
	
	m_pStartButton->addEventListener(MOUSE_OVER, [&]()->void
	{
		m_pStartButton->setAlpha(128);
	});

	m_pStartButton->addEventListener(MOUSE_OUT, [&]()->void
	{
		m_pStartButton->setAlpha(255);
	});
	addChild(m_pStartButton);

	
=======
	// New Game Button
	m_pNewGameButton = new NewGameButton();
	m_pNewGameButton->getTransform()->position = glm::vec2(600.0f, 700.0f);

	// Resume Button
	m_pResumeGameButton = new ResumeButton();
	m_pResumeGameButton->getTransform()->position = glm::vec2(600.0f, 850.0f);

	// Load Button
	m_pLoadButton = new LoadButton();
	m_pLoadButton->getTransform()->position = glm::vec2(910.0f, 700.0f);

	// Quit Button
	//
	m_pQuitButton = new QuitButton();
	m_pQuitButton->getTransform()->position = glm::vec2(910.0f,  850.0f);

	//resume
	m_pResumeGameButton->addEventListener(CLICK, [&]()-> void
		{
			//make spinner point to this button

			//switch button to on state texture(which ever color everone likes)

			//Go Into Game State when spinner center has been pressed


			//m_pNewGameButton->setActive(false);
			//TheGame::Instance()->changeSceneState(PLAY_SCENE); // go to rules scene
		});
	m_pResumeGameButton->addEventListener(MOUSE_OVER, [&]()->void
		{
			m_pResumeGameButton->setAlpha(128);
		});
	m_pResumeGameButton->addEventListener(MOUSE_OUT, [&]()->void
		{
			m_pResumeGameButton->setAlpha(255);
		});
	addChild(m_pResumeGameButton);

	//new game
	m_pNewGameButton->addEventListener(CLICK, [&]()-> void
		{
			//make spinner point to this button

			//switch button to on state texture(which ever color everone likes)

			//Go Into Game State when spinner center has been pressed


			//m_pNewGameButton->setActive(false);
			//TheGame::Instance()->changeSceneState(PLAY_SCENE); // Start new game
		});
	m_pNewGameButton->addEventListener(MOUSE_OVER, [&]()->void
		{
			m_pNewGameButton->setAlpha(128);
		});
	m_pNewGameButton->addEventListener(MOUSE_OUT, [&]()->void
		{
			m_pNewGameButton->setAlpha(255);
		});
	addChild(m_pNewGameButton);

	//load
	m_pLoadButton->addEventListener(CLICK, [&]()-> void
		{
			//make spinner point to this button

			//switch button to on state texture(which ever color everone likes)

			//Go Into Game State when spinner center has been pressed


			//m_pNewGameButton->setActive(false);
			//TheGame::Instance()->changeSceneState(PLAY_SCENE); // load saved file
		});
	m_pLoadButton->addEventListener(MOUSE_OVER, [&]()->void
		{
			m_pLoadButton->setAlpha(128);
		});
	m_pLoadButton->addEventListener(MOUSE_OUT, [&]()->void
		{
			m_pLoadButton->setAlpha(255);
		});
	addChild(m_pLoadButton);

	//Quit
	m_pQuitButton->addEventListener(CLICK, [&]()-> void
		{
			//make spinner point to this button

			//switch button to on state texture(which ever color everone likes)

			//Go Into Game State when spinner center has been pressed


			//m_pNewGameButton->setActive(false);
			//TheGame::Instance()->changeSceneState(END_SCENE);
		});
	m_pQuitButton->addEventListener(MOUSE_OVER, [&]()->void
		{
			m_pQuitButton->setAlpha(128);
		});
	m_pQuitButton->addEventListener(MOUSE_OUT, [&]()->void
		{
			m_pQuitButton->setAlpha(255);
		});
	addChild(m_pQuitButton);
>>>>>>> Stashed changes
}

