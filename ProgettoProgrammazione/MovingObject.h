#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include"Map.h"

//This class is used to implement object affected by physics

class AABB //This class is only used by Moving object
{
	//Attributes
public:
	sf::Vector2f center;
	sf::Vector2f halfsize;
	
	//Methods
public:
	AABB(float cx = 0, float cy = 0, float hsx = 0, float hsy = 0);
	AABB(sf::Vector2f c, sf::Vector2f hs);

	void move(sf::Vector2f offset);
};

class MovingObject
{
	//Atributes
protected:
	sf::Vector2f pos;
	sf::Vector2f oldPos;

	sf::Vector2f speed;
	sf::Vector2f oldSpeed;

	AABB collisionBox;

	//Flags
	bool _onGround;
	bool _wasOnGround;

	bool _pushLWall;
	bool _pushedLWall;
	bool _pushRWall;
	bool _pushedRWall;

	bool _atCeiling;
	bool _wasAtCeiling;

	//Methods
public:
	//Constructors
	MovingObject(sf::Vector2f pos, sf::Vector2f center, sf::Vector2f hs);
	MovingObject(float posX = 0, float posY = 0, float cX = 0, float cY = 0, float hsX = 0, float hsY = 0);
	//Getters
	sf::Vector2f getPos() { return this->pos; }
	sf::Vector2f getOldPos() { return this->oldPos; }
	sf::Vector2f getSpeed() { return this->speed; }
	sf::Vector2f getOldSpeed() { return this->oldSpeed; }
	sf::Vector2f getAABBPos() { return sf::Vector2f(collisionBox.center.x - collisionBox.halfsize.x, collisionBox.center.y - collisionBox.halfsize.y); }
	//Setters
	void setPos(sf::Vector2f sPos) { this->pos = sPos; }
	void setSpeed(sf::Vector2f sSpeed) { this->speed = sSpeed; }
	//Updates
	void updatePhysics(float elapsedTime, Map& map);
	void move(sf::Vector2f offset);
};