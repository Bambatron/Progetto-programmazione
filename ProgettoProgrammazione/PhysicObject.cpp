#include "PhysicObject.h"

PhysicObject::PhysicObject() : hitBox()
{
}

void PhysicObject::updatePhysics(float deltaTime)
{
	if (!onGround)
	{
		if (speed.y < 100)
			speed.y += deltaTime * 50;
	}

	if (onGround)
		speed.y = 0.0f;

	if (pushLeftWall || pushRightWall)
		speed.x = 0.0f;


	if (atCeiling)
		speed.y = 0.0f;
}
