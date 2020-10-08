#pragma once

#include <math.h>

#include "Drawable.h"

class Character : public Drawable
{
public:
	Character();
	virtual ~Character();

	//Functions
	void move(const float posX, const float posY);
	
	void setHp(int hp);
	void setHpTot(int hp_tot);
	void setSpeed(int speed);
	void setJumpHeight(int jump_height);
	void takeDamage();

	int getHp();
	int getHpTot();
	float getSpeed();
	float getJumpHeight();

protected:
	int hp;
	int hp_tot;
	int speed;
	float movementSpeed;
	float jump_height;
};