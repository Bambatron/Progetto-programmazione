#pragma once

#include <SFML/System.hpp>
#include<SFML/Window.hpp>

#include "Map.h"
#include "Player.h"
#include "Camera.h"
#include "CollisionData.h"

#define AREASIZE 300	//Each partition is a 300x300 pixels

struct Partition
{
public:
	std::map <int, Entity*> area;
	int posInMap;	//position in partitions map

	Partition(int id = 0): area()
	{
		posInMap = id;
	}
};


class Game
{
private:
	sf::RenderWindow window;
	Camera camera;
	
	float timePerFrame;

	Map map;
	
	Player player;

	sf::Vector2i partitionSize;
	std::map <int, Partition> partitions;
	std::list <CollisionData> collisions;

	//Flags
	bool gamePaused;

public:
	Game();
	void run();

private:
	void processInput(sf::Event input);
	
	void update(float deltaTime);
	
	void fixedUpdate();
	void checkCollision();	//Check for collisions in every partition
	void checkAreaCollision(int partitionID);	//Check for collisions in a single partition
	void handleCollision();

	void render();

	//Partitions
	void generatePartitions();
	void clearPartitions() { partitions.clear(); }
	//Areas
	void addObjToArea(int idArea, Entity* obj);
	void removeObjFromArea(int idArea, Entity* obj);
	void removeObjFromAllAreas(Entity* obj);	//Remove obj from all areas in which it's present
	void clearArea(int idArea) { partitions.at(idArea).area.clear(); }
	void updateAreas(bool all = false);
	void checkAreas(Entity* obj);
};

