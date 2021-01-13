#include "Game.h"

Game::Game(): window(sf::VideoMode(600,600), "window"), map(), camera(), player(), partitions()
{
	camera.setMapSize(map.getPixelMapSize());

	timePerFrame = (1.0f / 60.0f);
	gamePaused = false;

	/*partitionSize.x = map.getPixelMapSize().x / AREASIZE;
	partitionSize.y = map.getPixelMapSize().y / AREASIZE;
	generatePartitions();

	updateAreas(true);*/
}

void Game::run()
{
	float deltaTime = 0.0f;
	sf::Clock gameClock;

	while (window.isOpen())
	{
		sf::Event input;
		while (window.pollEvent(input))
		{
			processInput(input);
		}
		deltaTime += gameClock.restart().asSeconds();
		while (deltaTime > timePerFrame)
		{
			update(timePerFrame);
			deltaTime -= timePerFrame;

			//fixedUpdate();

			render();
		}
	}
}

void Game::processInput(sf::Event input)
{
	if (!player.processInput(input))
	{
		if (input.type == sf::Event::Closed)
		{
			window.close();
		}

		if (input.type == sf::Event::KeyPressed)
		{
			switch (input.key.code)
			{
			case sf::Keyboard::Escape:
				window.close();
				break;
			case sf::Keyboard::P:
				if (gamePaused)
					gamePaused = false;
				else
					gamePaused = true;
				break;
			case sf::Keyboard::R:	//Reset
				player.setPosition(140, 200);
			default:
				break;
			}
		}
	}

}

void Game::update(float deltaTime)
{
	map.update(deltaTime);

	player.update(deltaTime);

	camera.update(deltaTime, player.getPosition());

	fixedUpdate();
}

void Game::fixedUpdate()
{
	if (player.getPositionY() + player.getHeight() >= 560)
		player.hasGround();
	else
		player.hasGround(false);

	for (unsigned int i = 0; i < map.movingPlatforms.size(); i++)
	{
		if (map.movingPlatforms.at(i).isPhysical() && map.movingPlatforms.at(i).getPositionY() >= 560)
			map.movingPlatforms.at(i).hasGround(true);
	}

	for (unsigned int i = 0; i < map.destroyables.size(); i++)
	{
		if (map.destroyables.at(i).isPhysical() && (map.destroyables.at(i).getPositionY()+map.destroyables.at(i).getHeight()) >= 560)
			map.destroyables.at(i).hasGround(true);
	}

}

void Game::render()
{
	window.clear();
	
	window.setView(camera.getView());

	for (unsigned int i = 0; i < map.backgrounds.size(); i++)
	{
		window.draw(map.backgrounds.at(i));
	}
	for (unsigned int i = 0; i < map.platforms.size(); i++)
	{
		window.draw(map.platforms.at(i).draw());
	}
	for (unsigned int i = 0; i < map.movingPlatforms.size(); i++)
	{
		window.draw(map.movingPlatforms.at(i).draw());
	}
	for (unsigned int i = 0; i < map.destroyables.size(); i++)
	{
		window.draw(map.destroyables.at(i).draw());
	}

	window.draw(player.draw());

	window.display();
}