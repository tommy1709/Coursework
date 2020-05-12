#include "disp_text.h"

disp_text::disp_text()
{
	if (!font.loadFromFile("font/arial.ttf"));
	{
		//std::cout << "Error loading font\n";
	}
	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);

	clock.restart();
}

disp_text::~disp_text()
{

}

void disp_text::setter(bool set, int num, bool sec)
{
	val = num;
	check = set;
	second_check = sec;
}

void disp_text::restart_clock()
{
	clock.restart();
}

void disp_text::update(player* player, kill_count* kills, dispTime* dispTime)
{
	
	sec = clock.getElapsedTime();
	time = 10 - sec.asSeconds();
	
	if (time == 0)
	{
		clock.restart();
		check = false;
		kills->set_check(false);
	}
	
	if (val == 1)
	{
		pickup = "Double Kill: " + std::to_string(time);

		if (check == true)
		{
			kills->set_check(true);
		}
	}
	if (val == 2)
	{
		pickup = "Less 10 seconds";
		if (second_check == true) 
		{
			dispTime->less10(); 
			second_check = false;
		}
	}
	if (val == 3)
	{
		pickup = "Extra Life";
		if (second_check == true)
		{
			player->life();
			second_check = false;
		}
	}
	
	text.setString(pickup);
	text.setPosition(player->getPosition().x - 50, 150);
	
	
	if (text.getPosition().x >= 8850)
	{
		text.setPosition(8850, 150);
	}
	else if (text.getPosition().x <= 50)
	{
		text.setPosition(50, 150);
	}
}

void disp_text::Render(sf::RenderWindow* window)
{
	if (check == true)
	{
		window->draw(text);
	}
	
}