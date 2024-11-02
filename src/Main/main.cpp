#include "game.hpp"

int main()
{
	
	game_ns::Game* game = game_ns::Game::getInstance();
	game->play();
	return 0;
}
