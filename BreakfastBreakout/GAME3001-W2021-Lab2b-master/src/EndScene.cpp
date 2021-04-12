#include "EndScene.h"
#include <algorithm>
#include "Game.h"
#include "glm/gtx/string_cast.hpp"
#include "EventManager.h"

EndScene::EndScene()
{
	EndScene::start();
}

EndScene::~EndScene()
= default;

void EndScene::draw()
{
	drawDisplayList();
}

void EndScene::update()
{
	updateDisplayList();
}

void EndScene::clean()
{
	removeAllChildren();
}

void EndScene::handleEvents()
{
	EventManager::Instance().update();

	// Button Events
	m_pRestartButton->update();

	// Keyboard Events
	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->quit();
	}

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_1))
	{
		TheGame::Instance()->changeSceneState(PLAY_SCENE);
	}
}

void EndScene::start()
{

	m_pEndBackground = new EndBackground();
	addChild(m_pEndBackground);

	const SDL_Color blue = { 0, 0, 255, 255 };
	m_label = new Label("Game Over", "Consolas", 80, blue, glm::vec2(400.0f, 40.0f));
	m_label->setParent(this);
	addChild(m_label);

	m_label = new Label("Would You Like To Play Again?", "Consolas", 20, blue, glm::vec2(290.0f, 350.0f));
	m_label->setParent(this);
	addChild(m_label);

	// Restart Button
	m_pRestartButton = new Button("../Assets/textures/restartButton.png", "restartButton", RESTART_BUTTON);
	m_pRestartButton->getTransform()->position = glm::vec2(290.0f, 420.0f);
	m_pRestartButton->addEventListener(CLICK, [&]()-> void
	{
		m_pRestartButton->setActive(false);
		TheGame::Instance()->changeSceneState(START_SCENE);
	});

	m_pRestartButton->addEventListener(MOUSE_OVER, [&]()->void
	{
		m_pRestartButton->setAlpha(128);
	});

	m_pRestartButton->addEventListener(MOUSE_OUT, [&]()->void
	{
		m_pRestartButton->setAlpha(255);
	});

	addChild(m_pRestartButton);

	// Quit Button
	m_pQuitButton = new QuitButton();
	m_pQuitButton->getTransform()->position = glm::vec2(290.0f, 490.0f);
	m_pQuitButton->addEventListener(CLICK, [&]()-> void
		{
			m_pQuitButton->setActive(false);
			TheGame::Instance()->changeSceneState(START_SCENE);
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
}
