#include "entity.h"

ProjectileManager::ProjectileManager() 
{

}

void ProjectileManager::update(const float& dt)
{
	for (size_t i = 0; i < projectiles.size(); i++)
	{
		projectiles.at(i).update(dt);
		if (projectiles.at(i).delete_)
		{
			projectiles.erase(projectiles.begin() + i);
		}
	}
}
void ProjectileManager::draw(sf::RenderWindow*& window)
{
	for (auto& i : projectiles)
	{
		window->draw(i.getCirc());
	}
}

void ProjectileManager::instantiate(const sf::Vector2f& position, Bound* owner, const float& rotation, const float& size, const float& speed)
{
	Projectile proj = Projectile(size, position);

	proj.setDirection(rotation);
	proj.speed = speed;

	proj.setOwner(owner);

	projectiles.push_back(proj);
}