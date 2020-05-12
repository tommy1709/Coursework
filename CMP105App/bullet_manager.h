#pragma once
#include "bullet.h"
#include <iostream>
#include <math.h>
#include <vector>

class bullet_manager
{
	std::vector<bullet> bullets;
	sf::Texture texture;
	sf::Vector2f spawnPoint;

public:

	bullet_manager();
	~bullet_manager();

	void spawn(float x, float y);
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);
};

