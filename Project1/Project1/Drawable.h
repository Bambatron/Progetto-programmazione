#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
class Drawable
{
private:
	sf::Sprite sprite();
	sf::Texture texture();

	//Private functions
	void initTexture();
	void initSprite();

public:
	Drawable()
		virtual ~Drawable();

};

