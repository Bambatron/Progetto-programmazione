#include "Character.h"

Character::Character(unsigned int hp, bool facR, float wS, float jS, float posX, float posY, float cX, float cY, float hsX, float hsY)
{
	this->hp = hp;
	this->facingRight = facR;
	this->wSpeed = wS;
	this->jSpeed = jS;
	this->pos.x = posX;
	this->pos.y = posY;
	this->collisionBox.center.x = cX;
	this->collisionBox.center.y = cY;
	this->collisionBox.halfsize.x = hsX;
	this->collisionBox.halfsize.y = hsY;

	this->currentState = CharacterState::standing;
	this->_onGround = true;
	this->hasMoved = false;
	for(unsigned int i = 0; i < 5; i++)
		this->inputs[i] = false;
}

void Character::updateCharacter(float elapsedTime, Map& map)
{
	hasMoved = false;
	switch (currentState)
	{
	case CharacterState::standing:
		speed.x = 0;
		if (!_onGround)
		{
			currentState = CharacterState::jumping;
			break;
		}
		if (isPressed(KeyInput::goRight) != isPressed(KeyInput::goLeft))
		{
			if (isPressed(KeyInput::goRight))
				speed.x = wSpeed;
			else if (isPressed(KeyInput::goLeft))
				speed.x = -wSpeed;
			currentState = CharacterState::walking;
			break;
		}
		if (isPressed(KeyInput::jump))
		{
			currentState = CharacterState::jumping;
			speed.y += jSpeed;
		}
		break;
	case CharacterState::walking:
		if (isPressed(KeyInput::goRight) == isPressed(KeyInput::goLeft))
		{
			speed.x = 0;
			currentState = CharacterState::standing;
		}
		else if (isPressed(KeyInput::goRight))
		{
			if (_pushedRWall)
			{
				speed.x = 0;
				currentState = CharacterState::standing;
			}
			else
				speed.x = wSpeed;
		}
		else if (isPressed(KeyInput::goLeft))
		{
			if (_pushedLWall)
			{
				speed.x = 0;
				currentState = CharacterState::standing;
			}
			else
				speed.x = -wSpeed;
		}
		if (isPressed(KeyInput::jump))
		{
			currentState = CharacterState::jumping;
			speed.y += jSpeed;
		}
		if (!_onGround)
		{
			currentState = CharacterState::jumping;
			break;
		}
		break;
	case CharacterState::jumping:
		if (_onGround)
		{
			speed.y = 0;
			currentState = standing;
		}
		else if (speed.y < 600)
			speed.y += 98.1*elapsedTime;
		if (isPressed(KeyInput::goRight))
		{
			if (_pushRWall)
				speed.x = 0;
			else
				speed.x = wSpeed;
		}
		else if (isPressed(KeyInput::goLeft))
		{
			if (_pushLWall)
			{
				speed.x = 0;
			}
			else
				speed.x = -wSpeed;
		}
		break;
	case CharacterState::shooting:
		break;
	}
	
	Character::move(elapsedTime);
	
	//update obj flags
	updatePhysics(elapsedTime, map);
	if (_onGround
		||_atCeiling
		||_pushLWall
		||_pushRWall)
	{
		sprite.setPosition(sf::Vector2f(pos.x, pos.y));
	}
	//Update the inputs received from game
	updateInputs(); // Prev inpts are used for sounds and animations
}

void Character::updateInputs()
{
	for (unsigned int i = 0; i < 5; i++)
	{
		prevInputs[i] = inputs[i];
	}
}

void Character::move(float elapsedTime)
{
	MovingObject::move(speed*elapsedTime);
	sprite.move(speed*elapsedTime);
	hasMoved = true;
}

void Character::draw(sf::RenderWindow & window)
{
	window.draw(sprite);
}