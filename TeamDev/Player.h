#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML\Graphics.hpp>

class Player
{
	public:
		Player(sf::Vector2f Position);
		~Player();

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

		sf::Sprite Sprite;
		sf::Image Image;

	private:
		sf::Vector2f _position;
		int _leben;
		int _maxLeben;
		bool _alive;
		float _speed;
		sf::Texture _textur;

};

#endif // !PLAYER_HPP