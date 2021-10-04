#include "gui.h"

using namespace gui;

Panel::Panel() 
{

}
Panel::Panel(const sf::Vector2f& size, const sf::Vector2f& pos, const sf::Color& color) 
{
	setSize(size);
	setPos(pos);
	setColor(color);
}

void Panel::update(sf::RenderWindow*& window) 
{

}
void Panel::draw(sf::RenderWindow*& window) 
{
	if (!hidden) 
	{
		window->draw(rect);
	}
}

void Panel::setPos(const sf::Vector2f& pos)
{
	rect.setPosition(pos);
}
void Panel::setSize(const sf::Vector2f& size)
{
	rect.setSize(size);
}
void Panel::setColor(const sf::Color& color)
{
	rect.setFillColor(color);
}
void Panel::setOutline(const float& thickness, const sf::Color& color)
{
	rect.setOutlineThickness(thickness);
	rect.setOutlineColor(color);
}