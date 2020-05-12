#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/GameObject.h"
#include "kill_count.h"
#include "dispTime.h"
#include "player.h"

class disp_text
{
	sf::Text text;
	sf::Font font;
	sf::Clock clock;
	sf::Time sec;
	int time = 0;
	int val = 0;
	int num = 0;
	bool check = false;
	bool second_check = false;
	std::string pickup;

public:
	
	disp_text();
	~disp_text();
	void setter(bool set, int num, bool sec);
	void update(player* player, kill_count* kills, dispTime* dispTime);
	void restart_clock();
	void Render(sf::RenderWindow* window);

};

