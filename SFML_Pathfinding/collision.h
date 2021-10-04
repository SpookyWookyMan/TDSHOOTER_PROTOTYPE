#pragma once

#include <SFML/Graphics.hpp>

class Bound {
public: 

	bool operator== (Bound& obj) { return &(*this) == &(obj); };
	bool operator!= (Bound& obj) { return &(*this) != &(obj); };
};

class CircularBounds : public Bound
{
public:

	sf::Vector2f position;

	float radius = 0.0f;

	CircularBounds(const sf::Vector2f& position = sf::Vector2f(), const float& radius = 1.0f);

	void setPosition(const sf::Vector2f& position) { this->position = position; }
	void setRadius(const float& radius) { this->radius = radius; }

	bool intersects(const CircularBounds& obj);

	
};

class SquareBounds : public Bound
{
public:

	sf::Vector2f position;

	int16_t side;

	SquareBounds();
	SquareBounds(const sf::Vector2f& position, const int16_t& side);

	void setPosition(const sf::Vector2f& position) { this->position = position; }
	void setSideLength(const int16_t& side) { this->side = side; }

	bool intersects(const sf::Vector2f& point);
	bool intersects(const SquareBounds& rect);
};