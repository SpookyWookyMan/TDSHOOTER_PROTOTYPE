#include "collision.h"

CircularBounds::CircularBounds(const sf::Vector2f& position, const float& radius)
	: position(position), radius(radius)
{
	
}

bool CircularBounds::intersects(const CircularBounds& obj) 
{
	float dy = obj.position.y - this->position.y;
	float dx = obj.position.x - this->position.x;

	float dist = sqrt(pow(dy, 2) + pow(dx, 2));

	if (this->radius + obj.radius > dist) 
	{
		return true;
	}

	return false;
}