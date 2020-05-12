#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/GameObject.h"
#include <iostream>


class dispTime
{
	sf::Text text;
	sf::Font font;
	sf::Clock clock;
	sf::Time sec;
	int time = 0;
	int min = 0;
	bool check = false;
	bool stop = false;
	int num = 0;

public:
	
	dispTime();
	~dispTime();
	void start_clock();
	int get_time();
	int get_min();
	void stop_clock();
	void less10();
	void update(GameObject *player);
	void Render(sf::RenderWindow* window);
};

