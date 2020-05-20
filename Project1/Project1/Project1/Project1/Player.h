#pragma once
#include "Character.h"
class Player
	public Character
{
public:
	Player();
	virtual~Player();

	const sf::Vector2f& getPos() const;
	{
		return this->sprite.getPosition();
	}
	void setArmor(int armor);
	void setScore(int score);

};

