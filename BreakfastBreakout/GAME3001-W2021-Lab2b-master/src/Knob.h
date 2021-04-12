#pragma once
#ifndef __KNOB_BUTTON__
#define __KNOB_BUTTON__

#include "DisplayObject.h"
#include <SDL.h>
#include "UIControl.h"

class Knob : public UIControl
{
public:
	explicit Knob(const std::string& image_path = "../Assets/textures/buttons/Knob.png",
		std::string button_name = "Knob",
		GameObjectType type = KNOB,
		glm::vec2 position = glm::vec2(0.0f, 0.0f), bool is_centered = true);

	~Knob();

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

#endif /* defined (__KNOB_BUTTON__) */

