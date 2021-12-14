#include "entity.h"

std::vector<sf::Vector2f> NPCDirector::smallSpawnLocations;
std::vector<sf::Vector2f> NPCDirector::mediumSpawnLocations;
std::vector<sf::Vector2f> NPCDirector::largeSpawnLocations;

sf::Vector2f NPCDirector::bossSpawnLoaction;

NPCManager NPCDirector::manager;

void NPCDirector::addSmallSpawn(const std::vector<sf::Vector2f>& vecs)
{
	for (auto& i : vecs) smallSpawnLocations.push_back(i);
}
void NPCDirector::addMediumSpawn(const std::vector<sf::Vector2f>& vecs)
{
	for (auto& i : vecs) mediumSpawnLocations.push_back(i);
}
void NPCDirector::addLargeSpawn(const std::vector<sf::Vector2f>& vecs)
{
	for (auto& i : vecs) largeSpawnLocations.push_back(i);
}

void NPCDirector::start(void) 
{
	addSmallSpawn({
		sf::Vector2f(WINDOW_WIDTH * 0.07f, WINDOW_HEIGHT * 0.11f),
		sf::Vector2f(WINDOW_WIDTH - WINDOW_WIDTH * 0.07f, WINDOW_HEIGHT * 0.11f),

		sf::Vector2f(WINDOW_WIDTH * 0.07f, WINDOW_HEIGHT / 2.0f),
		sf::Vector2f(WINDOW_WIDTH - WINDOW_WIDTH * 0.07f, WINDOW_HEIGHT / 2.0f),

		sf::Vector2f(WINDOW_WIDTH * 0.07f, WINDOW_HEIGHT / 4.0f),
		sf::Vector2f(WINDOW_WIDTH - WINDOW_WIDTH * 0.07f, WINDOW_HEIGHT / 4.0f),

		sf::Vector2f(WINDOW_WIDTH / 4.0f, WINDOW_HEIGHT / 4.0f),
		sf::Vector2f(WINDOW_WIDTH - WINDOW_WIDTH / 4.0f, WINDOW_HEIGHT / 4.0f)
		});
	addMediumSpawn({
		sf::Vector2f(WINDOW_WIDTH / 2 - WINDOW_WIDTH * 0.14f, WINDOW_HEIGHT / 4.0f + WINDOW_HEIGHT * 0.11f),
		sf::Vector2f(WINDOW_WIDTH - (WINDOW_WIDTH / 2 - WINDOW_WIDTH * 0.14f), WINDOW_HEIGHT / 4.0f + WINDOW_HEIGHT * 0.11f),

		sf::Vector2f(WINDOW_WIDTH / 2 - WINDOW_WIDTH * 0.28f, WINDOW_HEIGHT / 4.0f + WINDOW_HEIGHT * 0.27f),
		sf::Vector2f(WINDOW_WIDTH - (WINDOW_WIDTH / 2 - WINDOW_WIDTH * 0.28f), WINDOW_HEIGHT / 4.0f + WINDOW_HEIGHT * 0.27f)
		});
	addLargeSpawn({
		sf::Vector2f(WINDOW_WIDTH / 2 - WINDOW_WIDTH * 0.11f, WINDOW_HEIGHT / 4.0f - WINDOW_HEIGHT * 0.07f),
		sf::Vector2f(WINDOW_WIDTH / 2 + WINDOW_WIDTH * 0.11f, WINDOW_HEIGHT / 4.0f - WINDOW_HEIGHT * 0.07f)
		});

	bossSpawnLoaction = sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 4.0f - WINDOW_HEIGHT * 0.07f);
}
void NPCDirector::update(const float& dt, std::vector<Projectile>& cvec, const sf::Vector2f& playerPos, sf::RenderWindow*& window,
	Bound* playerBounds)
{
	//instantiate here

	manager.update(dt, cvec, playerPos, window, playerBounds);
}
void NPCDirector::draw(sf::RenderWindow*& window)
{
	manager.draw(window);
}