#include "gui.h"

using namespace gui;

PopUpText::PopUpText()
{

}
PopUpText::PopUpText(const sf::Vector2f& position, const sf::Vector2f& direction,
					 const int64_t& amount, const float& duration,
			         const unsigned short& size)
	: amount(amount), position(position), 
	  direction(direction), duration(duration),
	  charSize(size)
{
	text.setFont(res_mgr::getFont("M12"));
	text.setFillColor(sf::Color(252, 186, 3));
	text.setCharacterSize(charSize);
	
	std::string str = std::to_string(this->amount);
	text.setString(str);

	this->size = sf::Vector2f(text.getLocalBounds().width, text.getLocalBounds().height);
	text.setOrigin(sf::Vector2f(this->size.x / 2, this->size.y / 2));

	text.setPosition(this->position);
	text.setOutlineThickness(this->size.y * 0.02f);
	text.setOutlineColor(sf::Color::Black);
}

void PopUpText::update(sf::RenderWindow*& window, const float& dt)
{
	timer += dt;

	if (isCritical) direction = sf::Vector2f(0.0f, -1.0f);

	position.x += direction.x * speed * dt;
	position.y += direction.y * speed * dt;

	if (isCritical && timer < (duration * 1000) / 2) 
	{
		ctimer += dt;

		this->size = sf::Vector2f(text.getLocalBounds().width, text.getLocalBounds().height);
		text.setOrigin(sf::Vector2f(this->size.x / 2, this->size.y / 2));

		unsigned short curSize = text.getCharacterSize();
		if(ctimer * 1000 > 6 && curSize <= charSize * 2.5f) text.setCharacterSize(++curSize);
		text.setStyle(sf::Text::Bold);
	}

	text.setPosition(position);

	fade = changeF ? timer > duration : true;
	if (timer * 1000 > 1 && fade)
	{
		if (changeF) { tick = text.getFillColor().a / fadeOutDuration; changeF = false; }
		float nalpha = (text.getFillColor().a - tick < 0) ? 0 : text.getFillColor().a - tick;

		text.setFillColor(sf::Color(text.getFillColor().r,
							    text.getFillColor().g, 
							    text.getFillColor().b, 
				                nalpha));
		text.setOutlineColor(sf::Color(text.getOutlineColor().r,
						               text.getOutlineColor().g,
						               text.getOutlineColor().b,
						               nalpha));

		if(text.getFillColor().a <= 0) delete_ = true;
		timer = 0.0f;
	}
}
void PopUpText::draw(sf::RenderWindow*& window)
{
	if (!delete_)
		window->draw(text);
}