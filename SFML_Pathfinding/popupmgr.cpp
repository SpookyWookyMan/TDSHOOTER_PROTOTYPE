#include "gui.h"

using namespace gui;

std::vector<PopUpText> PopUpTextMgr::popups;

void PopUpTextMgr::instantiate(const sf::Vector2f& position, const sf::Vector2f& direction,
	const int64_t& amount, const float& speed,
	const float& duration, const short& fadeOutDuration,
	const unsigned short& size, const sf::Color& color,
	const bool& isCritical) 
{
	PopUpText temp = PopUpText(position, direction, amount, duration, size);

	temp.fadeOutDuration = fadeOutDuration;
	temp.isCritical = isCritical;
	temp.speed = speed;
	temp.setColor(color);
	
	popups.insert(popups.begin(), temp);
}

void PopUpTextMgr::update(sf::RenderWindow*& window, const float& dt) 
{
	if (popups.size() > 0)
	{
		for (size_t i = 0; i < popups.size(); i++)
		{
			popups.at(i).update(window, dt);
			if (popups.at(i).delete_)
			{
				popups.erase(popups.begin() + i);
			}
		}
	}
}
void PopUpTextMgr::draw(sf::RenderWindow*& window) 
{
	for (auto& i : popups) 
	{
		i.draw(window);
	}
}