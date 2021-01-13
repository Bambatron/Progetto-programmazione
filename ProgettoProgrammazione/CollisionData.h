#pragma once

#include "Entity.h"

//Contains vital information for a single collision between Entities

enum CollisionType: int
{
	null = 0,
	//With Platform
	destrToPlat = 1,
	bullToPlat = 2,
	charToPlat = 3,
	dropToPlat = 4,
	//With MovingPlatform
	movPlatToDestr = 5,
	movPlatToBull = 6,
	movPlatToChar = 7,
	movPlatToDrop = 8,
	//With Destroyable
	destrToDestr = 9,
	destrToBull = 10,
	destrToChar = 11,
	destrToDrop = 12,
	//With Bullet
	bullToChar = 13,
	//With Char
	aliToAli = 14,
	aliToPlay = 15,
	playToDrop = 16
};

class CollisionData
{
public:	
	CollisionType type;
	sf::FloatRect overlap;
	Entity* obj1;
	Entity* obj2;

	CollisionData(CollisionType type = CollisionType::null, sf::FloatRect overlap = sf::FloatRect(0.0f, 0.0f, 0.0f, 0.0f), Entity* obj1 = nullptr, Entity* obj2 = nullptr);

	static bool doesCollide(EntityType type1, EntityType type2);
	static bool doesCollide(EntityType type1, EntityType type2, CollisionType* type);
};

