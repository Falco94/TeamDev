#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include "Game.h"
#include <SFML\Graphics.hpp>
#include <list>

class Asteroid
{
public:
	Asteroid(sf::Vector2f Position);
	~Asteroid();

	sf::Vector2f GetPosition();
	void SetPosition(sf::Vector2f);
	void Move(sf::Vector2f);
	float X;
	float Y;
	void Initialisiere();
	void Update(sf::Time Time, Game &game);

	float GetSpeed();
	void SetSpeed(float Speed);

	int GetLeben();
	void SetLeben(int Leben);

	bool Alive();
	void Kill();

	void Draw(Game &Game);

	sf::Sprite Sprite;
	sf::Image Image;
	sf::Texture Textur;

private:
	sf::Vector2f _position;
	int _leben;
	int _maxLeben;
	int _currentRect;
	bool _alive;
	float _speed;
	sf::Time _tempTime;

	//Bilder des Asteroiden
	sf::IntRect AsteroidRect[8];

};

#endif