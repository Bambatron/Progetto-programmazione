#include "Character.h"

Character::~Character()
{
}

void Character::takeDamage()
{
	this->hp--;
}

void Character::move(const float posX, const float posY)
{
}

void Character::setHp(int hp)
{
	this->hp = hp;
}

int Character::getHp()
{
	return this->hp;
}

void Character::setHpTot(int hp_tot)
{
	this->hp_tot = hp_tot;
}

int Character::getHpTot()
{
	return this->hp_tot;
}

void Character::setSpeed(int speed)
{
	this->speed = speed;
}

float Character::getSpeed()
{
	return this->speed;
}

void Character::setJumpHeight(int jump_height)
{
	this->jump_height = jump_height;
}

float Character::getJumpHeight()
{
	return this->jump_height;
}