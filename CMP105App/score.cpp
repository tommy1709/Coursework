#include "score.h"

score::score()
{
	texture.loadFromFile("gfx/score.png");
	setPosition(0, 0);
	setSize(sf::Vector2f(1200, 900));
	setTexture(&texture);

	if (!font.loadFromFile("font/arial.ttf"));
	{
		//std::cout << "Error loading font\n";
	}
	
	text_1.setFont(font);
	text_1.setCharacterSize(30);
	text_1.setFillColor(sf::Color::Black);
	text_1.setStyle(sf::Text::Bold);

	text_2.setFont(font);
	text_2.setCharacterSize(30);
	text_2.setFillColor(sf::Color::Black);
	text_2.setStyle(sf::Text::Bold);

	text_3.setFont(font);
	text_3.setCharacterSize(30);
	text_3.setFillColor(sf::Color::Black);
	text_3.setStyle(sf::Text::Bold);

	text_4.setFont(font);
	text_4.setCharacterSize(30);
	text_4.setFillColor(sf::Color::Black);
	text_4.setStyle(sf::Text::Bold);
}

score::~score()
{

}

void score::set_check(bool set)
{
	check = set;
}

void score::reset_score()
{
	ply_score = 0;
}

void score::update(dispTime* time, kill_count* kills)
{
	ply_score = 10000 + (kills->get_kills() * 400) - ((time->get_min() * 60) * 100) - (time->get_time() * 100); 


	if (ply_score > high_score)
	{
		high_score = ply_score;
	}

	std::string ply_sc = "Your score: " + std::to_string(ply_score);
	std::string hs = "High score: " + std::to_string(high_score);
	std::string num_kills = "Total kills: " + std::to_string(kills->get_kills());
	std::string tot_time = "Time: " + std::to_string(time->get_min()) + ":" + std::to_string(time->get_time());

	text_1.setString(ply_sc);
	text_1.setPosition(500, 400);

	text_2.setString(tot_time);
	text_2.setPosition(500, 300);

	text_3.setString(num_kills);
	text_3.setPosition(500, 350);

	text_4.setString(hs);
	text_4.setPosition(500, 550);
}

void score::render(sf::RenderWindow* window)
{
	window->draw(text_1);
	window->draw(text_2);
	window->draw(text_3);
	window->draw(text_4);
}