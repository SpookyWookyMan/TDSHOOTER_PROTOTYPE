#include "util.h"

bool util::isMousePressed(const unsigned& mcode)
{
	switch (mcode) 
	{
		case 0: return sf::Mouse::isButtonPressed(sf::Mouse::Left);   break;
		case 1: return sf::Mouse::isButtonPressed(sf::Mouse::Right);  break;
		case 2: return sf::Mouse::isButtonPressed(sf::Mouse::Middle); break;
	}

	return false;
}
bool util::isMouseOver(const sf::FloatRect& rect, sf::RenderWindow*& window) {
	sf::Vector2f pos(sf::Mouse::getPosition(*window));
	return rect.contains(pos);
}

float& util::vecMag(const sf::Vector2f vec)
{
	float mag = sqrt(vec.x * vec.x + vec.y * vec.y);

	return mag;
}
float& util::vecDot(const sf::Vector2f& v1, const sf::Vector2f& v2)
{
	float dot = v1.x * v2.x + v1.y * v2.y;

	return dot;
}
float& util::vecAngle(const sf::Vector2f& v1, const sf::Vector2f& v2)
{
	float mag1 = vecMag(v1);
	float mag2 = vecMag(v2);

	float dot = abs(vecDot(v1, v2));

	float cost = dot / (mag1 * mag2);
	float theta = (acos(cost) * 180)/PI;

	return theta;
}

sf::Vector2f& util::vectDelta(const sf::Vector2f& v1, const sf::Vector2f& v2)
{
	sf::Vector2f delta (abs(v2.x - v1.x), abs(v2.y - v1.y));

	return delta;
}

float& util::pointDist(const sf::Vector2f& p1, const sf::Vector2f& p2)
{
	float dist = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));

	return dist;
}

float& util::lookAt(const sf::Vector2f& position ,const sf::Vector2f& point)
{

	float dx = point.x - position.x;
	float dy = point.y - position.y;

	float theta = (atan2(dy, dx) * 180.0f) / PI;

	return theta;
}

int util::randnum(int min, int max)
{
	int result = 0, low = 0, high = 0;

	if (min < max) {
		low = min;
		high = max + 1;
	}
	else {
		low = max + 1;
		high = min;
	}

	result = (rand() % (high - low)) + low;
	return result;
}