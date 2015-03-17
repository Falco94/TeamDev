#ifndef PLAYER_HPP
#define PLAYER_HPP


#include <SFML\Graphics.hpp>

class Player
{
	public:
		Player();
		~Player();

		sf::Vector2f GetPosition();
		void SetPosition();
		void Initialisiere();

		int GetLeben();
		void SetLeben();

		bool Alive();

	private:
		sf::Vector2f _position;
		sf::Texture _texture;
		int _leben;
		bool _alive;

};

#endif // !PLAYER_HPP