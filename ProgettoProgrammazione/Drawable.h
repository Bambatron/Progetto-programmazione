#pragma once

#include <SFML/Graphics.hpp>

//This class is an interface for SFML resources for objects that have to be rendered on screen

class Drawable
{
//Attributes
protected:
	sf::RectangleShape sprite;
	sf::Texture texture;
	unsigned int textureID;

//Methods
public:
	Drawable();
	//Getters
	void render(sf::RenderWindow window) { window.draw(sprite); }
	sf::RectangleShape draw() { return sprite; }
	unsigned int getTextureID() { return textureID; }

protected:
	void initTexture();
	void initSprite(float scale);
};
