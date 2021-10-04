#pragma once

#include "util.h"
#include "entity.h"

#define PSPEED_X 200.0f
#define PSPEED_Y 200.0f

//TODO:
// Implement bullet spread
// Add HealthBar instance

class Player
{
private:

	//temporary
	sf::RectangleShape rect;

	//collision
	SquareBounds bounds;

	//
	float autoInterval = 0.0f;
	float singleFireInterval = 0.0f;
	float collisionTime = 0.0f;

	//movement
	bool movKeyPress[4] = {false, false, false, false};

	//shooting
	bool hasShot = false;
	bool isAuto = true;

	void movement(const float& dt);
	void shoot(sf::RenderWindow*& window);
	void collision(void);

public:

	ProjectileManager* projectileMgr;

	sf::Vector2f pos;
	sf::Vector2f speed;

	float speedMultiplier[4] = { 
		1.0f,
		1.0f,
		1.0f,
		1.0f
	};

	Player();

	void start(void);
	void events(sf::Event& evt);
	void update(sf::RenderWindow*& window, const float& dt);
	void draw(sf::RenderWindow*& window);

	SquareBounds& getBounds(void) { return bounds; }
	const sf::RectangleShape& getRect(void) { return rect; }
};

