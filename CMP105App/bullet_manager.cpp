#include "bullet_manager.h"

bullet_manager::bullet_manager()
{
	texture.loadFromFile("gfx/rainbow_bullet.png");
	

	for (int i = 0; i < 100; i++)
	{
		bullets.push_back(bullet());
		bullets[i].setAlive(false);
		bullets[i].setTexture(&texture);
		bullets[i].setSize(sf::Vector2f(25, 25));
	}
}

bullet_manager::~bullet_manager()
{

}

void bullet_manager::update(float dt)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			bullets[i].update(dt);
		}
	}
	deathCheck();
}

void bullet_manager::spawn(float x, float y)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (!bullets[i].isAlive())
		{
			bullets[i].setAlive(true);
			bullets[i].setPosition(x, y);
			return;
		}
	}
}

void bullet_manager::deathCheck()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			if (bullets[i].getPosition().y < 0) { bullets[i].setAlive(false); }
		}
	}
}

void bullet_manager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			window->draw(bullets[i]);
		}
	}
}