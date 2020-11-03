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
	
	sf::RectangleShape tileMap(sf::Vector2f(TILESIZE, TILESIZE));
	bool showTileMap = false;

	sf::Clock clock;
	sf::Time deltaTime = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f/60.f);
	
	Map map;
	
	//Player
	PlayerProva player;

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
				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::D)
						player.inputs[KeyInput::goRight] = true;
					if (event.key.code == sf::Keyboard::A)
						player.inputs[KeyInput::goLeft] = true;
					if (event.key.code == sf::Keyboard::W)
						player.inputs[KeyInput::jump] = true;
					/*if (event.key.code == sf::Keyboard::S)
					if (event.key.code == sf::Keyboard::K)*/
					if (event.key.code == sf::Keyboard::T)
						showTileMap = true;
				}
				if (event.type == sf::Event::KeyReleased)
				{
					if (event.key.code == sf::Keyboard::D)
						player.inputs[KeyInput::goRight] = false;
					if (event.key.code == sf::Keyboard::A)
						player.inputs[KeyInput::goLeft] = false;
					if (event.key.code == sf::Keyboard::W)
						player.inputs[KeyInput::jump] = false;
					/*if (event.key.code == sf::Keyboard::S)
					if (event.key.code == sf::Keyboard::K)*/
					if (event.key.code == sf::Keyboard::T)
						showTileMap = false;
				}
			}
			//Update
			player.updateCharacter(timePerFrame.asSeconds(), map);

			map.update(timePerFrame.asSeconds());

			// Clear the whole window before rendering a new frame
			window.clear();
	
			//Draw background
			if (showTileMap)
			{
				tileMap.setSize(sf::Vector2f(TILESIZE, TILESIZE));
				for (unsigned int y = 0; y < HEIGHT; y++)
				{
					for (unsigned int x = 0; x < WIDTH; x++)
					{
						if (map.tiles[x][y] == TileType::empty)
							tileMap.setFillColor(sf::Color::Blue);
						else if (map.tiles[x][y] == TileType::block)
							tileMap.setFillColor(sf::Color::Green);

						tileMap.setPosition(x*TILESIZE, y*TILESIZE);
						window.draw(tileMap);
					}
				}
				tileMap.setSize(player.getSprite().getSize());
				tileMap.setPosition(player.getPos());
				tileMap.setFillColor(sf::Color::Red);
				window.draw(tileMap);
			}
			else
			{
				map.draw(window);
				player.draw(window);
			}
			// End the current frame and display its contents on screen
			window.display();
		}
	}
	return 0;
}