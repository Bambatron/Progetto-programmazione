#include "Platform.h"

Platform::Platform(int posInMap, float width, float height, int posX, int posY, unsigned int textID)
{
	this->posInMap = posInMap;

	type = platform;

	sprite.setPosition(posX, posY);
	sprite.setSize(sf::Vector2f(width, height));
	sprite.setOutlineColor(sf::Color::Black);
	sprite.setOutlineThickness(1.0f);
	textureID = textID;
	if (textureID == 0)
		sprite.setFillColor(sf::Color::Yellow);

	hitBox.left = posX;
	hitBox.top = posY;
	hitBox.width = width;
	hitBox.height = height;
	maxSpeed = sf::Vector2f(0.0f, 0.0f);
	speed = sf::Vector2f(0.0f, 0.0f);
	physical = false;
	kinematic = false;
	onGround = false;
	pushLeftWall = false;
	pushRightWall = false;
	atCeiling = false;
	moved = false;
	collided = false;
}
