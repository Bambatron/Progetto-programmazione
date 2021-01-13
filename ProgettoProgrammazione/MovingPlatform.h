#pragma once

#include "Entity.h"

//Platform capable of moving, on track or free roam , but not affected by physics

class MovingPlatform: public Entity
{
	//Attributes
protected:
	int posInMap;
	sf::Vector2i startingPosition;	//Original position of the platform
	sf::Vector2i finalPosition;	//Final position of the platform
	sf::Vector2i direction;
	bool onTrack;
	bool moving;

	//Methods
public:
	MovingPlatform();
	MovingPlatform(int id, float width = 0.0f, float height = 0.0f, int sPosX = 0, int sPosY = 0, int fPosX = 0, int fPosY = 0, float speedX = 0.0f, float speedY = 0.0f, int textID = 0);
	//Getters
	int getPosInMap() { return posInMap; }
	sf::Vector2i getStartingPosition() { return startingPosition; }
	sf::Vector2i getFinalPos() { return finalPosition; }
	sf::Vector2i getDirection() { return direction; }
	bool isOnTrack() { return onTrack; }
	bool isMoving() { return moving; }
	//Setters
	void setStartingPosition(sf::Vector2i startPos) { startingPosition = startPos; }
	void setFinalPosition(sf::Vector2i finPos) { finalPosition = finPos; }
	void setOnTrack(bool track) { onTrack = track; }
	void setMoving(bool mov) { moving = mov; }
	//Updates
	virtual void update(float deltaTime);
protected:
	void searchDirection();
	bool isNearX();
	bool isNearY();
};
