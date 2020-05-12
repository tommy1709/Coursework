#include "pause.h"

pause::pause()
{
	texture.loadFromFile("gfx/pause.png");
	//setPosition(300, 150);
	setTexture(&texture);
	setSize(sf::Vector2f(500, 600));

}

pause::~pause()
{

}