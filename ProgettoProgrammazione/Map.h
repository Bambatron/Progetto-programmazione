#pragma once

#include <list>
#include <map>
#include <fstream>
#include <iostream>

#include "Platform.h"
#include "MovingPlatform.h"
#include "Destroyable.h"

#define MAPSTAT		3	//Number of values in a map stat line
#define BACKSTAT	4	//Number of values in a Background desription
#define PLATSTAT	5	//Number of values in a Platform description
#define MOVPLATSTAT	9	//Number of values in a MovingPlatform description
#define DESTRSTAT	11	//Number of values in a Destroyable description

enum MapType : int
{
	menu = 0,
	level = 1
};

class Map
{
	//Attributes
public:
	std::map <int, sf::RectangleShape> backgrounds;
	//Platforms
	std::map <int, Platform> platforms;
	std::map <int, MovingPlatform> movingPlatforms;
	std::map <int, Destroyable> destroyables;
private:
	sf::Vector2i pixelMapSize;
	MapType type;
	//Background
	std::map <int, sf::Texture> backImages;
	
	//Methods
public:
	//Constructor
	Map();
	//Getters
	sf::Vector2i getPixelMapSize() { return pixelMapSize; }
	int getPixelMapWidth() { return pixelMapSize.x; }
	int getPixelMapHeight() { return pixelMapSize.y; }
	//Update
	void update(float deltaTime); //Move around the platforms that are intended to be moved

	//Render
	void render(sf::RenderWindow& window);

private:
	//Generations
	void loadStat(std::string line);
	void loadBackground(std::string line);
	void generatePlatform(std::string line);
	void generateMovingPlatform(std::string line);
	void generateDestroyable(std::string line);
};