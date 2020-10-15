#pragma once

#include <math.h>

#include "Drawable.h"

class Character : public Drawable
{
//Attributes
protected:
	unsigned int hp;
	bool facingRight; // 1=facing right, 0=facing left
	float speed;

	//Methods
public:
	Character();

	void setHP(unsigned int hp) { this->hp = hp; }
	void setFacing(bool direction) { this->facingRight = direction; }
	void setSpeed(float speed) { this->speed = speed; }

	unsigned int getHP() { return hp; }
	bool getFacing() { return facingRight; }
	float getSpeed() { return speed; }

	void move(float timeElapsed);
};