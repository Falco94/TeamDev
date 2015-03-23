#include "Kollision.h"

bool Kollision::Kollidiert(sf::Sprite* sprite, std::list<Asteroid*> asteroids)
{
	std::list<Asteroid*>::iterator it = asteroids.begin();
	
		while (it != asteroids.end())
		{
			if (sprite->getGlobalBounds().intersects((*it)->Sprite.getGlobalBounds()))
			{
				if ((*it)->GetLeben() > 1)
					(*it)->SetLeben((*it)->GetLeben() - 1);
				else
					it = asteroids.erase(it);
				
				return true;
			}
			it++;
		}

	return false;
}

void Kollision::BerechneKollisionen(std::list<Shot*> shots, std::list<Asteroid*> asteroids)
{
	std::list<Asteroid*>::iterator itAsteroid = asteroids.begin();
	std::list<Shot*>::iterator itShot = shots.begin();

	while (itShot != shots.end())
	{
		while (itAsteroid != asteroids.end())
		{
			if ((*itShot)->Sprite.getGlobalBounds().intersects((*itAsteroid)->Sprite.getGlobalBounds()))
			{
				if ((*itAsteroid)->Alive())
					(*itShot)->Kill();

         		if ((*itAsteroid)->GetLeben() > 1)
					(*itAsteroid)->SetLeben((*itAsteroid)->GetLeben() - 1);
				else
				(*itAsteroid)->Kill();

			}
			itAsteroid++;
		}

		itAsteroid = asteroids.begin();
		itShot++;
	}
}