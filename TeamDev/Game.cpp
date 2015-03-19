#include "Game.h"

Game::Game()
{
	window.create(sf::VideoMode(1280, 720), "Test");
	running = true;
}

void Game::Run()
{

}

bool Game::isRunning()
{
	return running;
}