#pragma once
#include "Character.h"
class Player
	public Character
{
public:
	Player();
	virtual~Player();
	void setArmor(int armor);
	void setScore(int score);

};

