#include "PlayerProva.h"

PlayerProva::PlayerProva()
{
	sprite.setSize(sf::Vector2f(25.f, 50.f));
	sprite.setFillColor(sf::Color::Red);
	speed = 200;
}

sf::Drawable & PlayerProva::getPlayerSprite()
{
	return this->sprite;
}

void PlayerProva::setPos(float x, float y)
{
	this->sprite.setPosition(sf::Vector2f(x, y));
}

void PlayerProva::move(float direction, float elapsedTime)
{
	this->sprite.move(direction*speed*elapsedTime, 0.f);
}

void PlayerProva::jump(float t1, float t2)
{
	float g = 9.81;
	float v0 = 55;
	float offset = g*(t2 - t1)*(t2 - t1)/2 - v0*(t2-t1);
	sprite.move(sf::Vector2f(0.f, offset));
}
