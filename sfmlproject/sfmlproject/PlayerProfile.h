#pragma once
#include <iostream>
class PlayerProfile
{
private:
	PlayerProfile();
	static PlayerProfile* instance;

public:
	static PlayerProfile* getInstance();
	int playerLives;
	int playerHP;
	int playerScore;
};