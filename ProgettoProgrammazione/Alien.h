#pragma once

#include <SFML/Graphics.hpp>

#include "Character.h"

class Alien : public Character
{
private:

	unsigned pointCount;
	sf::RectangleShape shape;
	int type;
	float speed;
	int hp;
	int hpTot;
	int damage;
	int points;

	void initVariables();
	void initShape();

public:
	Alien(float pos_x, float pos_y);
	virtual~Alien();

	//Accessors
	const sf::FloatRect getBounds() const;
	const int& getPoints() const;

	//functions
	void update();
	void render(sf::RenderTarget*target);
};