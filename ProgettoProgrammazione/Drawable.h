#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Drawable
{
private:
	sf::Sprite sprite();
	sf::Texture texture();

	//Private functions
	void initTexture();
	void initSprite(float scale);

public:
	Drawable();
	virtual ~Drawable();
};
