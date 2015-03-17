#include "Game.h"

Game::Game()
{
	window.create(sf::VideoMode(1280, 720), "Test");
	_running = true;
}

void Game::Run()
{
	// Solange das Fenster nicht geschlossen ist --> GAMELOOP
	while (window.isOpen())
	{
		//Events abfangen
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
				_running = false;
			}
		}


	}
}

bool Game::isRunning()
{
	return _running;
}