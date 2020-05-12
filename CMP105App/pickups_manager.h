#pragma once
#include "Framework/Collision.h"
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
#include "pickups.h"
#include "disp_text.h"
#include <math.h>
#include "kill_count.h"

class pickups_manager
{
	std::vector<pickups> pkups;
	sf::Texture texture_1;
	sf::Texture texture_2;
	sf::Texture texture_3;
	bool check = false;
	int val;


public:

	pickups_manager();
	~pickups_manager();

	void spawn(int num, float x, float y);
	void update(float dt);
	void collisionCheck(GameObject* player, disp_text* text);
	void render(sf::RenderWindow* window);
	//void collision_resp_player(GameObject* collider, int num);
	//bool get_check();
	//void set_check(bool set);
};

