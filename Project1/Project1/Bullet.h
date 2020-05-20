#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
class Bullet
	public Entity;
{
private:

	sf::Sprite shape;

	sf::Vector2f direction;
	float movementspeed;



public:
	Bullet();
	Bullet(sf::Texture*texture, float posX, float posY, float movement_speed);
	virtual~Bullet();

	void update();
	void render(sf::RenderTarget*target);
};

