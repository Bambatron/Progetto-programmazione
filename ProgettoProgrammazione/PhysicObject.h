#pragma once

#include <SFML/Graphics/Rect.hpp>

class PhysicObject
{
	//Attributes
protected:
	sf::FloatRect hitBox;
	sf::Vector2f maxSpeed;
	sf::Vector2f speed;
	sf::Vector2f lastMovement;
	//Flags
	bool physical; //If false is not affected by normal physics (like gravity)
	bool kinematic; //If true is not affected by collision (but can still collide with other PhysicObjects)
	bool onGround; //Has a PhysicObject below
	bool pushLeftWall;	////Has a PhysicObject to its left
	bool pushRightWall;	//Has a PhysicObject it its right
	bool atCeiling;	//Has a PhysicObject above
	bool moved;	//Has moved in the last frame
	bool collided;	//Has collided in the last frame 
	
	//Methods
public:
	PhysicObject();
	//Getters
	sf::Vector2f getMaxSpeed() { return maxSpeed; }
	float getMaxSpeedX() { return maxSpeed.x; }
	float getMaxSpeedY() { return maxSpeed.y; }
	sf::Vector2f getSpeed() { return speed; }
	float getSpeedX() { return speed.x; }
	float getSpeedY() { return speed.y; }
	bool isPhysical() { return physical; }
	bool isKinematic() { return kinematic; }
	bool isOnGround() { return onGround; }
	bool isPushingLeftWall() { return pushLeftWall; }
	bool isPushingRightWall() { return pushRightWall; }
	bool isAtCeiling() { return atCeiling; }
	bool hasMoved() { return moved; }
	bool hasCollided() { return collided; }
	const sf::FloatRect getHitBox() { return hitBox; }
	bool intersect(const sf::FloatRect otherObj) { return hitBox.intersects(otherObj); }
	bool intersect(const sf::FloatRect otherObj, sf::FloatRect* overlappedArea) { return hitBox.intersects(otherObj, *overlappedArea); }
	//Setters
	void hasGround(bool value = true) { onGround = value; }
	void hasLeftWall(bool value = true) { pushLeftWall = value; }
	void hasRightWall(bool value = true) { pushRightWall = value; }
	void hasCeiling(bool value = true) { atCeiling = value; }
	//Updates
	void updatePhysics(float deltaTime);
};

