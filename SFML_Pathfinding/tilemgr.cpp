#include "environment.h"

std::vector<Tile> TileMgr::tiles;

void TileMgr::start(void) 
{
	//test
	Tile testTile = Tile(sf::Vector2f(400, 400), 100, TileType::COLLISION, sf::Color::Black);

	tiles.push_back(testTile);
}
void TileMgr::draw(sf::RenderWindow*& window) 
{
	for (auto& i : tiles) 
	{
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