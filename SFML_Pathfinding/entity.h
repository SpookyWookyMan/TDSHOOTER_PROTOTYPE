#pragma once

//TODO:
// Implement player detection zone (within the npc's view; create a fov by cutting the section of a circle based on the npc's direction)
// ^ For this, an environment.h header will be created, and there different types of tyles will be managed
// The collision tile in particular will be the one used for ensuring that the player is not being seen by the AI
//  
//

#include "util.h"

class Entity;
class Projectile;
class NPC;

class ProjectileManager 
{
private:

	std::vector<Projectile> projectiles;

public:

	sf::RenderWindow* window = nullptr;

	ProjectileManager();

	void update(const float& dt);
	void draw(sf::RenderWindow*& window);

	void instantiate(const sf::Vector2f& position, Bound* owner, const float& rotation, const float& size, const float& speed = 500.0f);
	std::vector<Projectile>& getProjectiles(void) { return projectiles; }
};
class NPCManager 
{
private:

	std::vector<NPC> npcs;

public:

	enum class CollisionType { BULLET = 0, BOUND, PLAYER };

	sf::RenderWindow* window = nullptr;

	std::vector<CircularBounds>* bvec = nullptr;

	NPCManager();

	void update(const float& dt, std::vector<Projectile>& cvec, const sf::Vector2f& playerPos, sf::RenderWindow*& window);
	void draw(sf::RenderWindow*& window);

	void instantiate(const sf::Vector2f& pos, const int64_t& health);
	void projColAction(NPC& npc, const int64_t& damage);
};

class Entity 
{
protected:
	
	CircularBounds bounds;

public:

	sf::Vector2f position;
	sf::Vector2f size;

	virtual void update(const float& dt) {};
	virtual void draw(sf::RenderWindow*& window) = 0;

	CircularBounds& getBounds(void) { return bounds; }
};

class Projectile : public Entity
{
private:

	sf::Clock destroyClock;

	sf::CircleShape circ;

	CircularBounds bounds;
	Bound* owner = nullptr;

	float radius = 1.0f;
	float anglY = 0.0f;

public:

	sf::Vector2f direction;

	bool delete_ = false;

	float speed = 500.0f;
	int64_t damage = 10;

	Projectile();
	Projectile(const float& radius, const sf::Vector2f pos);
	~Projectile();

	void update(const float& dt) override;
	void draw(sf::RenderWindow*& window) override;

	void setDirection(const float& theta);
	void setOwner(Bound* owner);

	sf::CircleShape& getCirc(void) { return circ; }
	const CircularBounds& getBounds(void) const { return bounds; }
	Bound*& getOwner(void) { return owner; };
};

class NPC : public Entity
{
private:

	sf::RectangleShape rect; //temporary
	sf::Color color;

public:

	sf::Vector2f position;
	sf::Vector2f lsize;

	int64_t health = 100;
	gui::HealthBar healthBar;

	float detectionRadius = 30.0f;

	bool detectedPlayer = false;
	bool delete_ = false;

	NPC();
	NPC(const sf::Vector2f& position = sf::Vector2f(), 
        const sf::Vector2f& size = sf::Vector2f(50.f, 50.f), 							  
        const sf::Color& color = sf::Color::White);

	void update(const float& dt, const sf::Vector2f& playerPos, sf::RenderWindow*& window);
	void draw(sf::RenderWindow*& window) override;

	sf::RectangleShape& getRect(void) { return rect; }
};