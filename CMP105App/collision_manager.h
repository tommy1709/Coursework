#pragma once
#include "player.h"
#include "tiles.h"
#include "bullet_manager.h"
#include "enemy.h"

class collision_manager
{
	//player player;
	tiles tiles;
	//enemy enemy;
	bullet_manager bullets;

public:

	collision_manager();
	~collision_manager();
	void check_collisions(player* player, enemy * enemy);
};

