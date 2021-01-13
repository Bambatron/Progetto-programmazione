#include "Map.h"

Map::Map(): backImages(), backgrounds(), platforms(), movingPlatforms(), destroyables()
{
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
				loadStat(line);
				break;
			case '1':
				std::getline(ifs, line);
				loadBackground(line);
				break;
			case '2':
				ifs >> std::ws;
				std::getline(ifs, line);
				generatePlatform(line);
				break;
			case '3':
				ifs >> std::ws;
				std::getline(ifs, line);
				generateMovingPlatform(line);
				break;
			case '4':
				ifs >> std::ws;
				std::getline(ifs, line);
				generateDestroyable(line);
				break;
			default:
				break;
			}
		}
	}
}

void Map::update(float deltaTime)
{
	for (unsigned int i = 0; i < movingPlatforms.size(); i++)
	{
		movingPlatforms.at(i).update(deltaTime);
	}
	for (unsigned int i = 0; i < destroyables.size(); i++)
	{
		destroyables.at(i).update(deltaTime);
	}
}

void Map::render(sf::RenderWindow& window)
{
	for (unsigned int i = 0; i < backgrounds.size(); i++)
	{
		window.draw(backgrounds.at(i));
	}
	for (unsigned int i = 0; i < platforms.size(); i++)
	{
		window.draw(platforms.at(i).draw());
	}
	for (unsigned int i = 0; i < movingPlatforms.size(); i++)
	{
		window.draw(movingPlatforms.at(i).draw());
	}
	for (unsigned int i = 0; i < destroyables.size(); i++)
	{
		window.draw(destroyables.at(i).draw());
	}
}

void Map::loadStat(std::string line)
{
	//Extract data from the line
	std::string tmp;
	int values[MAPSTAT]; //This works only because I already now how many number there are on that line
	for (unsigned int i = 0; i < MAPSTAT; i++)
	{
		size_t pos = line.find("|");	//Search "|" that indicate that what follows is an attribute
		line = line.substr(pos + 1);	//Subtract from line the pointer
		pos = line.find("|");			//Find where the current number ends
		tmp = line.substr(0, pos);		//Copy only the number in tmp
		line = line.substr(pos);		//Eliminate from line the nmber maintaining the next pointer to number
		values[i] = stof(tmp);			//Convert the number to float
	}

	pixelMapSize.x = values[0];
	pixelMapSize.y = values[1];

	switch (values[2])
	{
	case '0':
		type = menu;
		break;
	case '1':
		type = level;
		break;
	}
}

void Map::loadBackground(std::string line)
{
	//Extract Texture ID from line
	std::string imgName;
	size_t pos = line.find("|");	//Search "|" that indicate that what follows is an attribute
	line = line.substr(pos + 1);	//Subtract from line the pointer
	pos = line.find("|");			//Find where the current number ends
	imgName = line.substr(0, pos);	//Copy only the number in tmp
	line = line.substr(pos);		//Eliminate from line the nmber maintaining the next pointer to number

	//Create the texture
	backImages.insert({ backImages.size(), sf::Texture() });
	backImages.at(backImages.size() - 1).loadFromFile(imgName);

	//Extract data from the line
	std::string tmp;
	float values[BACKSTAT]; //This works only because I already now how many number there are on that line
	for (unsigned int i = 0; i < BACKSTAT; i++)
	{
		size_t pos = line.find("|");	////Search "|" that indicate that what follows is an attribute
		line = line.substr(pos + 1);	//Subtract from line the pointer
		pos = line.find("|");			//Find where the current number ends
		tmp = line.substr(0, pos);		//Copy only the number in tmp
		line = line.substr(pos);		//Eliminate from line the number maintaining the next pointer to number
		values[i] = stof(tmp);			//Convert the number to float
	}

	//Create background
	backgrounds.insert({ backgrounds.size(), sf::RectangleShape(sf::Vector2f(values[2],values[3])) });
	backgrounds.at(backgrounds.size() - 1).setPosition(values[0], values[1]);
	backgrounds.at(backgrounds.size() - 1).setTexture(&backImages.at(backImages.size() - 1));	//Bind a texture to the background
}

void Map::generatePlatform(std::string line)
{
	//Extract data from the line
	std::string tmp;
	float values[PLATSTAT]; //This works only because I already now how many number there are on that line
	for (unsigned int i = 0; i < PLATSTAT; i++)
	{
		size_t pos = line.find("|");	//Search "|" that indicate that what follows is an attribute
		line = line.substr(pos + 1);	//Subtract from line the pointer
		pos = line.find("|");			//Find where the current number ends
		tmp = line.substr(0, pos);		//Copy only the number in tmp
		line = line.substr(pos);		//Eliminate from line the nmber maintaining the next pointer to number
		values[i] = stof(tmp);			//Convert the number to float
	}

	//Create platform
	this->platforms.insert({ platforms.size(), Platform::Platform(platforms.size(), values[0], values[1], values[2], values[3], values[4]) });
}

void Map::generateMovingPlatform(std::string line)
{
	//Extract data from the line
	std::string tmp;
	float values[MOVPLATSTAT]; //This works only because I already now how many number there are on that line
	for (unsigned int i = 0; i < MOVPLATSTAT; i++)
	{
		size_t pos = line.find("|");	//Search "|" that indicate that what follows is an attribute
		line = line.substr(pos + 1);	//Subtract from line the pointer
		pos = line.find("|");			//Find where the current number ends
		tmp = line.substr(0, pos);		//Copy only the number in tmp
		line = line.substr(pos);		//Eliminate from line the number maintaining the next pointer to number
		values[i] = stof(tmp);			//Convert the number to float
	}

	//Create the moving platform
	this->movingPlatforms.insert({ movingPlatforms.size(), MovingPlatform::MovingPlatform(movingPlatforms.size(), values[0], values[1], values[2], values[3], values[4], values[5], values[6], values[7], values[8]) });
}

void Map::generateDestroyable(std::string line)
{
	//Extract data from the line
	std::string tmp;
	float values[DESTRSTAT]; //This works only because I already now how many number there are on that line
	for (unsigned int i = 0; i < DESTRSTAT; i++)
	{
		size_t pos = line.find("|");	//Search "|" that indicate that what follows is an attribute
		line = line.substr(pos + 1);	//Subtract from line the pointer
		pos = line.find("|");			//Find where the current number ends
		tmp = line.substr(0, pos);		//Copy only the number in tmp
		line = line.substr(pos);		//Eliminate from line the number maintaining the next pointer to number
		values[i] = stof(tmp);			//Convert the number to float
	}
	//Create the destroyable
	destroyables.emplace(destroyables.size(), Destroyable::Destroyable(destroyables.size(), values[0], values[1], values[2], values[3], values[4], values[5], values[6], values[7], values[8], values[9], values[10]));
}