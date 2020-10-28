#include "Map.h"

Map::Map()
{
	//Generating tilemap
	for (unsigned int y = 0; y < HEIGHT; y++)
	{
		for (unsigned int x = 0; x < WIDTH; x++)
		{
			tiles[x][y] = TileType::empty;
		}
	}

	//Generating platforms
	std::ifstream ifs("MAP.txt"); //This open the file
	//Check if file is open correctly
	if (!ifs.is_open())
	{
		std::cout << "Errore nell'aprire file mappa";
	}
	char ch;
	std::string line;

	while (!ifs.eof()) //eof return true if the end of the file is reached
	{
		ifs.get(ch);
		if (ch = '#')	//Recognise start of obj properties
		{
			ifs.get(ch);
			switch (ch)	//Recognise type of obj
			{
			case '0':
				std::getline(ifs, line);
				loadBackground(line);
				break;
			case '1':
				ifs >> std::ws;
				std::getline(ifs, line);
				generatePlatform(line);
				break;
			case '2':
				ifs >> std::ws;
				std::getline(ifs, line);
				generateMovingPlatform(line);
				break;
			case '3':
				ifs >> std::ws;
				std::getline(ifs, line);
				generateDestroyable(line);
				break;
			default:
				break;
			}
		}
	}

	loadTileMap();
}

void Map::loadTileMap()
{
	int countX = 0;
	int countY = 0;
	int offsetX = 0;
	int offsetY = 0;
	for (unsigned int i = 0; i < platforms.size(); i++)
	{
		countX = getTileIndexS(platforms.at(i).getBody().getSize().x);
		countY = getTileIndexS(platforms.at(i).getBody().getSize().y);		
		offsetX = getTileIndexS(platforms.at(i).getBody().getPosition().x);
		offsetY = getTileIndexS(platforms.at(i).getBody().getPosition().y);
		for (unsigned int y = 0; y < countY; y++)
		{
			for (unsigned int x = 0; x < countX; x++)
				tiles[x+offsetX][y+offsetY] = TileType::block;
		}
	}
	for (unsigned int i = 0; i < movingPlatforms.size(); i++)
	{
		countX = getTileIndexS(movingPlatforms.at(i).getBody().getSize().x);
		countY = getTileIndexS(movingPlatforms.at(i).getBody().getSize().y);
		offsetX = getTileIndexS(movingPlatforms.at(i).getBody().getPosition().x);
		offsetY = getTileIndexS(movingPlatforms.at(i).getBody().getPosition().y);
		for (unsigned int y = 0; y < countY; y++)
		{
			for (unsigned int x = 0; x < countX; x++)
				tiles[x+offsetX][y+offsetY] = TileType::block;
		}
	}
	for (unsigned int i = 0; i < destroyable.size(); i++)
	{
		countX = getTileIndexS(destroyable.at(i).getBody().getSize().x);
		countY = getTileIndexS(destroyable.at(i).getBody().getSize().y);
		offsetX = getTileIndexS(destroyable.at(i).getBody().getPosition().x);
		offsetY = getTileIndexS(destroyable.at(i).getBody().getPosition().y);
		for (unsigned int y = 0; y < countY; y++)
		{
			for (unsigned int x = 0; x < countX; x++)
				tiles[x+offsetX][y+offsetY] = TileType::block;
		}
	}
}

TileType Map::getTile(int x, int y)
{
	if ((x < 0) || (x >= WIDTH) || (y < 0) || (y >= HEIGHT))
		return TileType::block;
	else
		return tiles[x][y];
}

bool Map::isObstacle(int x, int y)
{
	if ((x < 0) || (x >= WIDTH) || (y < 0) || (y >= HEIGHT))
		return true;
	else
		return tiles[x][y];
}

bool Map::isGround(int x, int y)
{
	if ((x <= 0) || (x >= WIDTH) || (y <= 0) || (y >= HEIGHT))
		return false;
	else
		return ((tiles[x][y] == TileType::block)||(tiles[x][y] == TileType::oneway));
}

bool Map::hasGround(sf::Vector2f bottomLeft, sf::Vector2f bottomRight, float* groundY)
{
	sf::Vector2f checkedTile = bottomLeft;

	int tileIndexX;
	int tileIndexY;
	
	while (checkedTile.x < bottomRight.x)
	{
		checkedTile.x = fmin(checkedTile.x, bottomRight.x);
		tileIndexX = getTileIndexS(checkedTile.x);
		tileIndexY = getTileIndexS(checkedTile.y);
		if (this->isGround(tileIndexX, tileIndexY))
		{
			*groundY = getTilePosS(tileIndexY);
			return true;
		}
		checkedTile.x += TILESIZE;
	}
	return false;
}

bool Map::isOneWay(int x, int y)
{
	if ((x < 0) || (x >= WIDTH) || (y < 0) || (y >= HEIGHT))
		return false;
	else
		return (tiles[x][y] == TileType::oneway);
}

bool Map::isEmpty(int x, int y)
{
	if ((x < 0) || (x >= WIDTH) || (y < 0) || (y >= HEIGHT))
		return false;
	else
		return (tiles[x][y] == TileType::empty);
}

void Map::clearTile(float posX, float posY)
{
	tiles[getTileIndexS(posX)][getTileIndexS(posY)] = TileType::empty;
}

void Map::setTile(float posX, float posY)
{
	tiles[getTileIndexS(posX)][getTileIndexS(posY)] = TileType::block;
}

void Map::update(float elapsedTime)
{
	int countX = 0;
	int countY = 0;
	int offsetX = 0;
	int offsetY = 0;
	for (unsigned int i = 0; i < movingPlatforms.size(); i++)
	{
		if (movingPlatforms.at(i).isMoving())
		{
			countX = getTileIndexS(movingPlatforms.at(i).getBody().getSize().x);
			countY = getTileIndexS(movingPlatforms.at(i).getBody().getSize().y);
			offsetX = getTileIndexS(movingPlatforms.at(i).getBody().getPosition().x);
			offsetY = getTileIndexS(movingPlatforms.at(i).getBody().getPosition().y);
			//Clear tiles
			for (unsigned int y = 0; y < countY; y++)
			{
				for (unsigned int x = 0; x < countX; x++)
					tiles[x + offsetX][y + offsetY] = TileType::empty;
			}
			//move platforms
			movingPlatforms.at(i).move(elapsedTime);
			//Reset tiles
			countX = getTileIndexS(movingPlatforms.at(i).getBody().getSize().x);
			countY = getTileIndexS(movingPlatforms.at(i).getBody().getSize().y);
			offsetX = getTileIndexS(movingPlatforms.at(i).getBody().getPosition().x);
			offsetY = getTileIndexS(movingPlatforms.at(i).getBody().getPosition().y);
			for (unsigned int y = 0; y < countY; y++)
			{
				for (unsigned int x = 0; x < countX; x++)
					tiles[x + offsetX][y + offsetY] = TileType::block;
			}
		}
	}
}

void Map::draw(sf::RenderWindow& window)
{
	window.draw(background);
	for (unsigned int i = 0; i < platforms.size(); i++)
	{
		window.draw(platforms.at(i).getBody());
	}
	for (unsigned int i = 0; i < movingPlatforms.size(); i++)
	{
		window.draw(movingPlatforms.at(i).getBody());
	}
	for (unsigned int i = 0; i < destroyable.size(); i++)
	{
		window.draw(destroyable.at(i).getBody());
	}
}

void Map::loadBackground(std::string line)
{
	backImage = new sf::Texture();
	backImage->loadFromFile(line);
	background = *(new sf::RectangleShape(sf::Vector2f(800, 600)));
	background.setTexture(backImage);
}

void Map::generatePlatform(std::string line)
{
	std::string tmp;

	float values[4]; //This function only because I aready now how many number there will be on that line
	//Search "|" that indicate that what follows is a number
	for (unsigned int i = 0; i < 4; i++)
	{
		size_t pos = line.find("|");
		line = line.substr(pos + 1); //Subtract from line the pointer
		pos = line.find("|");
		tmp = line.substr(0, pos);	//Copy only the number in tmp
		line = line.substr(pos);	//Eliminate from line the nmber maintaining the next pointer to number
		values[i] = stof(tmp);	//Convert the number to float
	}
	this->platforms.insert({ platforms.size(), Platform::Platform(values[0], values[1], values[2], values[3]) });
}

void Map::generateMovingPlatform(std::string line)
{
	std::string tmp;

	float values[7]; //This function only because I aready now how many number there will be on that line

	//Search "|" that indicate that what follows is a number
	for (unsigned int i = 0; i < 7; i++)
	{
		size_t pos = line.find("|");
		line = line.substr(pos + 1); //Subtract from line the pointer
		pos = line.find("|");
		tmp = line.substr(0, pos);	//Copy only the number in tmp
		line = line.substr(pos);	//Eliminate from line the nmber maintaining the next pointer to number
		values[i] = stof(tmp);	//Convert the number to float
	}
	this->movingPlatforms.insert({ movingPlatforms.size(), MovingPlatform::MovingPlatform(values[0], values[1], values[4], values[5], values[2], values[3], true, values[6])});
}

void Map::generateDestroyable(std::string line)
{
	std::string tmp;

	float values[6]; //This function only because I aready now how many number there will be on that line

	//Search "|" that indicate that what follows is a number
	for (unsigned int i = 0; i < 6; i++)
	{
		size_t pos = line.find("|");
		line = line.substr(pos + 1); //Subtract from line the pointer
		pos = line.find("|");
		tmp = line.substr(0, pos);	//Copy only the number in tmp
		line = line.substr(pos);	//Eliminate from line the nmber maintaining the next pointer to number
		values[i] = stof(tmp);	//Convert the number to float
	}
	this->destroyable.insert({ destroyable.size(), Destroyable::Destroyable(values[0], values[1], values[2], values[3], true, values[4], values[5]) });
}