#include "Knob.h"
#include <utility>
#include "TextureManager.h"


/**
 * @brief Construct a new Button:: Button object
 *
 * @param image_path
 * @param button_name
 * @param type
 * @param position
 * @param is_centered
 */
Knob::Knob(const std::string& image_path, std::string button_name, const GameObjectType type,
	const glm::vec2 position, const bool is_centered) :
	m_alpha(255), m_name(std::move(button_name)), m_isCentered(is_centered), m_active(true)
{
	TextureManager::Instance()->load(image_path, m_name);

	const auto size = TextureManager::Instance()->getTextureSize(m_name);
	setWidth(size.x);
	setHeight(size.y);
	getTransform()->position = position;
	setType(type);
}

Knob::~Knob()
= default;

void Knob::draw()
{
	// alias for x and y
	const auto x = getTransform()->position.x;
	const auto y = getTransform()->position.y;

	// draw the Knob
	TextureManager::Instance()->draw(m_name, x, y, 0, m_alpha, m_isCentered);
}

void Knob::update()
{
	//check if mouse is over the Knob
	onMouseOver();

	// check if mouse outside the Knob
	onMouseOut();

	// check if left mouse is clicked
	onLeftMouseButtonClick();
}

void Knob::clean()
{
}

/**
 * @brief sets the alpha transparency of the Knob
 * @param alpha
 * @return void
 */
void Knob::setAlpha(const Uint8 alpha)
{
	m_alpha = alpha;
}

/**
 * @brief sets the Knob active boolean
 * @return void
 */
void Knob::setActive(const bool value)
{
	m_active = value;
}
