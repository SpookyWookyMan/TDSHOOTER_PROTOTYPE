#include "entity.h"

Projectile::Projectile() {}
Projectile::Projectile(const float& radius, const sf::Vector2f pos)
{
	position = pos;

	circ.setRadius(radius);
	circ.setPosition(position);
	circ.setOrigin(sf::Vector2f(radius, radius));

	bounds.setRadius(radius);
	bounds.setPosition(position);
}
Projectile::~Projectile() { }

void Projectile::update(const float& dt)
{
	position.x += direction.x * speed * dt;
	position.y += direction.y * speed * dt;

	circ.setPosition(position);
	bounds.setPosition(position);

	sf::Vector2f pointUp = sf::Vector2f(position.x, (position.y - radius * 2));
	sf::Vector2f pointLeft = sf::Vector2f((position.x - radius * 2), position.y);
	sf::Vector2f pointDown = sf::Vector2f(position.x, (position.y + radius * 2));
	sf::Vector2f pointRight = sf::Vector2f((position.x + radius * 2), position.y);

	for (auto& i : TileMgr::tiles) 
	{
		bool up = i.getBounds().intersects(pointUp);
		bool left = i.getBounds().intersects(pointLeft);
		bool down = i.getBounds().intersects(pointDown);
		bool right = i.getBounds().intersects(pointRight);

		if (up || down) 
		{ 
			if (anglY > 65.0f) direction.y *= -1;
			else delete_ = true;
		}
		else if (left || right) 
		{ 
			if (anglY < 35.0f) direction.x *= -1;
			else delete_ = true;
		}
	}

	float lifeTime = (!delete_) ? destroyClock.getElapsedTime().asSeconds() : 0.0f;
	if (lifeTime > 1.0f) 
	{
		delete_ = true;
		lifeTime = 0;
	}
}
void Projectile::setOwner(Bound* owner)
{
	this->owner = owner;
}

void Projectile::draw(sf::RenderWindow*& window)  
{
	window->draw(circ);
}

void Projectile::setDirection(const float& theta)
{
	float rad = (theta * PI) / 180.0f;

	direction = sf::Vector2f(1.0f, 0.0f);

	float x = direction.x * cos(rad) - direction.y * sin(rad);
	float y = direction.x * sin(rad) + direction.y * cos(rad);

	direction = sf::Vector2f(x, y);

	anglY = util::vecAngle(sf::Vector2f(0, 1), direction);
}
