#include "Shot.h"

Shot::Shot(sf::Vector2f Position)
{
	if (!Textur.loadFromFile("C:\\Users\\Falco\\Documents\\Visual Studio 2013\\Projects\\TeamDev\\Textures\\Player\\shot.png"))
	{
		std::cout << "Fehler beim Laden der Textur";
	}


	//// Erstellt eine neue Datei mit Transparenz
	//Image.loadFromFile("C:\\Users\\Falco\\Documents\\Visual Studio 2013\\Projects\\TeamDev\\Textures\\Player\\shot.png");
	//Image.createMaskFromColor(sf::Color(20, 70, 96));
	//Image.saveToFile("C:\\Users\\Falco\\Documents\\Visual Studio 2013\\Projects\\TeamDev\\Textures\\Player\\shot.png");
	

	Initialisiere();

	//_textur.setSmooth(true);
	Sprite.setTexture(Textur);
	Sprite.scale(2, 2);
	_position = Position;
	Sprite.setPosition(_position);
	X = _position.x;
	Y = _position.y;
}

Shot::~Shot()
{
}

void Shot::Initialisiere()
{
	_alive = true;
	_speed = 400.f;
}

void Shot::SetPosition(sf::Vector2f Position)
{
	Sprite.setPosition(Position);
	_position = Position;
	X = _position.x;
	Y = _position.y;
}

void Shot::Move(sf::Vector2f Offset)
{
	Sprite.move(Offset);
	_position += Offset;
	X = _position.x;
	Y = _position.y;
}

sf::Vector2f Shot::GetPosition()
{
	return _position;
}

float Shot::GetSpeed()
{
	return _speed;
}

void Shot::Update(sf::Time Time)
{
	this->Move(sf::Vector2f((this->GetSpeed()*Time.asSeconds()), 0));
}

bool Shot::isAlive()
{
	return _alive;
}

void Shot::Kill()
{
	_alive = false;
}

void Shot::Draw(Game &Game)
{
	Game.window.draw(this->Sprite);
}