#pragma once
#ifndef __TEMP_KNOB_
#define __TEMP_KNOB_
#include "DisplayObject.h"
#include <SDL.h>
#include "UIControl.h"

template <class T>
class TempKnob
{
public:
	explicit TempKnob(const std::string& image_path = "../Assets/textures/buttons/Knob.png",
		std::string button_name = T,
		GameObjectType type = T,
		glm::vec2 position = glm::vec2(0.0f, 0.0f), bool is_centered = true);

	~TempKnob();

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


#endif /*( define __TEMP_KNOB_ ) */

template<class T>
inline TempKnob<T>::~TempKnob()
{
}

template<class T>
inline void TempKnob<T>::draw()
{
}

template<class T>
inline void TempKnob<T>::update()
{
}

template<class T>
inline void TempKnob<T>::clean()
{
}

template<class T>
inline void TempKnob<T>::setAlpha(Uint8 alpha)
{
}

template<class T>
inline void TempKnob<T>::setActive(bool value)
{
}
