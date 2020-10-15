#pragma once
#include <SFML/Graphics.hpp>

class PlayerProva
{
public:
	PlayerProva();

	sf::Drawable& getPlayerSprite();

	void setPos(float x, float y);
	void setJumping(bool jump) { jumping = jump; }

	bool getJumping() { return jumping; }

	void move(float direction, float elapsedTime);

	void jump(float t1, float t2);

	sf::RectangleShape sprite;

private:
	
	float speed;
	bool jumping; // 1 if player is jumping, if player is not jumping
};