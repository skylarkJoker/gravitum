#include <iostream>
#include <string>

#include "DrawBox.hpp"
#include "Game.hpp"

int main()
{
	try
	{
    Game game;
    game.run();
	}
	catch (const std::exception& e)
	{
		std::cout << "\nException: " << e.what() << std::endl;
	}
    return EXIT_SUCCESS;
}
