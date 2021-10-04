#include "gui.h"

using namespace gui;

Button::Button() : color(sf::Color::Black)
{
	rect.setSize(sf::Vector2f(150.0f, 50.0f));
	rect.setPosition(sf::Vector2f());
	rect.setFillColor(color);

	rect.setOutlineColor(sf::Color::White);
	rect.setOutlineThickness(rect.getSize().x * 0.02f);
}
Button::Button(const sf::Vector2f& size, const sf::Vector2f& pos, const sf::Color& color)
	: color(color)
{
	rect.setSize(size);
	rect.setPosition(pos);
	rect.setFillColor(color);

	rect.setOutlineColor(sf::Color::White);
	rect.setOutlineThickness(size.x * 0.02f);
}

void Button::update(sf::RenderWindow*& window)
{
	bool mouseOver = util::isMouseOver(rect.getGlobalBounds(), window);

	if (mouseOver)
	{
		if(colormo == COLOR_NONE) rect.setFillColor(sf::Color(color.r + 30, color.g + 30, color.b + 30));
		else rect.setFillColor(sf::Color(colormo));

		funcmo();
		if (util::isMousePressed(LMB)) 
		{
			if (colormc == COLOR_NONE) rect.setFillColor(sf::Color(color.r + 60, color.g + 60, color.b + 60));
			else rect.setFillColor(sf::Color(colormc));

			if (!mouseClicked) funcmc();
			mouseClicked = true;

			return;
		}

		if (mouseClicked) funcmr();
		mouseClicked = false;
	}
	else 
	{
		rect.setFillColor(color);

		mouseClicked = false;
	}
}
void Button::draw(sf::RenderWindow*& window)
{
	if (!hidden) 
	{
		window->draw(rect);
		window->draw(text);
	}
}

void Button::setText(const std::string& string)
{
	textString = string;
	text.setFont(res_mgr::getFont("Arial"));
	text.setString(textString);
	text.setCharacterSize(floor(rect.getSize().y * 0.7f));

	sf::Vector2f bounds = sf::Vector2f(text.getLocalBounds().width, text.getLocalBounds().height);
	sf::Vector2f rsize = rect.getSize();
	sf::Vector2f rpos = rect.getPosition();

	text.setOrigin(sf::Vector2f(bounds.x / 2, bounds.y / 2));
	text.setPosition(sf::Vector2f(rpos.x + rsize.x / 2, rpos.y + rsize.y / 4 + bounds.y / 12));
}