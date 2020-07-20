#include <iostream>
#include <string>

#include "DrawBox.h"
#include "Game.h"

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
