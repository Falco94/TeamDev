#include "Player.h"
#include "SFML\Graphics.hpp"
#include <iostream>

Player::Player(sf::Vector2f Position)
{
	if(!Textur.loadFromFile("C:\\Users\\Falco\\Documents\\Visual Studio 2013\\Projects\\TeamDev\\Textures\\Player\\playerSprite.png"))
	{ 
		std::cout << "Fehler beim Laden der Textur";
	}

	//// Erstellt eine neue Datei mit Transparenz
	//Image.loadFromFile("C:\\Users\\Falco\\Documents\\Visual Studio 2013\\Projects\\TeamDev\\Textures\\Player\\playerSprite.png");
	//Image.createMaskFromColor(sf::Color(20, 70, 96));
	//Image.saveToFile("C:\\Users\\Falco\\Documents\\Visual Studio 2013\\Projects\\TeamDev\\Textures\\Player\\playerSprite.png");
	

	Initialisiere();

	Textur.setSmooth(true);
	Sprite.setTexture(Textur);
	Sprite.scale(2, 2);
	Sprite.setTextureRect(sf::IntRect(50, 0, 21, 16));
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

void Player::Update(sf::Time Time, Game &game)
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
		_tempTimeUp += Time;

		if (this->Sprite.getTextureRect().left > 0)
		{
			if (_tempTimeUp > sf::seconds(0.75))
			{
				_tempTimeUp = _tempTimeUp.Zero;

				this->Sprite.setTextureRect(sf::IntRect(this->Sprite.getTextureRect().left-25, 0, 21, 16));
			}
		}

		this->Move(sf::Vector2f(0, -this->GetSpeed()*Time.asSeconds()));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		_tempTimeDown += Time;

		if (this->Sprite.getTextureRect().left < 100)
		{
			if (_tempTimeDown > sf::seconds(0.75))
			{
				_tempTimeDown = _tempTimeDown.Zero;
				this->Sprite.setTextureRect(sf::IntRect(this->Sprite.getTextureRect().left + 25, 0, 21, 16));
			}
		}

		this->Move(sf::Vector2f(0, this->GetSpeed()*Time.asSeconds()));
	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		_tempTimeNotDown += Time;

		if (this->Sprite.getTextureRect().left > 50)
		{
			if (_tempTimeNotDown > sf::seconds(0.75))
			{
				_tempTimeNotDown = _tempTimeNotDown.Zero;
				this->Sprite.setTextureRect(sf::IntRect(this->Sprite.getTextureRect().left - 25, 0, 21, 16));
			}
		}
	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		_tempTimeNotUp += Time;

		if (this->Sprite.getTextureRect().left < 50)
		{
			if (_tempTimeNotUp > sf::seconds(0.75))
			{
				_tempTimeNotUp = _tempTimeNotUp.Zero;
				this->Sprite.setTextureRect(sf::IntRect(this->Sprite.getTextureRect().left + 25, 0, 21, 16));
			}
		}
	}

	//TODO: 30 als Korrektur für Sprite Größe. Dynamisch programmieren?
	if (this->X <= 0)
		this->SetPosition(sf::Vector2f(0, this->Y));

	if (this->X >= game.window.getSize().x-30)
		this->SetPosition(sf::Vector2f(game.window.getSize().x - 30, this->Y));

	if (this->Y <= 0)
		this->SetPosition(sf::Vector2f(this->X, 0));

	if (this->Y >= game.window.getSize().y - 30)
		this->SetPosition(sf::Vector2f(this->X, game.window.getSize().y - 30));
}

void Player::UpdateShots(sf::Time Time, Game &game)
{
	std::list<Shot*>::iterator it = this->Shots.begin();

	while (it != this->Shots.end())
	{
		if ((*it)->isAlive())
		{
			(*it)->Update(Time);

			if ((*it)->X > game.window.getSize().x)
				(*it)->Kill();

			(*it)->Draw(game);
			it++;
		}
		else
		{

			it = this->Shots.erase(it);
		}
	}
}

void Player::Draw(Game &Game)
{
	Game.window.draw(this->Sprite);
}