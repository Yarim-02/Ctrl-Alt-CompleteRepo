#pragma once
#ifndef __NEWGAME_BUTTON__
#define __NEWGAME_BUTTON__

#include "DisplayObject.h"
#include <SDL.h>
#include "UIControl.h"

class NewGameButton : public UIControl
{
public:
	explicit NewGameButton(const std::string& image_path = "../Assets/textures/newButton.png",
		std::string button_name = "newButton",
		GameObjectType type = NEWGAME_BUTTON,
		glm::vec2 position = glm::vec2(0.0f, 0.0f), bool is_centered = true);

	~NewGameButton();

	// Life Cycle Events
	void draw() override;
	void update() override;
	void clean() override;

	// button setters
	void setAlpha(Uint8 alpha);
	void setActive(bool value);

private:
	Uint8 m_alpha;
	std::string m_name;
	bool m_isCentered;
	bool m_active;
};

#endif /* defined (__NEWGAME_BUTTON__) */

