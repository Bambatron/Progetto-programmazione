#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include "State.h"
#include "GameLogic.h"
#include "SelectionCharacter.h"
#include "Button.h"

class Main:
	public State
{
public:
	Main();
	virtual ~Main();

private:
	virtual void update(const sf::Time& delta_time);
	virtual void render();

	void initButtons();
	void initBackground();

	void updateButtons();

	sf::Texture background_txt;
	sf::Sprite background;

	Button new_game;
	Button exit;
};



