#include <SFML\Graphics.hpp>


class Player
{
	public:
		Player();
		~Player();

		sf::Vector2f GetPosition();
		void SetPosition();

		int GetLeben();
		void SetLeben();

		bool Alive();

	private:
		sf::Vector2f _position;
		int _leben;
		bool _alive;

};