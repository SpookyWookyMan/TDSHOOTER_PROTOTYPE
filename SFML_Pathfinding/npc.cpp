#include "entity.h"

NPC::NPC() 
{

}
NPC::NPC(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color)
	: color(color), position(position)
{
	
	rect.setPosition(this->position);
	rect.setSize(size);
	
	sf::Vector2f size_ = sf::Vector2f(rect.getLocalBounds().width, rect.getLocalBounds().height);
	this->lsize = size_;

	rect.setOrigin(size_.x / 2, size_.y / 2);

	rect.setFillColor(color);

	healthBar = gui::HealthBar(sf::Vector2f(this->position.x - size_.x / 2, this->position.y - (size_.y - size_.y * 0.2f)),
		sf::Vector2f(size.x, size.y * 0.15f), health);

	bounds.setPosition(position);
	bounds.setRadius(size.x / 2);
}

void NPC::update(const float& dt, const sf::Vector2f& playerPos, sf::RenderWindow*& window)
{
	shotTimer += dt;


	float theta = util::lookAt(rect.getPosition(), playerPos);
	rect.setRotation(theta);

	if (shotTimer >= 0.8f) {
		projectileManager->instantiate(position, &bounds, theta, 5.0f, 300.0f);
		shotTimer = 0.0f;
	}


	healthBar.setPosition(sf::Vector2f(this->position.x - lsize.x / 2, this->position.y - (lsize.y - lsize.y * 0.2f)));
	healthBar.update(window, dt);
}
void NPC::draw(sf::RenderWindow*& window) 
{
	window->draw(rect);
	healthBar.draw(window);
}