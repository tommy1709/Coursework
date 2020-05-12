
#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/GameObject.h"
#include "enemy_manager.h"

class kill_count
{
	int kills = 0;
	sf::Text text;
	sf::Font font;
	bool check = false;
	

public:

	kill_count();
	~kill_count();
	int get_kills();
	void set_check(bool set);
	void reset_kills();
	void update(GameObject* player, enemy_manager* enemy);
	void Render(sf::RenderWindow* window);
	
};

