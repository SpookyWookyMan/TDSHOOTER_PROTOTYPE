#pragma once

#include <iostream>
#include <vector>

#include "collision.h"

enum class TileType;
class Tile;
class TileMgr;

class MapGenerator 
{
	//Implement this over the week

	// 1. Load .png image from resources folder
	// 2. Separate each one, 'collision' will be the most important and the sole reason why this class exists.
	// 3. From the 'collision' image, we will get each 32x32 pixel cell from the image, and convert the cells which
	// are not transparent into Tiles, with 32 pixel length, scaled up as needed.
	// 4. After all is done. Separate all layes into chunks, which will then be used on the procedurally generated map.
	// 5. Figure out - after the conversion and chunks are working - the implementation of procedural generation.
	// 
	// !IMPORTANT ---> This, along with the AI, are the two hardest things on the whole project, the rest should be simple
	// 	   to implement. Make sure this is working properly and fits the vision of the game along with the AI. It doesn't matter
	//	   how long it might take, these features must be implemented and the project must be finished. 
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

	Tile(const sf::Vector2f& position, const int16_t& length, const TileType& type, const sf::Color& color);

	void draw(sf::RenderWindow*& window);

	SquareBounds& getBounds(void) { return bounds; }
};

class TileMgr 
{
public:

	static std::vector<Tile> tiles;

	static void start(void);
	static void draw(sf::RenderWindow*& window);
	static void purge(void);
};