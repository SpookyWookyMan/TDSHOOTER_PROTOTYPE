#include "environment.h"

EnvLoader TileMgr::envL;
std::vector<Tile> TileMgr::tiles;

void TileMgr::start(void) 
{
	//test
	//Tile testTile = Tile(sf::Vector2f(400, 400), 100, TileType::COLLISION, sf::Color::Black);
	envL.generateTiles({ 0,0 }, 50, 26, 18);

	//tiles.push_back(testTile);
}
void TileMgr::drawDecor(sf::RenderWindow*& window)
{
	for (auto& i : tiles)
	{
		if(i.type == TileType::DECOR)
			i.draw(window);
	}
}
void TileMgr::drawCol(sf::RenderWindow*& window) 
{
	for (auto& i : tiles) 
	{
		if (i.type == TileType::COLLISION)
			i.draw(window);
	}
}
void TileMgr::purge(void) 
{
	for (size_t i = 0; i < tiles.size(); i++)
	{
		tiles.erase(tiles.begin() + i);
	}
}