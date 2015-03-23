#include "Shot.h"

Shot::Shot(sf::Vector2f Position, int IndexDirection)
{
	if (!Textur.loadFromFile("C:\\Users\\Falco\\Documents\\Visual Studio 2013\\Projects\\TeamDev\\Textures\\Player\\shot.png"))
	{
		std::cout << "Fehler beim Laden der Textur";
	}

	_directions[0] = sf::Vector2f(1, 0);
	_directions[1] = sf::Vector2f(1, 1);
	_directions[2] = sf::Vector2f(1, -1);
	_directions[3] = sf::Vector2f(0, 1);
	_directions[4] = sf::Vector2f(0, -1);
	_directions[5] = sf::Vector2f(-1, 1);
	_directions[6] = sf::Vector2f(-1, -1);
	

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
	_direction = _directions[IndexDirection];
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
	this->Move(sf::Vector2f((this->GetSpeed()*Time.asSeconds())*this->_direction.x, 
		(this->GetSpeed()*Time.asSeconds())*this->_direction.y));
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