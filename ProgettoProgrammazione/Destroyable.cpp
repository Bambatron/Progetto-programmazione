#include "Destroyable.h"

Destroyable::Destroyable(int posX, int posY, float width, float height, bool alive, int hp, int points)
{
	body.setPosition(posX, posY);
	body.setSize(sf::Vector2f(width, height));
	this->alive = alive;
	this->hp = hp;
	this->points = points;
	body.setFillColor(sf::Color::Green);
	body.setOutlineColor(sf::Color::Blue);
	body.setOutlineThickness(2.f);
}

void Destroyable::takeDamage(unsigned int dmg)
{
	if (dmg < this->hp)
		this->hp -= dmg;
	else
		this->death();
}

void Destroyable::death()
{
	//Drop Stuff

	alive = false;
	
	//Release resources if necessary

}