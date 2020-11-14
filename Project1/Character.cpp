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
void Character::updateStats()
{
	this->hp = this->hpTot;
	this->damageMin = this->damageMin;
	this->damageMax = this->damageMin * 2;
	if (this->weapon)
	{
		this->damageMin += this->weapon->getDamageMin;
		this->damageMin += this->weapon->getDamageMax;
	}
}

Character::Character(std::string name, std::string bio)
{
	this->
	this->x = 0;
	this->y = 0;
	this->name = name;
	this->weapon = nullptr;
	this->statPoints = x;
	this->updateStats();
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