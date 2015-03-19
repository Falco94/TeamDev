#include "Game.h"
#include "Player.h"
#include "SFML\Audio.hpp"


// Verweise für SFML\Audio
#pragma comment(lib, "openal32.lib")
#pragma comment(lib, "sndfile.lib") 
#pragma comment(lib, "sfml-system.lib")

//TODO: Funktionen aus main Prozedur auslagern...
// window.draw und window.display in die Game Klasse einbauen.
int main()
{
	Game game;
	Player player(sf::Vector2f(100, 100));

	sf::Clock clock;
	sf::Time time;
	sf::Time timeAll;


	//Music Test
	sf::Music music;
	if (!music.openFromFile("C:\\Users\\Falco\\Documents\\Visual Studio 2013\\Projects\\TeamDev\\Sounds\\vic-viper.wav"))
		return -1; // error
	music.play();


	while (game.isRunning())
	{

		time = clock.restart();
		timeAll += clock.restart();

		//Events abfangen
		sf::Event event;

		game.window.clear();

		while (game.window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				game.window.close();
				game.running = false;
			}
		}

		player.Update(time, game.window);

		game.Run();
		game.window.draw(player.Sprite);
		game.window.display();
	}

	return 0;
}