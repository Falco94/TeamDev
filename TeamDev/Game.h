#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>;
#include "SFML\Graphics.hpp";

class Game
{
public:
	Game();

	bool isRunning();
	void Run();

	sf::RenderWindow window;


private:
	bool _running;
};

#endif