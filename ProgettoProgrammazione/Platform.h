#pragma once

#include "Entity.h"

//Static platform that does not move or update in any way

class Platform: public Entity
{
	//Attributes
private:
	int posInMap;
	//Methods
public:
	Platform(int posInMap, float width = 50.f, float height = 25.f, int posX = 0, int posY = 0,  unsigned int textID = 0);

	int getPosInMap() { return posInMap; }
};

