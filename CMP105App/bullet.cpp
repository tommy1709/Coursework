#include "bullet.h"

bullet::bullet()
{

}

bullet::~bullet()
{

}

void bullet::update(float dt)
{
	move(400* dt,0);
}