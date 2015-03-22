#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Shot.h"
#include <SFML\Graphics.hpp>
#include <list>

class Player
{
	public:
		Player(sf::Vector2f Position);
		~Player();

		std::list<Shot*> Shots;

		sf::Vector2f GetPosition();
		void SetPosition(sf::Vector2f);
		void Move(sf::Vector2f);
		float X;
		float Y;
		void Initialisiere();
		void Update(sf::Time Time, Game &game);
		void UpdateShots(sf::Time Time, Game &game);

		float GetSpeed();
		void SetSpeed(float Speed);

		int GetLeben();
		void SetLeben(int Leben);

		bool Alive();

		void Draw(Game &Game);

		sf::Sprite Sprite;
		sf::Image Image;
		sf::Texture Textur;

	private:
		sf::Vector2f _position;
		int _leben;
		int _maxLeben;
		bool _alive;
		float _speed;
		sf::Time _tempTimeUp;
		sf::Time _tempTimeDown;
		sf::Time _tempTimeNotUp;
		sf::Time _tempTimeNotDown;
		
};

#endif // !PLAYER_HPP