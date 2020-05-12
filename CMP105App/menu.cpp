#include "menu.h"

menu::menu()
{
	texture.loadFromFile("gfx/game_menu.png");
	setTexture(&texture);
	setSize(sf::Vector2f(1200, 900));
	setPosition(0, 0);

}

menu::~menu()
{

}