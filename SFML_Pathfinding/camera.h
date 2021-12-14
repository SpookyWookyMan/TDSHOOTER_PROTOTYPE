#pragma once

#include "util.h"

class Camera 
{
private:

	sf::View view;

public:

	Camera();

	void bind(sf::RenderWindow *&window);
	void center(const sf::Vector2f &target);
	void setSize(const sf::Vector2f &size);
};