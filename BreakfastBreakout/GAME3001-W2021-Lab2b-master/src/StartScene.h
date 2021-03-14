#pragma once
#ifndef __START_SCENE__
#define __START_SCENE__

#include "Scene.h"
#include "Label.h"
#include "ship.h"
#include "Button.h"
#include "ResumeButton.h"
#include "LoadButton.h"
#include "QuitButton.h"
#include "NGButton.h"
#include "Background.h"
#include "MenuBG.h"
#include "EndBG.h"


class StartScene final : public Scene
{
public:
	StartScene();
	~StartScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;
	
private:
	Label* m_pStartLabel{};
	Label* m_pInstructionsLabel{};

	Ship* m_pShip{};

	//Buttons
	LoadButton* m_pLoadButton;
	QuitButton* m_pQuitButton;
	NewGameButton* m_pNewGameButton;
	ResumeButton* m_pResumeGameButton;

	//Backgrounds
	MenuBackground* m_pBackground;

};

#endif /* defined (__START_SCENE__) */