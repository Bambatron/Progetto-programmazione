#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include "Map.h"
#include "PlayerProva.h"

int main() {
	//Setting up
	sf::RenderWindow window(sf::VideoMode(800, 600), "camera");
	sf::Clock clock;
	sf::Time deltaTime = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	//Bacground
	sf::Texture backImage;
	std::string filename("C:/Immagine.png");
	backImage.loadFromFile(filename);
	sf::Sprite background(backImage);

	Map map;
	/*
	//Platforms
	std::map <int, sf::RectangleShape> platforms;

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
	platforms.at(8).setPosition(200.f, 150.f);*/

	float dirX = -1;
	float dirY = 1;

	//Player
	PlayerProva player;
	player.setPos(100.f, 500.f);

	//Game loop
	while (window.isOpen())
	{
		deltaTime += clock.restart();
		// Event processing
		sf::Event event;
		if (deltaTime > timePerFrame)
		{
			deltaTime -= timePerFrame;
			while (window.pollEvent(event))
			{
				// Request for closing the window
				if (event.type == sf::Event::Closed)
				{
					window.close();
				}
				if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::A))
				{
					player.move(-1, timePerFrame.asSeconds());
				}
				if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::D))
				{
					player.move(1, timePerFrame.asSeconds());
				}
			}
			/*
			//Moving platforms on X
			if (platforms.at(7).getPosition().x <= 425)
			{
				dirX = 1;
			}
			if (platforms.at(7).getPosition().x >= 525)
			{
				dirX = -1;
			}
			platforms.at(7).move(dirX*timePerFrame.asSeconds()*25, 0.f);
			//Moving platforms on y
			if (platforms.at(8).getPosition().y >= 250)
			{
				dirY = -1;
			}
			if (platforms.at(8).getPosition().y <= 150)
			{
				dirY = +1;
			}
			platforms.at(8).move(0.f, dirY*timePerFrame.asSeconds()*25);*/
			map.update(timePerFrame.asSeconds());
		}

		// Clear the whole window before rendering a new frame
		window.clear();

		//Draw background
		/*window.draw(background);
		for (unsigned int i = 0; i < platforms.size(); i++)
		{
			window.draw(platforms.at(i));
		}*/

		map.draw(window);

		window.draw(player.getPlayerSprite());

		// End the current frame and display its contents on screen
		window.display();
	}

	return 0;
}