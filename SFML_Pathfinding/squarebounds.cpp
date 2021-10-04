#include "collision.h"

SquareBounds::SquareBounds() 
{

}
SquareBounds::SquareBounds(const sf::Vector2f& position, const int16_t& side)
	:position(position), side(side)
{
	
}

bool SquareBounds::intersects(const sf::Vector2f& point) 
{
	return this->position.x + side > point.x && this->position.x < point.x
		&& this->position.y + side > point.y && this->position.y < point.y;
}
bool SquareBounds::intersects(const SquareBounds& rect) 
{
	return position.x < rect.position.x + rect.side &&
		   position.x + side > rect.position.x	    &&
		   position.y < rect.position.y + rect.side &&
		   position.y + side> rect.position.y;
}