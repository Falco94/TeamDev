#ifndef ASTEROIDS_HPP
#define ASTEROIDS_HPP

#include "Asteroid.h"

class Asteroids
{
public:
	Asteroids();
	~Asteroids();
	std::list<Asteroid*> asteroids;
	void AddAsteroid(sf::Vector2f(Position));
	void Update(sf::Time Time, Game &game);
};

#endif