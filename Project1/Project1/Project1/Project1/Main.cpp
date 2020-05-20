#include "Main.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

int main()
{
	// generazione numeri casuali
	srand(time(static_cast<unsigned>(0)));
	Game game;
	game.run();

	//end game
	return 0;
}