#pragma once
#include "Framework/Animation.h"
#include"Framework/Vector.h"
#include "Framework/GameObject.h"


class enemy: public GameObject
{
	sf::Texture texture;
	
	Animation idle;
	Animation run;
	Animation death;
	Animation* currentAnimation;

	
	float speed;
	float scale;
	bool death_check = false;
	bool check = false;
	bool complete = false;

	sf::Vector2f direction;
	sf::Vector2f target;
	sf::Vector2f start_point;
	sf::Vector2f gravity;
	sf::Vector2f stepVelocity;
	sf::Vector2f zero = sf::Vector2f(0, 0);
	int select;

public:

	enemy();
	~enemy();

	void update(float dt, int num, int target_x, int start_x);
	
	
};

