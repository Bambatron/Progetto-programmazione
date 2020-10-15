#pragma once

#include "Platform.h"

class Destroyable: public Platform
{
	//Attributes
private:
	bool alive;
	unsigned int hp;
	unsigned int points;

	//Methods
public:
	Destroyable(int posX = 0, int posY = 0, float width = 50.f, float height = 25.f, bool alive = true, int hp = 100, int points = 100);

	void takeDamage(unsigned int dmg);
	
	bool isAlive() { return alive; }

private:
	void death(); //On destruction give points..., notify the game of the death and release the resources if necessary
};

