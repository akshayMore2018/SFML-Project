#pragma once
#include <iostream>


class PlayerProfile
{
private:
	PlayerProfile();
	static PlayerProfile* instance;

public:
	enum playerState 
	{ 
		WON, 
		LOST, 
		PLAYING, 
		DIED,
	};

	enum playerWeapon
	{
		BLUE_FLAME,
		RED_FLAME,
		PINK_FLAME,
	};
	static PlayerProfile* getInstance();
	int playerLives;
	int playerHP;
	int playerScore;
	short unsigned int playerState;
	short unsigned int currentPlayerWeapon;
};