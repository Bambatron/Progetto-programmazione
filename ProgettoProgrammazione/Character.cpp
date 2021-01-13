#include "Character.h"

Character::Character()
{
	for (unsigned int i = 0; i < NINPUTS; i++)
	{
		this->inputs[i] = false;
	}

	facingRight = true;
}

void Character::resetInputs()
{
	for (unsigned int i = 0; i < NINPUTS; i++)
	{
		inputs[i] = false;
	}
}

void Character::update(float deltaTime)
{
	moved = false;
	collided = false;

	updateCharacter();
	
	if (physical)
		updatePhysics(deltaTime);
	
	move(speed*deltaTime);

	for (unsigned int  i = 0; i < NINPUTS; i++)
	{
		inputs[i] = false;
	}
}

void Character::updateCharacter()
{
	switch (currentState)
	{
	case standing:
		//To walking
		if (inputs[goRight] != inputs[goLeft])
		{
			currentState = walking;
			if (inputs[goRight] && !pushRightWall)
				speed.x = maxSpeed.x;
			else if (!pushLeftWall)
				speed.x = -maxSpeed.x;
		}
		else
		{
			speed.x = 0.0f;
		}
		//To jumping
		if (!onGround)
			currentState = jumping;
		else if (inputs[jump])
		{
			currentState = jumping;
			speed.y = -maxSpeed.y;
		}
		//Shoot or use ability (shooting has priority over ability by design)
		if (inputs[KeyInput::shoot])
			shoot();
		else if (inputs[use])
			ability();
		break;

	case walking:
		//To standing
		if ((pushLeftWall && speed.x < 0)
			||(pushRightWall && speed.x > 0)
			|| inputs[goRight] == inputs[goLeft])
		{
			currentState = standing;
			speed.x = 0;
		}
		//To jumping
		if (!onGround)
			currentState = jumping;
		else if (inputs[jump])
		{
			currentState = jumping;
			speed.y = -maxSpeed.y;
		}
		//Shoot or use ability (shooting has priority over ability by design)
		if (inputs[KeyInput::shoot])
			shoot();
		else if (inputs[use])
		{
			ability();
			currentState = standing;
		}
		break;
	case jumping:
		//Check if bonks head
		if (atCeiling  && speed.y < 0)
			speed.y = 0;
		//To standing	
		if (onGround && speed.y > 0)
		{
			speed.y = 0;
			currentState = standing;
		}
		//Countinue x-axis movement
		if (inputs[goRight] != inputs[goLeft])
		{
			if (inputs[goRight] && !pushRightWall)
				speed.x = maxSpeed.x;
			else if (!pushLeftWall)
				speed.x = -maxSpeed.x;
		}
		else
		{
			speed.x = 0.0f;
		}
		break;
	}
}

void Character::shoot()
{
	std::cout << "Character::shoot()\n";
}

void Character::ability()
{
	std::cout << "Character::ability()\n";
}

