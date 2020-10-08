#pragma once
#include <SFML/Graphics.hpp>

class PlayerProva
{
public:
	PlayerProva();

	sf::Drawable& getPlayerSprite();

	void setPos(float x, float y);

	void move(float direction, float elapsedTime);

private:
	sf::RectangleShape sprite;
	float speed;
};