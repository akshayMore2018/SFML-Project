#include<iostream>
#include "Game.h"
#include "SFML/Graphics.hpp"

int main()
{
	{
		Game game("nightmare", 480, 640);

		while (game.isRunning())
		{
			game.event();
			game.update();
			game.render();

		}
	}
}

	