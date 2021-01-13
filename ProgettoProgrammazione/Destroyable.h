#pragma once

#include "MovingPlatform.h"

//MovingPlatform that is affected by collision and is capable of being damaged

class Destroyable: public MovingPlatform
{
	//Attributes
private:
	bool alive;
	unsigned int hp;
	unsigned int points;

	//Methods
public:
	Destroyable();
	Destroyable(int id, float width = 20.0f, float height = 20.0f, int posX = 0, int posY = 0, int fPosX = -1, int fPosY = -1, float speedX = 0.0f, float speedY = 0.0f, int hp = 100, int points = 100, int textID = 0);
	//Getters
	bool isAlive() { return alive; }
	int getHP() { return hp; }
	int getPoints() { return points; }
	//Setters
	void takeDamage(unsigned int dmg);
	void setHP(unsigned int hp) { this->hp = hp; }
	void setPoints(unsigned int points) { this->points = points; }
	//Updates
	virtual void update(float deltaTime);
private:
	void death(); //On destruction give points..., notify the game of the death and release the resources if necessary
};

