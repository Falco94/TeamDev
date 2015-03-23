#ifndef KOLLISION_HPP
#define KOLLISION_HPP

#include "SFML\Graphics.hpp"
#include "Asteroids.h"
#include "Shot.h"

class Kollision
{
public:
	bool Kollidiert(sf::Sprite* sprite, std::list<Asteroid*> asteroids);
	void BerechneKollisionen(std::list<Shot*> shots, std::list<Asteroid*> asteroids);
};


#endif