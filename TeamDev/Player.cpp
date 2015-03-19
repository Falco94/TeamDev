#include "Player.h"
#include "SFML\Graphics.hpp"
#include <iostream>

Player::Player(sf::Vector2f Position)
{
	if(!_textur.loadFromFile("C:\\Users\\Falco\\Documents\\Visual Studio 2013\\Projects\\TeamDev\\Textures\\Player\\player.png"))
	{ 
		std::cout << "Fehler beim Laden der Textur";
	}

	
	/* Erstellt eine neue Datei mit Transparenz
	Image.loadFromFile("C:\\Users\\Falco\\Documents\\Visual Studio 2013\\Projects\\TeamDev\\Textures\\Player\\player.png");
	Image.createMaskFromColor(sf::Color(20, 70, 96));
	Image.saveToFile("C:\\Users\\Falco\\Documents\\Visual Studio 2013\\Projects\\TeamDev\\Textures\\Player\\player.png");
	*/

	Initialisiere();

	_textur.setSmooth(true);
	Sprite.setTexture(_textur);
	Sprite.scale(2, 2);
	_position = Position;
	Sprite.setPosition(_position);
	X = _position.x;
	Y = _position.y;

}

Player::~Player()
{
}

void Player::Initialisiere()
{
	_position = sf::Vector2f(0,0);
	_alive = true;
	_leben = _maxLeben;
	_speed = 200.f;
}

void Player::SetPosition(sf::Vector2f Position)
{
	Sprite.setPosition(Position);
	_position = Position;
	X = _position.x;
	Y = _position.y;
}

void Player::Move(sf::Vector2f Offset)
{
	Sprite.move(Offset);
	_position += Offset;
	X = _position.x;
	Y = _position.y;
}

sf::Vector2f Player::GetPosition()
{
	return _position;
}

float Player::GetSpeed()
{
	return _speed;
}

void Player::Update(sf::Time Time, sf::RenderWindow &window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->Move(sf::Vector2f((this->GetSpeed()*Time.asSeconds()), 0));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->Move(sf::Vector2f(-(this->GetSpeed()*Time.asSeconds()), 0));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->Move(sf::Vector2f(0, -this->GetSpeed()*Time.asSeconds()));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		this->Move(sf::Vector2f(0, this->GetSpeed()*Time.asSeconds()));
	}

	//TODO: 30 als Korrektur für Sprite Größe. Dynamisch programmieren?
	if (this->X <= 0)
		this->SetPosition(sf::Vector2f(0, this->Y));

	if (this->X >= window.getSize().x-30)
		this->SetPosition(sf::Vector2f(window.getSize().x-30, this->Y));

	if (this->Y <= 0)
		this->SetPosition(sf::Vector2f(this->X, 0));

	if (this->Y >= window.getSize().y-30)
		this->SetPosition(sf::Vector2f(this->X, window.getSize().y-30));
}