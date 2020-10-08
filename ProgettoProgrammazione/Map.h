#pragma once
#include <SFML/Graphics.hpp>
#include <map>

class Map
{//Attributes
private:
	sf::Texture* backImage;
	sf::RectangleShape background;

	std::map <int, sf::RectangleShape> platforms;

	float dirX;
	float dirY;

	//Methods
public:
	Map();

	void draw(sf::RenderWindow& window);

	void update(float elapsedTime); //Move around the platforms that are intended to be moved

};