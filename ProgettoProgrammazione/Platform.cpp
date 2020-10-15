#include "Platform.h"

Platform::Platform(int posX, int posY, float width, float height)
{
	body.setPosition(posX, posY);
	body.setSize(sf::Vector2f(width, height));
	body.setFillColor(sf::Color::Yellow);
}
