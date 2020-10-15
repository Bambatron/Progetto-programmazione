#pragma once

#include<iostream>

#include "Character.h"

class Player : public Character
{
//Attributes
private:
	unsigned int score;
//Methods
public:
	Player();
	~Player();

	void setScore(unsigned int score) { this->score = score; }
	void addScore(unsigned int score) { this->score += score; }
	unsigned int getScore() { return score; }
};