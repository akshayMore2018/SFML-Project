#include<iostream>
#include "Game.h"

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

	