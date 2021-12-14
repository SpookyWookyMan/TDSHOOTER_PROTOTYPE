#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <math.h>
#include <functional>
#include <time.h>
#include <random>
#include <cstdarg>
#include <stdio.h>

#include "gui.h"
#include "res.h"
#include "collision.h"
#include "environment.h"

#define WINDOW_WIDTH 1400
#define WINDOW_HEIGHT 900

#define LOG(...) {printf(__VA_ARGS__);}

#define LMB 0
#define RMB 1
#define MMB 2

#define COLOR_NONE sf::Color::Black

#define PI 3.14159265359f

namespace util
{

	bool isMousePressed(const unsigned& mcode);
	bool isMouseOver(const sf::FloatRect& rect, sf::RenderWindow*& window);

	float& vecMag(const sf::Vector2f vec);
	float& vecDot(const sf::Vector2f& v1, const sf::Vector2f& v2);
	float& vecAngle(const sf::Vector2f& v1, const sf::Vector2f& v2);
	sf::Vector2f& vectDelta(const sf::Vector2f& v1, const sf::Vector2f& v2);

	float& pointDist(const sf::Vector2f& p1, const sf::Vector2f& p2);

	float& lookAt(const sf::Vector2f& position, const sf::Vector2f& point);
	int randnum(int min, int max);
}