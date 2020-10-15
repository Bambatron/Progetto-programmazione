#include "Player.h"

Player::Player()
{
	sprite->setSize(sf::Vector2f(25.f, 50.f));
	sprite->setFillColor(sf::Color::Blue);
	hp = 100;
	facingRight = 1;
	speed = 250.f;
	score = 0;
}

Player::~Player()
{

}
