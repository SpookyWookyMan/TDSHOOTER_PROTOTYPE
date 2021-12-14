#pragma once

#include "util.h"
#include "entity.h"
#include "gui.h"

#define PSPEED_X 300.0f
#define PSPEED_Y 300.0f

#define PSIZE 50

//TODO:
// Implement bullet spread
// Add HealthBar instance

class Player
{
private:

	//temporary
	sf::RectangleShape rect;

	SquareBounds bounds;

	//gui
	gui::HealthBar healthBar;

	//collision
	//
	float autoInterval = 0.0f;
	float singleFireInterval = 0.0f;
	float collisionTime = 0.0f;

	float fireRate = 0.11f;

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
	void drawGui(sf::RenderWindow*& window);

	SquareBounds& getBounds(void) { return bounds; }
	const sf::RectangleShape& getRect(void) { return rect; }
};

