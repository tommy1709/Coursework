#pragma once
#include "Framework/GameObject.h"
#include "dispTime.h"
#include "kill_count.h"

class score: public GameObject
{
	int ply_score = 0;
	int high_score = 0;
	sf::Texture texture;
	sf::Font font;
	sf::Text text_1;
	sf::Text text_2;
	sf::Text text_3;
	sf::Text text_4;
	bool check = false;

public:

	score();
	~score();
	void set_check(bool set);
	void reset_score();
	void update(dispTime* time, kill_count* kills);
	void render(sf::RenderWindow* window);

};

