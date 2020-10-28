#include <iostream>

#include "Platform.h"

class MovingPlatform: public Platform
{
	//Attributes
private:
	sf::Vector2f originalPosition;	//Original position of the platform
	sf::Vector2f finalPosition;	//Final position of the platform
	bool moving; //1 if the platform is moving
	sf::Vector2i direction;
	float speed;
	

	//Methods
public:
	MovingPlatform(int originalPositionX, int originalPositionY, int finalPositionX, int finalPositionY, float width = 50.f, float height = 25.f, bool moving = 1, float speed = 60.f);

	bool isMoving() { return moving; }
	void setMoving(bool start) { moving = start; } //1 if the platform start moving

	sf::Vector2f getOriginalPosition() { return originalPosition; }
	sf::Vector2f getFinalPos() { return finalPosition; }

	void move(float elapsedTime);
	 
private:
	void searchDirection();
	bool isNearX();
	bool isNearY();

};
