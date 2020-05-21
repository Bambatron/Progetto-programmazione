#include "Main.h"

Main::Main()
{
	initBackground();
	initButtons();
}

Main::~Main()
{
}

void Main::initButtons()
{
	play_game.setText();
	play_game.setBox();

	end.setText();
	end.setBox();
}

void Main::initBackground()
{
	background_txt.loadFromFile("Sources/background.jpg");
	background.setTexture(background_txt);
}

void Main::updateButtons()
{
	//NEWGAME
	if (new_game.isHover(mouse_pos_view))
	{
		new_game.buttonAnimation();
	}
	else
		new_game.setStandard();

	if (new_game.isActive(mouse_pos_view))
	{
		this->states->push(new SelectionCharacter());
		this->states->top()->window = this->window;
		this->states->top()->states = this->states;
		return;
	}


	//EXIT
	if (exit.isHover(mouse_pos_view))
	{
		exit.buttonAnimation();
	}
	else
		exit.setStandard();

	if (exit.isActive(mouse_pos_view))
	{
		this->states->top()->endState();
	}
}

void Main::update(const sf::Time& delta_time)
{
	window->setView(window->getDefaultView());
	updateMousePos();
	updateButtons();
	render();
}

void Main::render()
{
	window->draw(background);
	new_game.draw(window);
	exit.draw(window);
}

//Linea generale che non fa parte del codice
int main()
{
	// generazione numeri casuali
	srand(time(static_cast<unsigned>(0)));
	Game game;
	game.run();

	//end game
	return 0;
}