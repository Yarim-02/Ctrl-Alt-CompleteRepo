#include "StartScene.h"
#include <algorithm>
#include "Game.h"
#include "glm/gtx/string_cast.hpp"
#include "EventManager.h"

StartScene::StartScene()
{
	StartScene::start();

	// Menu Music
	SoundManager::Instance().load("../Assets/audio/soundtrack/menu.mp3", "menu", SOUND_MUSIC);
	SoundManager::Instance().playMusic("menu", -1, 0);
	SoundManager::Instance().setMusicVolume(32);
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
	m_pResumeGameButton->getTransform()->position = glm::vec2(-1000.0f, 620.0f);

	// Load Button
	m_pLoadButton = new LoadButton();
	m_pLoadButton->getTransform()->position = glm::vec2(-1080.0f, 750.0f);

	// Quit Button
	m_pQuitButton = new QuitButton();
	m_pQuitButton->getTransform()->position = glm::vec2(900.0f, 620.0f);
	
	// Rotating Knob
	m_pKnob = new Knob();
	m_pKnob->getTransform()->position = glm::vec2(735.0f, 690.0f);

	//resume
	m_pResumeGameButton->addEventListener(CLICK, [&]()-> void
		{
			m_pResumeGameButton->setActive(false);
			SoundManager::Instance().load("../Assets/audio/sound effects/pop.wav", "pop", SOUND_SFX);
			SoundManager::Instance().playSound("pop", 0);
			SoundManager::Instance().setSoundVolume(32);
			TheGame::Instance()->changeSceneState(LEVEL2);
		});
	m_pResumeGameButton->addEventListener(MOUSE_OVER, [&]()->void
		{
			m_pResumeGameButton->setAlpha(128);
			setEnabled(m_pKnob);
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
			SoundManager::Instance().load("../Assets/audio/sound effects/pop.wav", "pop", SOUND_SFX);
			SoundManager::Instance().playSound("pop", 0);
			SoundManager::Instance().setSoundVolume(32);
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
			SoundManager::Instance().load("../Assets/audio/sound effects/pop.wav", "pop", SOUND_SFX);
			SoundManager::Instance().playSound("pop", 0);
			SoundManager::Instance().setSoundVolume(32);
			TheGame::Instance()->changeSceneState(LEVEL3);
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
			SoundManager::Instance().load("../Assets/audio/sound effects/pop.wav", "pop", SOUND_SFX);
			SoundManager::Instance().playSound("pop", 0);
			SoundManager::Instance().setSoundVolume(32);
			TheGame::Instance()->quit();
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
			m_pKnob->setActive(false);
			SoundManager::Instance().load("../Assets/audio/sound effects/pop.wav", "pop", SOUND_SFX);
			SoundManager::Instance().playSound("pop", 0);
			SoundManager::Instance().setSoundVolume(32);
			TheGame::Instance()->changeSceneState(LEVEL2);
		});
	m_pKnob->addEventListener(MOUSE_OVER, [&]()->void
		{
			m_pKnob->setAlpha(128);
		});
	m_pKnob->addEventListener(MOUSE_OUT, [&]()->void
		{
			m_pKnob->setAlpha(255);
		});
	addChild(m_pKnob);
}


