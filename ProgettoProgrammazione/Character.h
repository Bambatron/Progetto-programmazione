#pragma once

#include <cmath>

#include "Drawable.h"
#include "MovingObject.h"

//Combine together the functionalities of Drawable and MovingObject

enum CharacterState
{
	standing,
	walking,
	jumping,
	shooting,
};

enum KeyInput
{
	goRight = 0,
	goLeft = 1,
	jump = 2,
	crouch = 3,
	shoot = 4
};

class Character : public Drawable, public MovingObject
{
//Attributes
public:
	bool inputs[5]; //inputs[i] = true if corresponding KeyInput is pressed
	bool prevInputs[5];
	bool hasMoved;
protected:
	unsigned int hp;
	bool facingRight;	// 1=facing right, 0=facing left
	float wSpeed;	//Max speed on x axis
	float jSpeed;	//Max speed on y axis going up

	CharacterState currentState;

	//Methods
public:
	//Constructors
	Character(unsigned int hp=0, bool facR = false, float wS = 120.f, float jS = 240.f, float posX = 0, float posY = 0, float cX = 0, float cY = 0, float hsX = 0, float hsY = 0);
	//Getters
	unsigned int getHP() { return hp; }
	bool getFacing() { return facingRight; }
	CharacterState getCurrentState() { return currentState; }
	//Setters
	void setHP(unsigned int hp) { this->hp = hp; }
	void setFacing(bool direction) { this->facingRight = direction; }
	void setCurrentState(CharacterState state) { this->currentState = state; }

	//Updates
	void updateCharacter(float elapsedTime, Map& map);
	void updateInputs();
	
	void move(float elapsedTime);

	void draw(sf::RenderWindow& window);
protected:
	bool isPressed(KeyInput key) { return inputs[key]; }
};