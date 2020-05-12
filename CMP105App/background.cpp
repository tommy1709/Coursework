#include "background.h"

background::background()
{
	texture.loadFromFile("gfx/game_background.png");
	setTexture(&texture);
	setPosition(0, 0);
	setSize(sf::Vector2f(10000, 900));
}

background::~background()
{

}