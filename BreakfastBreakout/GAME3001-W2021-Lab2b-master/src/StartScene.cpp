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
	m_pBackground = new MenuBackground();
	addChild(m_pBackground);

	const SDL_Color blue = { 0, 0, 255, 255 };
	m_pStartLabel = new Label("~BreakFast Breakout~", "Consolas", 80, blue, glm::vec2(750.0f, 40.0f));
	m_pStartLabel->setParent(this);
	addChild(m_pStartLabel);

	m_pInstructionsLabel = new Label("By: Crtl+Alt+Complete", "Consolas", 20, blue, glm::vec2(750.0f, 400.0f));
	m_pInstructionsLabel->setParent(this);
	addChild(m_pInstructionsLabel);

	// New Game Button
	m_pNewGameButton = new NewGameButton();
	m_pNewGameButton->getTransform()->position = glm::vec2(580.0f, 620.0f);

	// Resume Button
	m_pResumeGameButton = new ResumeButton();
	m_pResumeGameButton->getTransform()->position = glm::vec2(900.0f, 620.0f);

	// Load Button
	m_pLoadButton = new LoadButton();
	m_pLoadButton->getTransform()->position = glm::vec2(580.0f, 750.0f);

	// Quit Button
	m_pQuitButton = new QuitButton();
	m_pQuitButton->getTransform()->position = glm::vec2(900.0f, 750.0f);
	
	// Rotating Knob
	m_pKnob = new Knob();
	m_pKnob->getTransform()->position = glm::vec2(735.0f, 690.0f);

	//resume
	m_pResumeGameButton->addEventListener(CLICK, [&]()-> void
		{
			m_pResumeGameButton->setActive(false);
			TheGame::Instance()->changeSceneState(PLAY_SCENE);
		});
	m_pResumeGameButton->addEventListener(MOUSE_OVER, [&]()->void
		{
			m_pResumeGameButton->setAlpha(128);
			setEnabled(m_pKnob)
		});
	m_pResumeGameButton->addEventListener(MOUSE_OUT, [&]()->void
		{
			m_pResumeGameButton->setAlpha(255);
		});
	addChild(m_pResumeGameButton);

	//new game
	m_pNewGameButton->addEventListener(CLICK, [&]()-> void
		{
			//Go Into Saved Game State
			m_pNewGameButton->setActive(false);
			TheGame::Instance()->changeSceneState(PLAY_SCENE);
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
			//Go Into Saved Game State
			m_pLoadButton->setActive(false);
			TheGame::Instance()->changeSceneState(PLAY_SCENE);
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
			m_pQuitButton->setActive(false);
			TheGame::Instance()->changeSceneState(END_SCENE);
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

	//Knob
	m_pKnob->addEventListener(CLICK, [&]()-> void
		{
			m_pResumeGameButton->setActive(false);
			TheGame::Instance()->changeSceneState(PLAY_SCENE);
		});
	m_pKnob->addEventListener(MOUSE_OVER, [&]()->void
		{
			m_pResumeGameButton->setAlpha(128);
		});
	m_pKnob->addEventListener(MOUSE_OUT, [&]()->void
		{
			m_pResumeGameButton->setAlpha(255);
		});
	addChild(m_pKnob);
}


