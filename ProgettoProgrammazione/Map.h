#pragma once

#include <map>
#include <fstream>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Platform.h"
#include "MovingPlatform.h"
#include "Destroyable.h"

#define TILESIZE	25	//Every tile is a 25x25 square
#define WIDTH		32	//Tiles on x axis
#define HEIGHT		24	//Tiles on y axis
#define TILECOUNT	768//Number of tiles in the map

enum TileType
{
	empty = 0,	//Void tile
	block = 1,	//Not-crossable platform
	oneway = 2	//one way crossable platform, usually from over to below
};

class Map
{
	//Attributes
public:
	//Tile map
	TileType tiles[32][24];
private:
	//Background
	sf::Texture* backImage;
	sf::RectangleShape background;

	//Platforms
	std::map <int, Platform> platforms;
	std::map <int, MovingPlatform> movingPlatforms;
	std::map <int, Destroyable> destroyable;

	//Methods
public:
	//Constructor
	Map();
	void loadTileMap();	//Load the tile map for the first time

	//Getters
	static sf::Vector2i getTileIndex(float x, float y) { return sf::Vector2i((x / TILESIZE), (y / TILESIZE)); }
	static int getTileIndexS(float value) { return (value / TILESIZE); }
	static sf::Vector2i getTilePos(int x, int y) { return sf::Vector2i((x * TILESIZE), (y * TILESIZE)); }
	static float getTilePosS(int value) { return (value * TILESIZE); }
	TileType getTile(int x, int y);
	bool isObstacle(int x, int y);
	bool isGround(int x, int y);
	bool hasGround(sf::Vector2f bottomLeft, sf::Vector2f bottomRight, float* groundY);
	bool isOneWay(int x, int y);
	bool isEmpty(int x, int y);

	//Setters
	void clearTile(float posX, float posY);	//PosX and posY as map positin and not as tile index
	void setTile(float posX, float posY);	//PosX and posY as map positin and not as tile index
	
	//Update
	void update(float elapsedTime); //Move around the platforms that are intended to be moved
	
	//Render
	void draw(sf::RenderWindow& window);

private:
	//Generations
	void loadBackground(std::string line);
	void generatePlatform(std::string line);
	void generateMovingPlatform(std::string line);
	void generateDestroyable(std::string line);
};