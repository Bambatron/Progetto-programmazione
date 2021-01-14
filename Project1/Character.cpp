#include "Character.h"

Character::Character()
{

}

Character::~Character()
{

}

void Character::takeDamage()
{
	this->hp--;
}

void Character::returnHp()
{
	if ((this->hp = this->hp + x) > this->hp_max)
		this->hp = this->hp_max;

}

void Character::setHp(int hp)
{
	this->hp = hp;
}

int Character::getHp()
{
	return
		this->hp;
}

void Character::setHpTot(int hp_tot)
{
	this->hp_tot = hp_tot;
}

int Character::getHpTot()
{
	return
		this->hp_tot;
}
void Character::setSpeed(int speed)
{
	this->speed = speed;
}

int Character::getSpeed()
{
	return
		this->speed;
 
void Character::setJumpHeight(int jump_height )
{
	this->jump_height = jump_height;
}

int Character::getJumpHeight()
{
	return
		this->jump_height;
}

int Character::getAmmo()
{
	return
		this->ammo;
}

void Character::setAmmo(int n)
{
	this->ammo = n;
}

bool Character::isShooting()
{
	return shoot;
}