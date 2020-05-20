#include "Alien.h"
void Alien::initShape()
{

	this->shape.setShape();

}

void Alien::initVariables()
{
	this->hpTot  = x;
	this->hp     = x;
	this->damage = x;
	this->points = x; 
}
Alien::Alien(float pos_x,float pos_y)
{
	
	this->initShape();
	this->initVariables();
	this->shape.setPosition(pos_x, pos_y);


}
Alien::~Alien()
{


}

//Functions
void Alien::update();
{

}
void Alien::render(sf::RenderTarget*target);
{
	target->draw(this->shape);

}

