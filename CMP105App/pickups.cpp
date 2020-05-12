#include "pickups.h"

pickups::pickups()
{
	
}

pickups::~pickups()
{

}

void pickups::update(float dt)
{
	move(10 * dt, 0);
}