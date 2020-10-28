#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

//This class is an interface for SFML resources

class Drawable
{
//Attributes
protected:
	sf::RectangleShape sprite;
	sf::Texture texture;
	unsigned int textureID;

//Methods
public:
	sf::RectangleShape getSprite() { return sprite; }
protected:
	void initTexture();
	void initSprite(float scale);
};
