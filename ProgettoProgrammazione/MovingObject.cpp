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
	_pushedLWall = _pushLWall;
	_pushedRWall = _pushRWall;
	_wasAtCeiling = _atCeiling;

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
		speed.y = 0.0f;
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