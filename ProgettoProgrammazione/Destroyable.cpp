#include "Destroyable.h"

Destroyable::Destroyable()
{
	alive = true;
	type = EntityType::destroyable;
	lastMovement = sf::Vector2f(0.0f, 0.0f);
	physical = true;
	kinematic = false;
	onGround = false;
	pushLeftWall = false;
	pushRightWall = false;
	atCeiling = false;
	moved = false;
	collided = false;
}

Destroyable::Destroyable(int id, float width, float height, int posX, int posY, int fPosX, int fPosY, float speedX, float speedY, int hp, int points, int textID)
{
	alive = true;
	this->hp = hp;
	this->points = points;

	startingPosition = sf::Vector2i(posX, posY);
	finalPosition = sf::Vector2i(fPosX, fPosY);
	if (fPosX < 0 || fPosY < 0)
		onTrack = false;
	else
		onTrack = true;

	type = EntityType::destroyable;

	hitBox.left = posX;
	hitBox.top = posY;
	hitBox.width = width;
	hitBox.height = height;
	maxSpeed = sf::Vector2f(speedX, speedY);
	
	if (onTrack)
		searchDirection();
	else
		speed = sf::Vector2f(0.0f, 0.0f);
	
	lastMovement = sf::Vector2f(0.0f, 0.0f);
	physical = true;
	kinematic = false;
	onGround = false;
	pushLeftWall = false;
	pushRightWall = false;
	atCeiling = false;
	moved = false;
	collided = false;

	sprite.setPosition(posX, posY);
	sprite.setSize(sf::Vector2f(width, height));
	sprite.setOutlineColor(sf::Color::Black);
	sprite.setOutlineThickness(1.0f);
	textureID = textID;
	if (textID == 0)
		sprite.setFillColor(sf::Color::Green);
}

void Destroyable::takeDamage(unsigned int dmg)
{
	if (dmg < this->hp)
		this->hp -= dmg;
	else
		this->death();
}

void Destroyable::update(float elapsedTime)
{
	moved = false;
	collided = false;

	if (physical)
		updatePhysics(elapsedTime);

	move(speed*elapsedTime);
}

void Destroyable::death()
{
	//Drop Stuff

	alive = false;
	
	//Release resources if necessary

}