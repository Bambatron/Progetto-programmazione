#include "MovingPlatform.h"

MovingPlatform::MovingPlatform(int originalPositionX, int originalPositionY, int finalPositionX, int finalPositionY, float width, float height, bool moving, float speed)
{
	this->originalPosition = sf::Vector2f(originalPositionX, originalPositionY);
	body.setPosition(originalPosition);
	body.setSize(sf::Vector2f(width, height));

	this->moving = moving;
	this->speed = speed;
	this->finalPosition = sf::Vector2f(finalPositionX, finalPositionY);
	searchDirection();
	body.setFillColor(sf::Color::Magenta);
}

void MovingPlatform::move(float elapsedTime)
{
	float oldPosX;
	float oldPosY;
	if (isNearX())
		direction.x = 0;
	if (isNearY())
		this->direction.y = 0;

	if ((direction.x == 0) && (direction.y == 0))
	{
		sf::Vector2f tmp = finalPosition;
		finalPosition = originalPosition;
		originalPosition = tmp;
		searchDirection();
	}
	oldPosX = body.getPosition().x;
	oldPosY = body.getPosition().y;
	body.move(elapsedTime*speed*direction.x, elapsedTime*speed*direction.y);
}

void MovingPlatform::searchDirection()
{
	//Searh on X 
	if (originalPosition.x < finalPosition.x)
		direction.x = 1;
	else if (originalPosition.x > finalPosition.x)
		direction.x = -1;
	else if (originalPosition.x == finalPosition.x)
		direction.x = 0;

	//search on Y
	if (originalPosition.y < finalPosition.y)
		direction.y = 1;
	else if (originalPosition.y > finalPosition.y)
		direction.y = -1;
	else if (originalPosition.y == finalPosition.y)
		direction.y = 0;
}

bool MovingPlatform::isNearX()
{
	bool result;
	float offset;
	float error = 5.f;

	if (finalPosition.x > body.getPosition().x)
		offset = finalPosition.x - body.getPosition().x;
	else
		offset = body.getPosition().x - finalPosition.x;

	if (offset <= error)
		result = true;
	else
		result = false;

	return result;
}

bool MovingPlatform::isNearY()
{
	bool result;
	float offset;
	float error = 5.f;
	
	if (finalPosition.y > body.getPosition().y)
		offset = finalPosition.y - body.getPosition().y;
	else
		offset = body.getPosition().y - finalPosition.y;

	if (offset < error)
		result = true;
	else
		result = false;

	return result;
}