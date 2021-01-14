#pragma once
#ifndef ALIEN_H
#define ALIEN_H
#include "Character.h"
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Alien
	public Entity
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
	//void initAniamtions();
	void initShape();

public:
	Alien(float x, float y, sf::Texture& texture_sheet);
	virtual~Alien();

	void update(const float& dt, sf::Vector2f& mouse_pos_view);

	void render(sf::RenderTarget & target, const bool show_hitbox);
	
	
	//Accessors
	const sf::FloatRect getBounds() const;
	const int& getPoints() const;
	const int& getDamage() const;

	//functions
	void update();
	void render(sf::RenderTarget*target);

};
#endif
