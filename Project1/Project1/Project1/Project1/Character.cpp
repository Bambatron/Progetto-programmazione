#include "Character.h"

Character::Character(std::string name)
{
	this->movementSpeed = x,f;
}

Character::~Character()
{
}
void Character::move(const float posX, const float posY);
{
	this->sprite.move(this->movementspeed*posX, this->movementspeed*posY);

}


void Character::takeDamage()
{
	this->hp--;
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
		this->jumpheight;