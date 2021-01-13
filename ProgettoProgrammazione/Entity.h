#pragma once

#include <iostream>
#include <set>

#include "Drawable.h"
#include "PhysicObject.h"

//Implements MovingObjects and Drawable functionalities
//Objects affected by physics that is rendered

struct AreaData
{
public:
	int areaPosInPart;	//position in partitions map
	int areaPosInObj;	//position in entity area map
	int posInArea;	//position of entity in area

	AreaData(int partPos, int areaPos, int pos)
	{
		this->areaPosInPart = partPos;
		this->areaPosInObj = areaPos;
		this->posInArea = pos;
	}
};

enum EntityType : int
{
	platform = 0,
	movingPlatform = 1,
	destroyable = 2,
	bullet = 3,
	alien = 4,
	player = 5,
	drop = 7
};

class Entity: public PhysicObject, public Drawable
{
	//Attributes
public:
	std::map <int, AreaData> areas;
protected:
	EntityType type;
	//Methods
public:
	Entity();
	//Getters
	int areasSize() { return areas.size(); }
	EntityType getType() { return type; }
	sf::Vector2i getPosition() { return sf::Vector2i(hitBox.left, hitBox.top); }
	int getPositionX() { return hitBox.left; }
	int getPositionY() { return hitBox.top; }
	sf::Vector2i getTopLeft() { return sf::Vector2i(hitBox.left, hitBox.top); }
	sf::Vector2i getBottomLeft() { return sf::Vector2i(hitBox.left, hitBox.top + hitBox.height); }
	sf::Vector2i getTopRight() { return sf::Vector2i(hitBox.left + hitBox.width, hitBox.top); }
	sf::Vector2i getBottomRight() { return sf::Vector2i(hitBox.left + hitBox.width, hitBox.top + hitBox.height); }
	sf::Vector2f getSize() { return sf::Vector2f(hitBox.width, hitBox.height); }
	float getWidth() { return hitBox.width; }
	float getHeight() { return hitBox.height; }
	//Setters
	void setPosition(sf::Vector2i pos);
	void setPosition(int posX, int posY);
	void clearAreas() { areas.clear(); }
	void addArea(int partPos, int pos) { areas.insert({ areas.size(), AreaData(partPos, areas.size(), pos) }); }
	void eraseArea(int pos) { areas.erase(pos); }
	//Transformers
	void move(sf::Vector2f offset);
	void move(float offsetX, float offsetY) { move(sf::Vector2f(offsetX, offsetY)); }
	//Updates
	virtual void update(float deltaTime);
};