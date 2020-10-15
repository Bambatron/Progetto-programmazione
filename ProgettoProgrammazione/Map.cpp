#include "Map.h"

Map::Map()
{
	std::ifstream ifs("MAP.txt"); //This open the file
	//Check if file is open correctly
	if (!ifs.is_open())
	{
		std::cout << "Errore neel'aprire file mappa";
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
}

void Map::draw(sf::RenderWindow& window)
{
	window.draw(background);
	for (unsigned int i = 0; i < platforms.size(); i++)
	{
		window.draw(platforms.at(i).getBody());
	}
	for ( unsigned int i = 0; i < movingPlatforms.size(); i++)
	{
		window.draw(movingPlatforms.at(i).getBody());
	}
}

void Map::update(float elapsedTime)
{	for (unsigned int i = 0; i < movingPlatforms.size(); i++)
	{
		if (movingPlatforms.at(i).isMoving()) {
			movingPlatforms.at(i).move(elapsedTime);
		}
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
	this->platforms.insert({ platforms.size(), Destroyable::Destroyable(values[0], values[1], values[2], values[3], true, values[4], values[5]) });
}
