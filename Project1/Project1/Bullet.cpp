#include "Bullet.h"

Bullet::Bullet()
{

}
Bullet::Bullet(sf::Texture*texture, float pos_X, float pos_Y, float movement_speed)
{
	this->shape.setTexture(texture);
	this->pos.X = pos_X;
	this->pos.Y = pos_Y;
	this->movementSpeed = movement_speed;

}
Bullet::~Bullet()
{

}
void Bullet::update()
{
	this->shape.move(this->movementùSpeed * this->direction);
}

void Game::render()
{
	
}