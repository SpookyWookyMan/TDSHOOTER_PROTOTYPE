#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "util.h"
#include "gui.h"
#include "player.h"
#include "entity.h"

class Program
{
private:

	//============================ Program Init Variables

	sf::RenderWindow* window;
	sf::Clock deltaClock;
	sf::Sprite inGameCursor;

	std::string win_name;
	
	//============================ Program Runtime Variables
	//gui::Button b = gui::Button(sf::Vector2f(75, 25), sf::Vector2f(25, 25), sf::Color(30, 30, 30));

	Player player;
	ProjectileManager projectileMgr;
	NPCManager npcmgr;
	//============================


public:

	Program(const std::string& win_name);
	Program();
	~Program();

	void open(void);
	void events(sf::Event& evt);
	void draw(void);
	void update(void);
	void run(void);
};
