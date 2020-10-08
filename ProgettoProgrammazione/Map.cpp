#include "Map.h"

Map::Map()
{
	backImage = new sf::Texture();
	backImage->loadFromFile("C:/Immagine.png");
	background = *(new sf::RectangleShape(sf::Vector2f(800, 600)));
	background.setTexture(backImage);

	//Ground
	platforms.insert({ 0, sf::RectangleShape(sf::Vector2f(800, 50)) });
	platforms.at(0).setFillColor(sf::Color::Green);
	platforms.at(0).setPosition(0.f, 550.f);

	//Suspended platforms
	platforms.insert({ 1, sf::RectangleShape(sf::Vector2f(150, 25)) });
	platforms.at(1).setFillColor(sf::Color::Yellow);
	platforms.at(1).setPosition(100.f, 425.f);

	platforms.insert({ 2, sf::RectangleShape(sf::Vector2f(150, 25)) });
	platforms.at(2).setFillColor(sf::Color::Yellow);
	platforms.at(2).setPosition(550.f, 425.f);

	platforms.insert({ 3, sf::RectangleShape(sf::Vector2f(200, 25)) });
	platforms.at(3).setFillColor(sf::Color::Yellow);
	platforms.at(3).setPosition(300.f, 325.f);

	platforms.insert({ 4, sf::RectangleShape(sf::Vector2f(125, 25)) });
	platforms.at(4).setFillColor(sf::Color::Yellow);
	platforms.at(4).setPosition(0.f, 275.f);

	platforms.insert({ 5, sf::RectangleShape(sf::Vector2f(125, 25)) });
	platforms.at(5).setFillColor(sf::Color::Yellow);
	platforms.at(5).setPosition(675.f, 275.f);

	platforms.insert({ 6, sf::RectangleShape(sf::Vector2f(100, 25)) });
	platforms.at(6).setFillColor(sf::Color::Yellow);
	platforms.at(6).setPosition(350.f, 75.f);

	//Moving platforms
	platforms.insert({ 7, sf::RectangleShape(sf::Vector2f(100, 25)) }); //Moving on X
	platforms.at(7).setFillColor(sf::Color::Magenta);
	platforms.at(7).setPosition(525.f, 200.f);

	platforms.insert({ 8, sf::RectangleShape(sf::Vector2f(100, 25)) });	//Moving on Y
	platforms.at(8).setFillColor(sf::Color::Magenta);
	platforms.at(8).setPosition(200.f, 150.f);

}

void Map::draw(sf::RenderWindow& window)
{
	window.draw(background);
	for (unsigned int i = 0; i < platforms.size(); i++)
	{
		window.draw(platforms.at(i));
	}
}

void Map::update(float elapsedTime)
{
	if (platforms.at(7).getPosition().x <= 425)
	{
		dirX = 1;
	}
	else if (platforms.at(7).getPosition().x >= 525)
	{
		dirX = -1;
	}
	platforms.at(7).move(dirX * elapsedTime * 50, 0.f);

	if (platforms.at(8).getPosition().y >= 250)
	{
		dirY = -1;
	}
	else if (platforms.at(8).getPosition().y <= 150)
	{
		dirY = 1;
	}
	platforms.at(8).move(0.f, dirY * elapsedTime * 50);
}