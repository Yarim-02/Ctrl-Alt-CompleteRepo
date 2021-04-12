#pragma once
#ifndef __LOAD_BUTTON__
#define __LOAD_BUTTON__

#include "DisplayObject.h"
#include <SDL.h>
#include "UIControl.h"

class LoadButton : public UIControl
{
public:
<<<<<<< Updated upstream
	explicit LoadButton(const std::string& image_path = "../Assets/textures/buttons/LoadButton2-Off.png",
=======
	explicit LoadButton(const std::string& image_path = "../Assets/textures/Buttons/loadButton.png",
>>>>>>> Stashed changes
		std::string button_name = "loadButton",
		GameObjectType type = START_BUTTON,
		glm::vec2 position = glm::vec2(0.0f, 0.0f), bool is_centered = true);

	~LoadButton();

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

#endif /* defined (__LOAD_BUTTON__) */

