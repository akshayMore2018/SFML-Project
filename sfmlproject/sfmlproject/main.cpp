#include<iostream>
#include "Game.h"
#include "SFML/Graphics.hpp"

int main()
{
	{
		Game game("nightmare", 480, 600);

		while (game.isRunning())
		{
			game.event();
			game.update();
			game.render();

		}
	}
}

	