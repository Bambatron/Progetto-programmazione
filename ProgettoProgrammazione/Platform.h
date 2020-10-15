#pragma once

#include <SFML/Graphics.hpp>

class Platform
{
	//Attributes
protected:
	sf::RectangleShape body;	//the actual platform
	
	//Methods
public:
	Platform(int posX = 0, int posY = 0, float width = 50.f, float height = 25.f);
	sf::RectangleShape getBody() { return this->body; }
};

