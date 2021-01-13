#pragma once

#include <cmath>

#include "Entity.h"

//Entity that react to inputs be it auto-generated(Alien) or user-made(Player)

enum CharacterState: int
{
	standing = 0,
	walking = 1,
	jumping = 2,
};

#define NINPUTS 6
enum KeyInput: int
{
	goRight = 0,
	goLeft = 1,
	jump = 2,
	crouch = 3,
	shoot = 4,
	use = 5
};

class Character : public Entity
{
//Attributes
public:
	bool inputs[NINPUTS]; //inputs[i] = true if corresponding KeyInput is pressed
protected:
	unsigned int hp;
	CharacterState currentState;
	//Flag
	bool facingRight;	// 1=facing right, 0=facing left
	//Methods
public:
	//Constructors
	Character();
	//Getters
	bool isPressed(KeyInput key) { return inputs[key]; }
	unsigned int getHP() { return hp; }
	CharacterState getCurrentState() { return currentState; }
	bool isFacingRight() { return facingRight; }
	//Setters
	void resetInputs();
	void receiveInput(KeyInput key, bool value = true) { inputs[key] = value; }
	void setHP(unsigned int hp) { this->hp = hp; }
	void setCurrentState(CharacterState state) { this->currentState = state; }
	void setFacing(bool direction) { this->facingRight = direction; }
	//Transformers
	//Updates
	virtual void update(float deltaTime);
	void updateCharacter();
	virtual void shoot();
	virtual void ability();
};