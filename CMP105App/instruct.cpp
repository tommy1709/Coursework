#include "instruct.h"

instruct::instruct()
{
	texture.loadFromFile("gfx/instructions.png");
	setPosition(0, 0);
	setSize(sf::Vector2f(1200, 900));
	setTexture(&texture);
}

instruct::~instruct()
{

}