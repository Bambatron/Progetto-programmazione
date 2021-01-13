#pragma once

#include <SFML/Window/Event.hpp>

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
	//Getters
	unsigned int getScore() { return score; }
	//Setters
	void setScore(unsigned int score) { this->score = score; }
	void addScore(unsigned int score) { this->score += score; }
	//Transformers
	//Updates
	bool processInput(sf::Event input);
	virtual void shoot();
	virtual void ability();
};