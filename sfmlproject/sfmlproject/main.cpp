#include<iostream>
#include "Game.h"
#include <fstream>

int main()
{
	{

		std::ifstream f("Config/window.ini");

		std::string title = "None";
		unsigned int width = 915;
		unsigned int height = 720;
		if (f.is_open())
		{
			std::getline(f,title);
			f >> width >> height;
		}
		else
		{
			std::cerr << "Error reading file" << std::endl;
		}
		f.close();
		Game game(title, height, width);

		while (game.isRunning())
		{
			game.event();
			game.update();
			game.render();

		}
	}
}

	