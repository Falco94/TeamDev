#include "Game.h"
#include "Player.h"
#include "Asteroid.h"
#include "Asteroids.h"
#include "Kollision.h"
#include "Shot.h"
#include "SFML\Audio.hpp"


// Verweise f�r SFML\Audio
#pragma comment(lib, "openal32.lib")
#pragma comment(lib, "sndfile.lib") 
#pragma comment(lib, "sfml-system.lib")

const float ASTEROID_SPAWN_TIMER = 0.75;

//TODO: Funktionen aus main Prozedur auslagern...
// window.draw und window.display in die Game Klasse einbauen.
int main()
{
	Game game;
	Player player(sf::Vector2f(100, 100));
	Asteroids asteroids;
	Kollision kollision;

	bool lockSpace;

	sf::Clock clock;
	sf::Clock universalClock;
	sf::Time time;
	sf::Time shotLock;
	sf::Time timeAll;
	sf::Time AsteroidSpawnTimer;

	universalClock.restart();

	
	////Music Test
	//sf::Music music;
	//if (!music.openFromFile("C:\\Users\\Falco\\Documents\\Visual Studio 2013\\Projects\\TeamDev\\Sounds\\vic-viper.wav"))
	//	return -1; // error
	//music.setLoop(true);
	//music.setVolume(10);
	//music.play();

	while (game.isRunning())
	{
		shotLock += clock.getElapsedTime();
		AsteroidSpawnTimer += clock.getElapsedTime();
		time = clock.restart();
		timeAll = universalClock.getElapsedTime();
		
		
		//Events abfangen
		sf::Event event;

		if (shotLock >= sf::milliseconds(500/player.upgrade.ShootingMultiply))
		{
			lockSpace = false;
			shotLock = shotLock.Zero;
		}

		game.window.clear();

		while (game.window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				game.window.close();
				game.running = false;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				if (!lockSpace)
				{
					for (int i = 0; i < player.upgrade.LaserCount; i++)
					{
						Shot* s = new Shot(sf::Vector2f(player.X + 30, player.Y + 10), i);
						player.Shots.push_back(s);
						lockSpace = true;
					}

				}
			}
		}

		if (AsteroidSpawnTimer > sf::seconds(ASTEROID_SPAWN_TIMER))
		{
			AsteroidSpawnTimer = AsteroidSpawnTimer.Zero;
			asteroids.AddAsteroid(sf::Vector2f(game.window.getSize().x, rand() % game.window.getSize().y));
		}


		kollision.BerechneKollisionen(player.Shots, asteroids.asteroids);

		asteroids.Update(time, game);

		player.UpdateShots(time, game);
		player.Update(time, game);
		player.Draw(game);

		game.Run();
		game.window.display();
	}

	return 0;
}

