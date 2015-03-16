#include <iostream>
#include <SFML\Graphics.hpp>

int main()
{

	sf::Window window(sf::VideoMode(1204, 768), "Testbild");

	// Solange das Fenster nicht geschlossen ist --> GAMELOOP
	while (window.isOpen())
	{
		//Events abfangen
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}
	}

	return 0;
}