#include "Character.h"

Character::Character()
{
}

void Character::move(float elapsedTime)
{
	this->sprite->move(facingRight*speed*elapsedTime, 0.f);
}
