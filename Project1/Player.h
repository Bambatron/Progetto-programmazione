#pragma once
#include "Character.h"
#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Player
	public Character
{
private:
	sf::Sprite sprite;
	sf::Texture textureSheet;

	//Animation
	sf::IntRect currentFrame;

	float moovmentSpeed;
	float attackNotHit;
	float attackNotHitMax;

	int hp;
	int hpMax;
	
	void initVariables();
	void initTexture();
	void initSprite();

	void initGUI(); // Si può mettere anche in Game.h

public:
	Player();
	virtual~Player();

	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;
	const int& getHp() const;
	const int& getHTot() const;

	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y);
	void setHp(const int hp);
	void loseHp(const int value);

	//Functions
	void move(const float posX, const float posY);
	const bool canAttack();

	void updateMovement();
	void updateAttack();
	void update();
	void render(sf::RenderTarget& target);

	void setArmor(int armor);
	void setScore(int score);

};

