#pragma once
#include <math.h>

class Character
	public Entity;
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
	int getSpeed();

protected:
	int hp;
	int hp_tot;
	int speed;
private:
	float movementSpeed;
}

