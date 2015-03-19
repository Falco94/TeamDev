#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>;
#include "SFML\Graphics.hpp";
#include <list>

class Game
{
public:
	Game();

	bool isRunning();
	void Run();
	sf::RenderWindow window;
	bool running;

private:
	
};

#endif