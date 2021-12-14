#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "collision.h"

enum class TileType;
class Tile;
class TileMgr;

class EnvLoader
{

public:

	void generateTiles(const sf::Vector2f &pos, const int16_t& length, const int16_t& nTilesX, const int16_t& nTilesY);
};

enum class TileType
{
	DECOR = 0,
	COLLISION
};

class Tile 
{
private:

	sf::RectangleShape rect;

	SquareBounds bounds;

	int16_t length;

public:

	TileType type;

	Tile();
	Tile(const sf::Vector2f& position, const int16_t& length, const TileType& type, const sf::Color& color);

	void draw(sf::RenderWindow*& window);

	SquareBounds& getBounds(void) { return bounds; }
};

class TileMgr 
{
private:

	static EnvLoader envL;

public:

	static std::vector<Tile> tiles;

	static void start(void);
	static void drawDecor(sf::RenderWindow*& window);
	static void drawCol(sf::RenderWindow*& window);
	static void purge(void);
};