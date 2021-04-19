#pragma once
#ifndef __RESUME_BUTTON__
#define __RESUME_BUTTON__

#include "DisplayObject.h"
#include <SDL.h>
#include "UIControl.h"

class ResumeButton : public UIControl
{
public:
	explicit ResumeButton(const std::string& image_path = "../Assets/textures/buttons/ResumeButton-On.png",
		std::string button_name = "resumeButton",
		GameObjectType type = RESUME_BUTTON,
		glm::vec2 position = glm::vec2(0.0f, 0.0f), bool is_centered = true);

	~ResumeButton();

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

#endif /* defined (__RESUME_BUTTON__) */

