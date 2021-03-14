#include "MenuBG.h"
#include "TextureManager.h"

MenuBackground::MenuBackground()
{
	TextureManager::Instance()->load("../Assets/textures/Menu3.png", "MenuBG");

	auto size = TextureManager::Instance()->getTextureSize("MenuBG");
	setWidth(size.x);
	setHeight(size.y);

	getTransform()->position = glm::vec2(100.0f, 000.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(MENU_BACKGROUND);


}

MenuBackground::~MenuBackground()
= default;

void MenuBackground::draw()
{
	TextureManager::Instance()->draw("MenuBG",
		getTransform()->position.x, getTransform()->position.y, 0, 255, false);

}

void MenuBackground::update()
{
}

void MenuBackground::clean()
{
}