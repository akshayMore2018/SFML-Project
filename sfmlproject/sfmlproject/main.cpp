#include<iostream>
#include "Game.h"

int main()
{
	{
		Game game("nightmare", 720, 915);

		while (game.isRunning())
		{
			game.event();
			game.update();
			game.render();

		}
	}
}

	