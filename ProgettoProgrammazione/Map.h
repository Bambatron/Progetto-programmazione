#pragma once

#include <map>
#include <fstream>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Platform.h"
#include "MovingPlatform.h"
#include "Destroyable.h"

class Map
{//Attributes
private:
	sf::Texture* backImage;
	sf::RectangleShape background;

	std::map <int, Platform> platforms;
	std::map <int, MovingPlatform> movingPlatforms;
	float dirX;
	float dirY;

	//Methods
public:
	Map();

	void draw(sf::RenderWindow& window);

	void update(float elapsedTime); //Move around the platforms that are intended to be moved

private:
	void loadBackground(std::string line);
	void generatePlatform(std::string line);
	void generateMovingPlatform(std::string line);
	void generateDestroyable(std::string line);
};