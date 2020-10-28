#include "PlayerProva.h"

PlayerProva::PlayerProva() 
{
	//Drawable stuff
	sprite.setSize(sf::Vector2f(12.f, 40.f));
	sprite.setPosition(sf::Vector2f(100.f, 500.f));
	sprite.setFillColor(sf::Color::Red);
	//Moving Object
	pos = sf::Vector2f(100.f, 500.f);
	collisionBox.center = sf::Vector2f(100 + 6, 500 + 20);
	collisionBox.halfsize = sf::Vector2f(6, 20);
	this->currentState = CharacterState::standing;
	
	this->_onGround = true;
	this->_wasOnGround = true;
	this->_pushLWall = false;
	this->_pushedLWall = false;
	this->_pushRWall = false;
	this->_pushedRWall = false;
	this->_atCeiling = false;
	this->_wasAtCeiling = false;

	//Character
	hp = 100;
	facingRight = true;
	wSpeed = 60;
	jSpeed = -160;
}

void PlayerProva::move(float elapsedTime)
{
	std::cout << "PlayerProva::move()\n";
	MovingObject::move(speed*elapsedTime);
	sprite.move(sf::Vector2f(speed.x*elapsedTime, speed.y*elapsedTime));
}
