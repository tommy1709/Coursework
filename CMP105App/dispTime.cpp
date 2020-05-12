#include "dispTime.h"

dispTime::dispTime()
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

dispTime::~dispTime()
{

}

void dispTime::start_clock()
{
	clock.restart();
	stop = false;
}

void dispTime::less10()
{
	check = true;
}	

int dispTime::get_min()
{
	return min;
}

int dispTime::get_time()
{
	return time;
}

void::dispTime::stop_clock()
{
	stop = true;
}

void dispTime::update(GameObject* player)
{
	//if (stop == false)
	{
		sec = (clock.getElapsedTime());
		time = (sec.asSeconds() + num);
	}

	if (time == 60)
	{
		clock.restart();
		num = 0;
		min++;
	}

	if (check == true)
	{
		if (time < 10)
		{
			num -= time;
		}
		else
		{
			num -= 10;
		}

		check = false;
	}

	std::string game_clock = "Time " + std::to_string(min) + ":" + std::to_string(time);
	text.setString(game_clock);
	text.setPosition(player->getPosition().x - 50, 50);
	if (text.getPosition().x >= 8850)
	{
		text.setPosition(8850, 50);
	}
	else if (text.getPosition().x <= 50)
	{
		text.setPosition(50, 50);
	}
}

void dispTime::Render(sf::RenderWindow* window)
{
	window->draw(text);
}