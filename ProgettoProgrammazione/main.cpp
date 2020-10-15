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

	Map map;

	float dirX = -1;
	float dirY = 1;
	//Jump stuff
	float t1 = 0;
	float t2 = 0;
	float startingY = 0;

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
				if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::W))
				{
					player.setJumping(true);
					startingY = player.sprite.getPosition().y;
				}
			}
		
			if (player.getJumping())
			{
				player.jump(t1, t2);
				t1 = t2;
				t2 += timePerFrame.asSeconds();
				if (((player.sprite.getPosition().y - 50) == 550) || ((startingY - player.sprite.getPosition().y) >= 150))
				{
					player.setJumping(false);
					t1 = 0;
					t2 = 0;
				}
			}

			map.update(timePerFrame.asSeconds());
		}

		// Clear the whole window before rendering a new frame
		window.clear();

		//Draw background
		
		map.draw(window);

		window.draw(player.getPlayerSprite());

		// End the current frame and display its contents on screen
		window.display();
	}

	return 0;
}