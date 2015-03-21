#ifndef SHOT_HPP
#define SHOT_HPP

#include "SFML\Graphics.hpp"
#include <iostream>

class Shot
{
public:
	Shot(sf::Vector2f Position);
	~Shot();

	sf::Vector2f GetPosition();
	void SetPosition(sf::Vector2f);
	void Move(sf::Vector2f);
	float X;
	float Y;
	void Initialisiere();
	void Update(sf::Time Time, sf::RenderWindow &window);

	float GetSpeed();
	void SetSpeed(float Speed);

	int GetLeben();
	void SetLeben(int Leben);

	bool Alive();
	void Kill();

	sf::Sprite Sprite;
	sf::Image Image;

private:
	sf::Vector2f _position;
	bool _alive;
	float _speed;
	sf::Texture _textur;
	
};

#endif