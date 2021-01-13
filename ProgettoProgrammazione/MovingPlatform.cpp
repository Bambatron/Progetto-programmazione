#include "MovingPlatform.h"

MovingPlatform::MovingPlatform()
{
}

MovingPlatform::MovingPlatform(int id, float width, float height, int sPosX, int sPosY, int fPosX, int fPosY, float speedX, float speedY, int textID)
{
	startingPosition = sf::Vector2i(sPosX, sPosY);
	finalPosition = sf::Vector2i(fPosX, fPosY);
	moving = true;

	if (fPosX < 0 || fPosY < 0)
		onTrack = false;
	else
		onTrack = true;

	type = EntityType::movingPlatform;

	hitBox.left = sPosX;
	hitBox.top = sPosY;
	hitBox.width = width;
	hitBox.height = height;
	maxSpeed = sf::Vector2f(speedX, speedY);
	
	if (onTrack)
		searchDirection();
	else
		speed = sf::Vector2f(0.0f, 0.0f);

	lastMovement = sf::Vector2f(0.0f, 0.0f);
	physical = false;
	kinematic = false;
	onGround = false;
	pushLeftWall = false;
	pushRightWall = false;
	atCeiling = false;
	moved = false;
	collided = false;

	sprite.setPosition(sPosX, sPosY);
	sprite.setSize(sf::Vector2f(width, height));
	sprite.setOutlineColor(sf::Color::Black);
	sprite.setOutlineThickness(1.0f);
	textureID = textID;
	if (textID == 0)
		sprite.setFillColor(sf::Color::Magenta);
}

void MovingPlatform::update(float deltaTime)
{
	moved = false;
	collided = false;

	if (onTrack)
	{
		if (isNearX())
			speed.x = 0;
		if (isNearY())
			speed.y = 0;

		if ((speed.x == 0) && (speed.y == 0))
		{
			//Swap startingPosition and finalPosition
			sf::Vector2i tmp = finalPosition;
			finalPosition = startingPosition;
			startingPosition = tmp;

			searchDirection();
		}
	}

	if (physical)
		updatePhysics(deltaTime);

	move(speed*deltaTime);
}

void MovingPlatform::searchDirection()
{
	//Searh on X 
	if (startingPosition.x < finalPosition.x)
		speed.x = maxSpeed.x;
	else if (startingPosition.x > finalPosition.x)
		speed.x = -maxSpeed.x;
	else if (startingPosition.x == finalPosition.x)
		speed.x = 0;

	//search on Y
	if (startingPosition.y < finalPosition.y)
		speed.y = maxSpeed.y;
	else if (startingPosition.y > finalPosition.y)
		speed.y = -maxSpeed.y;
	else if (startingPosition.y == finalPosition.y)
		speed.y = 0;
}

bool MovingPlatform::isNearX()
{
	float distance = fabs(finalPosition.x - hitBox.left);
	float error = 5.0f;

	if (distance <= error)
		return true;
	
	return false;
}

bool MovingPlatform::isNearY()
{
	float distance = fabs(finalPosition.y - hitBox.top);
	float error = 5.0f;

	if (distance <= error)
		return true;

	return false;
}