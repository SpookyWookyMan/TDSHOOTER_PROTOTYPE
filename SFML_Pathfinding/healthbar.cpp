#include "gui.h"

using namespace gui;

HealthBar::HealthBar()
{
	sf::Vector2f size = sf::Vector2f(190.0f, 10.0f);
	this->size = size;

	max = 100;
	cur = max;

	back.setSize(size);
	filr.setSize(size);
	main.setSize(size);

	back.setOutlineColor(sf::Color::Black);
	back.setOutlineThickness(size.y * 0.1f);

	back.setFillColor(sf::Color(0, 0, 0, 100));
	filr.setFillColor(sf::Color(194, 60, 8));
	main.setFillColor(sf::Color(98, 133, 103));
}
HealthBar::HealthBar(const sf::Vector2f& position, const sf::Vector2f& size, const int64_t& max)
	: size(size), max(max), cur(max)
{
	back.setSize(size);
	filr.setSize(size);
	main.setSize(size);

	back.setOutlineColor(sf::Color::Black);
	back.setOutlineThickness(size.y * 0.1f);

	back.setFillColor(sf::Color(0, 0, 0, 100));
	filr.setFillColor(sf::Color(194, 60, 8));
	main.setFillColor(sf::Color(98, 133, 103));

	back.setPosition(position);
	filr.setPosition(position);
	main.setPosition(position);
}

void HealthBar::update(sf::RenderWindow*& window, const float& dt) 
{
	float nuwidth = cur < 0 ? 0.0f : nwidth();
	timer += dt;

	sf::Vector2f newSize = sf::Vector2f(nuwidth, size.y);
	main.setSize(newSize);

	float ds = filr.getSize().x - newSize.x;
	if (timer * 1000 > 1 && ds > 0)
	{
		if (changeF) { tick = ds / 200; changeF = false; }
		float nfwidth = filr.getSize().x - tick;

		filr.setSize(sf::Vector2f(nfwidth, filr.getSize().y));

		timer = 0.0f;
	}
}
void HealthBar::draw(sf::RenderWindow*& window) 
{
	window->draw(back);
	window->draw(filr);
	window->draw(main);
}

void HealthBar::setPosition(const sf::Vector2f& pos) 
{
	back.setPosition(pos);
	filr.setPosition(pos);
	main.setPosition(pos);

	position = pos;
}
sf::Vector2f& HealthBar::getPosition(void)
{
	return position;
}
sf::Vector2f& gui::HealthBar::getSize(void)
{
	sf::Vector2f size = sf::Vector2f(back.getLocalBounds().width, back.getLocalBounds().height);

	return size;
}

void HealthBar::changeBy(const int64_t& amount) 
{
	cur += amount;
	if (cur < 0) cur = 0;

	changeF = true;
}
float& HealthBar::nwidth(void) 
{
	float _nwidth = (size.x * cur) / max;

	return _nwidth;
}