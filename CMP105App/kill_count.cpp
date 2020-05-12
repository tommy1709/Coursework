#include "kill_count.h"

kill_count::kill_count()
{
	if (!font.loadFromFile("font/arial.ttf"));
	{
		
	}
	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);

}

kill_count::~kill_count()
{

}

void kill_count::set_check(bool set)
{
	check = set;
}

void kill_count::reset_kills()
{
	kills = 0;
}

int kill_count::get_kills()
{
	return kills;
}

void kill_count::update(GameObject* player, enemy_manager* enemy)
{
	if (enemy->get_check() == true)
	{
		if (check == false) { kills+= 1; enemy->set_check(false); }
		else if (check == true) { kills += 2; enemy->set_check(false); }
	}

	text.setPosition(player->getPosition().x - 50, 100);
	if (text.getPosition().x >= 8850)
	{
		text.setPosition(8850, 100);
	}
	else if (text.getPosition().x <= 50)
	{
		text.setPosition(50, 100);
	}

	std::string disp_kills = "Kills: " + std::to_string(kills);
	text.setString(disp_kills);
      
}

void kill_count::Render(sf::RenderWindow* window)
{
	window->draw(text);
}
