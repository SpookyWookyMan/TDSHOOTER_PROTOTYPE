#include "environment.h"

Tile::Tile(const sf::Vector2f& position, const int16_t& length, const TileType& type, const sf::Color& color) 
	: length(length), type(type)
{
	rect.setPosition(position);
	rect.setSize(sf::Vector2f((float)length, (float)length));
	rect.setFillColor(color);

	bounds.setPosition(position);
	bounds.setSideLength(length);
}

void Tile::draw(sf::RenderWindow*& window) 
{
	window->draw(rect);
}