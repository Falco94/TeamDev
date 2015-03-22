#include "Asteroids.h"

Asteroids::Asteroids()
{
}

Asteroids::~Asteroids()
{
}

void Asteroids::AddAsteroid(sf::Vector2f Position)
{
	Asteroid* a = new Asteroid(Position);
	this->asteroids.push_back(a);
}

void Asteroids::Update(sf::Time Time, Game &game)
{
	std::list<Asteroid*>::iterator it = this->asteroids.begin();

	while (it != this->asteroids.end())
	{
		if ((*it)->Alive())
		{
			(*it)->Draw(game);
			(*it)->Update(Time, game);
			it++;
		}
		else
		{
			it = this->asteroids.erase(it);
		}
	}
}