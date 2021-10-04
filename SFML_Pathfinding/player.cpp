#include "player.h"
#include <limits>

Player::Player()
{
}

void Player::start(void)
{
	rect = sf::RectangleShape({50.0f, 50.0f});
	rect.setOrigin(rect.getSize().x / 2, rect.getSize().y / 2);

	pos = sf::Vector2f( WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 );
	speed = sf::Vector2f(PSPEED_X, PSPEED_Y);

	rect.setPosition(pos);

	bounds = SquareBounds(pos, rect.getSize().x);
}
void Player::events(sf::Event& evt)
{
    if (evt.type == sf::Event::KeyPressed)
    {
		
    }
}

void Player::movement(const float& dt)
{
	movKeyPress[0] = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	movKeyPress[1] = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	movKeyPress[2] = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
	movKeyPress[3] = sf::Keyboard::isKeyPressed(sf::Keyboard::D);

	if (movKeyPress[0]) pos.y -= (speed.y * speedMultiplier[0]) * dt;
	if (movKeyPress[1]) pos.x -= (speed.x * speedMultiplier[1]) * dt;
	if (movKeyPress[2]) pos.y += (speed.y * speedMultiplier[2]) * dt;
	if (movKeyPress[3]) pos.x += (speed.x * speedMultiplier[3]) * dt;
}
void Player::shoot(sf::RenderWindow*& window)
{
	if (util::isMousePressed(LMB)) //singleFire
	{
		float theta = util::lookAt(rect.getPosition(), (sf::Vector2f)sf::Mouse::getPosition(*window));

		if (isAuto) 
		{
			if (autoInterval >= 0.1f) //Check for specific gun's cooldown timer
			{ 
				float tdev = util::randnum(-300, 300) / 100; //temporary

				projectileMgr->instantiate(pos, &bounds, theta + tdev, 5.0f, 2000.0f); 
				autoInterval = 0;
			}
		}
		else if(!hasShot)
		{
			projectileMgr->instantiate(pos, &bounds, theta, 5.0f, 2000.0f);

			hasShot = true;
		}
	}
	else 
	{
		if (singleFireInterval >= 0.3f) //Check for specific gun's cooldown timer
		{
			hasShot = false;
			singleFireInterval = 0.0f;
		}
	}
}
void Player::collision(void)
{
	for (auto& i : TileMgr::tiles)
	{
		if (i.getBounds().intersects(bounds)) 
		{
			sf::Vector2f bpos(bounds.position);
			sf::Vector2f tpos(i.getBounds().position);

			int8_t bsize = bounds.side;
			int8_t tsize = i.getBounds().side;

			float dx = 0.0f;
			float dy = 0.0f;

			bool colX = bpos.y + (bsize - bsize * 0.05f) > tpos.y && tpos.y + (tsize - tsize * 0.05f) > bpos.y;
			bool colY = bpos.x + (bsize - bsize * 0.05f) > tpos.x && tpos.x + (tsize - tsize * 0.05f) > bpos.x;

			if (colX) 
			{
				if (bpos.x < tpos.x) dx = -(bpos.x + bsize) + tpos.x;
				if (bpos.x > tpos.x) dx = (tpos.x + tsize) - bpos.x;
			}
			if (colY)
			{
				if (bpos.y < tpos.y) dy = -(bpos.y + bsize) + tpos.y;
				if (bpos.y > tpos.y) dy = (tpos.y + tsize) - bpos.y;
			}

			pos.x += dx;
			pos.y += dy;
		}
	}
}

void Player::update(sf::RenderWindow*& window, const float& dt)
{
	singleFireInterval += !isAuto && hasShot ? dt : 0.0f;
	autoInterval += dt;

	movement(dt);
	collision();
	shoot(window);

	float theta = util::lookAt(rect.getPosition(), (sf::Vector2f)sf::Mouse::getPosition(*window));
	rect.setRotation(theta);

	rect.setPosition(pos);
	bounds.setPosition(sf::Vector2f(pos.x-bounds.side / 2 , pos.y - bounds.side / 2));
}
void Player::draw(sf::RenderWindow*& window)
{
	window->draw(rect);
}
