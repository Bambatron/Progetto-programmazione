#include "MovingObject.h"

AABB::AABB(float cx, float cy, float hsx, float hsy)
{
	this->center.x = cx;
	this->center.y = cy;
	this->halfsize.x = hsx;
	this->halfsize.y = hsy;
}

AABB::AABB(sf::Vector2f c, sf::Vector2f hs)
{
	this->center = c;
	this->halfsize = hs;
}

void AABB::move(sf::Vector2f offset)
{
	center.x += offset.x;
	center.y += offset.y;
}

MovingObject::MovingObject(sf::Vector2f pos, sf::Vector2f center, sf::Vector2f hs)
{
	this->pos = pos;
	this->collisionBox.center = center;
	this->collisionBox.halfsize = hs;
}

MovingObject::MovingObject(float posX, float posY, float cX, float cY, float hsX, float hsY)
{
	this->pos.x = posX;
	this->pos.y = posY;
	this->collisionBox.center.x = cX;
	this->collisionBox.center.y = cY;
	this->collisionBox.halfsize.x = hsX;
	this->collisionBox.halfsize.y = hsY;
}

void MovingObject::updatePhysics(float elapsedTime, Map& map)
{	
	//Update old data
	oldPos = pos;
	oldSpeed = speed;
	
	//Chek left wall
	_pushedLWall = _pushLWall;
	sf::Vector2f leftUp(collisionBox.center.x - collisionBox.halfsize.x, collisionBox.center.y - collisionBox.halfsize.y);
	sf::Vector2f leftdown(collisionBox.center.x - collisionBox.halfsize.x, collisionBox.center.y + collisionBox.halfsize.y);
	float wallX = 0;
	if (speed.x <= 0
		&& map.hasLeftWall(leftUp, leftdown, &wallX))
	{
		pos.x = wallX;
		collisionBox.center.x = wallX + collisionBox.halfsize.x;
		speed.x = 0;
		_pushLWall = true;
	}
	else
		_pushLWall = false;

	//Chek right wall
	_pushedRWall = _pushRWall;
	sf::Vector2f rightUp(collisionBox.center.x + collisionBox.halfsize.x, collisionBox.center.y - collisionBox.halfsize.y);
	sf::Vector2f rightDown(collisionBox.center.x + collisionBox.halfsize.x, collisionBox.center.y + collisionBox.halfsize.y);
	wallX = 0;
	if (speed.x >= 0
		&& map.hasRightWall(rightUp, rightDown, &wallX))
	{
		pos.x = wallX - 2 * collisionBox.halfsize.x;
		collisionBox.center.x = wallX - collisionBox.halfsize.x;
		speed.x = 0;
		_pushRWall = true;
	}
	else
		_pushRWall = false;

	//Check ceiling
	_wasAtCeiling = _atCeiling;
	sf::Vector2f upperLeft(collisionBox.center.x - collisionBox.halfsize.x, collisionBox.center.y - collisionBox.halfsize.y);
	sf::Vector2f upperRight(collisionBox.center.x + collisionBox.halfsize.x, collisionBox.center.y - collisionBox.halfsize.y);
	float ceilingY = 0;
	if (speed.y < 0
		&& map.hasCeiling(upperLeft, upperRight, &ceilingY))
	{
		pos.y = ceilingY;
		collisionBox.center.y = ceilingY + collisionBox.halfsize.y;
		speed.y = 0.f;
		_atCeiling = true;
	}
	else
		_atCeiling = false;

	//Check ground
	_wasOnGround = _onGround;
	sf::Vector2f bottomLeft(collisionBox.center.x - collisionBox.halfsize.x, collisionBox.center.y + collisionBox.halfsize.y);
	sf::Vector2f bottomRight(collisionBox.center.x + collisionBox.halfsize.x, collisionBox.center.y + collisionBox.halfsize.y);
	float groundY = 0;
	if (speed.y >= 0.0f
		&& map.hasGround(bottomLeft, bottomRight, &groundY))
	{
		pos.y = groundY - collisionBox.halfsize.y * 2;
		collisionBox.center.y = groundY - collisionBox.halfsize.y;
		speed.y = 0.f;
		_onGround = true;
	}
	else
		_onGround = false;
}

void MovingObject::move(sf::Vector2f offset)
{
	pos.x += offset.x;
	pos.y += offset.y;
	collisionBox.move(offset);
}