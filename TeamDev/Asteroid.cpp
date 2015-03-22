#include "Asteroid.h"
#include "SFML\Graphics.hpp"
#include <iostream>

Asteroid::Asteroid(sf::Vector2f Position)
{
	if (!Textur.loadFromFile("C:\\Users\\Falco\\Documents\\Visual Studio 2013\\Projects\\TeamDev\\Textures\\Player\\asteroid_sprite.png"))
	{
		std::cout << "Fehler beim Laden der Textur";
	}

	//// Erstellt eine neue Datei mit Transparenz
	//Image.loadFromFile("C:\\Users\\Falco\\Documents\\Visual Studio 2013\\Projects\\TeamDev\\Textures\\Player\\asteroid_sprite.png");
	//Image.createMaskFromColor(sf::Color(255, 0, 255));
	//Image.saveToFile("C:\\Users\\Falco\\Documents\\Visual Studio 2013\\Projects\\TeamDev\\Textures\\Player\\asteroid_sprite.png");

	Initialisiere();

	Textur.setSmooth(true);
	Sprite.setTexture(Textur);
	Sprite.scale(1,1);
	Sprite.setTextureRect(sf::IntRect(50, 0, 21, 16));
	_position = Position;
	Sprite.setPosition(_position);
	X = _position.x;
	Y = _position.y;

	AsteroidRect[0] = sf::IntRect(2, 0, 36, 40);
	AsteroidRect[1] = sf::IntRect(43, 0, 35, 40);
	AsteroidRect[2] = sf::IntRect(83, 0, 34, 40);
	AsteroidRect[3] = sf::IntRect(122, 0, 36, 40);
	AsteroidRect[4] = sf::IntRect(164, 0, 33, 40);
	AsteroidRect[5] = sf::IntRect(204, 0, 32, 40);
	AsteroidRect[6] = sf::IntRect(244, 0, 31, 40);
	AsteroidRect[7] = sf::IntRect(282, 0, 36, 40);
}

Asteroid::~Asteroid()
{
}

void Asteroid::Initialisiere()
{
	_position = sf::Vector2f(0, 0);
	_alive = true;
	_maxLeben = 2;
	_leben = _maxLeben;
	_speed = 200.f;
}

void Asteroid::SetPosition(sf::Vector2f Position)
{
	Sprite.setPosition(Position);
	_position = Position;
	X = _position.x;
	Y = _position.y;
}

void Asteroid::Move(sf::Vector2f Offset)
{
	Sprite.move(Offset);
	_position += Offset;
	X = _position.x;
	Y = _position.y;
}

sf::Vector2f Asteroid::GetPosition()
{
	return _position;
}

float Asteroid::GetSpeed()
{
	return _speed;
}

void Asteroid::Update(sf::Time Time, Game &game)
{
	this->Move(sf::Vector2f(-(this->GetSpeed()*Time.asSeconds()), 0));

	_tempTime += Time;

		if (this->Sprite.getTextureRect().left > 0)
		{
			if (_tempTime > sf::seconds(0.2))
			{
				_tempTime = _tempTime.Zero;

				if (_currentRect > 7)
					_currentRect = 0;
				this->Sprite.setTextureRect(this->AsteroidRect[_currentRect]);
				_currentRect++;
			}
		}

	//TODO: 30 als Korrektur für Sprite Größe. Dynamisch programmieren?
	if (this->X <= 0)
		this->Kill();
}

bool Asteroid::Alive()
{
	return _alive;
}

void Asteroid::Draw(Game &Game)
{
	Game.window.draw(this->Sprite);
}

void Asteroid::Kill()
{
	_alive = true;
}