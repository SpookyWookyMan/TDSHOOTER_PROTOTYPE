#include "entity.h"

NPCManager::NPCManager() 
{
}

void NPCManager::update(const float& dt, std::vector<Projectile>& cvec, const sf::Vector2f& playerPos, 
	sf::RenderWindow*& window) //might change to:
{							   //const std::vector<CircularBounds>* cvec[]
	if (npcs.size() > 0)	   //for different collision entities
	{
		for (size_t i = 0; i < npcs.size(); i++)
		{
			npcs.at(i).update(dt, playerPos, window);
			for (auto& j : cvec)
			{
				if (npcs.at(i).getBounds().intersects(j.getBounds())
					&& *j.getOwner() != npcs.at(i).getBounds())
				{
					npcs.at(i).detectedPlayer = true; //temporary

					float xdev = static_cast<float>(util::randnum(-3000, 3000)) / 10000;
					float ydev = static_cast<float>(util::randnum(-3000, 3000)) / 10000;

					unsigned short size = util::randnum(25, 35); //temporary

					float duration = 0.4f;
					short fduration = 75;

					j.damage = util::randnum(12, 25); //temporary

					bool crit = util::randnum(0, 100) < 5; //temporary
					if (crit) 
					{
						j.damage *= 2;

						duration *= 1.5f;
						fduration *= 2;
					}

					sf::Color clr = crit ? sf::Color(171, 64, 22) : sf::Color(252, 186, 3);
					
					sf::Vector2f pdir = sf::Vector2f(j.direction.x + xdev,
												     j.direction.y + ydev);

					sf::Vector2f ppos = sf::Vector2f(npcs.at(i).getRect().getPosition().x,
						npcs.at(i).getRect().getPosition().y);

					gui::PopUpTextMgr::instantiate(ppos, pdir, j.damage, 155.0f, duration, fduration, size, clr, crit);
					projColAction(npcs.at(i), j.damage); //only bullets for the time being
					j.delete_ = true;
				}
			}
			if (npcs.at(i).delete_)
			{
				npcs.erase(npcs.begin() + i);
			}
		}
	}
}
void NPCManager::draw(sf::RenderWindow*& window) 
{
	for (auto& i : npcs) 
	{
		i.draw(window);
	}
}

void NPCManager::instantiate(const sf::Vector2f& pos, const int64_t& health)
{
	//temporary, must implement more variables

	NPC tmp = NPC(pos);

	tmp.health = health;
	tmp.healthBar = gui::HealthBar(sf::Vector2f(tmp.position.x - tmp.lsize.x / 2, tmp.position.y - (tmp.lsize.y - tmp.lsize.y * 0.2f)),
		sf::Vector2f(tmp.lsize.x, tmp.lsize.y * 0.15f), health);

	npcs.push_back(tmp);
}

void NPCManager::projColAction(NPC& npc, const int64_t& damage)
{
	npc.health -= damage;
	npc.healthBar.changeBy(-damage);
	//other damage feedbacks
	
	//
	if (npc.health <= 0) npc.delete_ = true;
}