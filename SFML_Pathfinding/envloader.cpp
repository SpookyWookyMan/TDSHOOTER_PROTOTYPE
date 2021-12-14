#include "environment.h"

void EnvLoader::generateTiles(const sf::Vector2f &pos, const int16_t& length, const int16_t& nTilesX, const int16_t& nTilesY)
{
	//Only reading from image and drawing sf::RectangleShapes for now
	//Will change to specific sprites

	sf::RectangleShape tileRect; //temporary
	sf::Color tileColor;

	sf::Image decoration;
	sf::Image collision;
	// sf::Image dcollision;

	decoration.loadFromFile("res/images/chunks/chunk1/decor.png");
	collision.loadFromFile("res/images/chunks/chunk1/col.png");

	for (size_t i = 0; i < nTilesY; i++) //Col
		for (size_t j = 0; j < nTilesX; j++) 
		{
			sf::Color pxColor;
			sf::Color tColor = sf::Color(51, 51, 51);

			//printf("pixel x: %d; y: %d\n", 32 * i)

			pxColor = collision.getPixel(32 * j, 32 * i);
			if (pxColor.a == 0) continue;

			sf::Vector2f tpos = sf::Vector2f(pos.x + length * j, pos.y + length * i);
			Tile temp(tpos, length, TileType::COLLISION, tColor);

			TileMgr::tiles.push_back(temp);
		}
	for (size_t i = 0; i < nTilesY; i++) //Decor
		for (size_t j = 0; j < nTilesX; j++)
		{
			sf::Color pxColor;
			sf::Color tColor = sf::Color(130, 122, 94);

			//printf("pixel x: %d; y: %d\n", 32 * i)

			pxColor = decoration.getPixel(32 * j, 32 * i);
			if (pxColor.a == 0) continue;

			sf::Vector2f tpos = sf::Vector2f(pos.x + length * j, pos.y + length * i);
			Tile temp(tpos, length, TileType::DECOR, tColor);

			TileMgr::tiles.push_back(temp);
		}
}