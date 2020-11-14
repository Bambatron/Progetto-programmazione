#include "Alien.h"

void Alien::initVariables()
{
	this->pointCount = rand() %x+y; //min=x max=y
	this->type       = 0;
	this->speed      = static_cast<float>(this->pointCount);
	this->hpTot      = static_cast<int>(this->pointCount);
	this->hp         = this->hpTot;
	this->damage     = this->pointCount;
	this->points     = this->pointCount; 
}

void Alien::initShape()
{
	this->shape.pointCount(this->pointCount);
	this->shape.setShape();
	this->shape.setFillColor(sf::Color(rand() % x + y, rand() % x + y, rand() % x + y));
}

Alien::Alien(float pos_x,float pos_y)
{
	
	this->initShape();
	this->initVariables();
	this->shape.setPosition(pos_x, pos_y);
	this->shape.setFillColor(sf::Color(rand(),rand(),rand()));
}
Alien::~Alien()
{

}


const sf::FloatRect Alien::getBounds() const
{
	return this->shape.getGlobalBounds();
}

const int & Alien::getPoints() const
{
	return this->points ;
}
const int & Alien::getDamage() const
{
	return this->damage;
}

//Functions
void Alien::update();
{
	this->shape.move(0.f, this->speed);
}
void Alien::render(sf::RenderTarget*target);
{
	target->draw(this->shape);

}

