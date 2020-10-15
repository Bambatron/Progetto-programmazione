#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Drawable
{
//Attributes
protected:
	sf::RectangleShape* sprite;
	sf::Texture texture;
	unsigned int textureID;

//Methods
protected:
	void initTexture();
	void initSprite(float scale);
	void collide();
};
