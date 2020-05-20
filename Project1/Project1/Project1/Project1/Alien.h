#pragma once
#include "Character.h"
#include <SFML/Graphics.hpp>
class Alien
	public Character
{
private:
	sf::RectangleShape shape;

	int hp;
	int hpTot;
	int damage;
	int points;

	void initShape();
	void initVariables();


public:
	Alien(float pos_x,float pos_y);
	virtual~Alien();

	//functions
	void update();
	void render(sf::RenderTarget*target);

};

