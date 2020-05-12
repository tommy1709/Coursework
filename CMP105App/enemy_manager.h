#pragma once
#include "enemy.h"
#include <iostream>
#include <math.h>
#include <vector>
#include "player.h"
#include "Framework/Collision.h"
#include "Framework/GameObject.h"
#include "Framework/Animation.h"


class enemy_manager
{
	std::vector<enemy> enemys;
	sf::Vector2f spawnpoint;
	sf::Texture texture;
	bool check = false;
	float death_xpos = 0;
	float death_ypos = 0;
	int rand_num = 0;
	

public:

	enemy_manager();
	~enemy_manager();

	void spawn();
	void update(float dt);
	void collisionCheck(player* player);
	void render(sf::RenderWindow* window);
	void collision_resp_player(GameObject* collider, int num);
	bool get_check();
	void set_check(bool set);
	float get_xpos();
	float get_ypos();
	int get_rand();
	void set_rand(int rand);
};


