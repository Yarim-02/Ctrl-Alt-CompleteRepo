#pragma once
#ifndef __QUIT_BUTTON__
#define __QUIT_BUTTON__

#include "DisplayObject.h"
#include <SDL.h>
#include "UIControl.h"

class QuitButton : public UIControl
{
public:
	explicit QuitButton(const std::string& image_path = "../Assets/textures/quitButton.png",
		std::string button_name = "quitButton",
		GameObjectType type = QUIT_BUTTON,
		glm::vec2 position = glm::vec2(0.0f, 0.0f), bool is_centered = true);

	~QuitButton();

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

#endif /* defined (__QUIT_BUTTON__) */

