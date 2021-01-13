#include "Entity.h"

Entity::Entity()
{
}

void Entity::setPosition(sf::Vector2i pos)
{
	hitBox.left = pos.x;
	hitBox.top = pos.y;
	sprite.setPosition(pos.x, pos.y);
}

void Entity::setPosition(int posX, int posY)
{
	hitBox.left = posX;
	hitBox.top = posY;
	sprite.setPosition(posX, posY);
}

void Entity::move(sf::Vector2f offset)
{
	if (offset.x != 0 || offset.y != 0)
		moved = true;

	hitBox.left += offset.x;
	hitBox.top += offset.y;
	sprite.move(offset);
	lastMovement = offset;
}

void Entity::update(float delTaTime)
{
	moved = false;
	collided = false;

	if (physical)
		updatePhysics(delTaTime);

	move(speed*delTaTime);
}
