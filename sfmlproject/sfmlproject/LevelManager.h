#pragma once
#include <iostream>
#include <vector>

class Entity;
class LevelManager
{
public:
	LevelManager(std::vector<Entity*>* entitylist);
	~LevelManager();
	
	enum LEVELS
	{
		LEVEL1,
		LEVEL2,
		LEVEL3
	};
	
	short unsigned int currentLevel;
	void setLevel(short unsigned int levelToSet);
private:
	void spawnAsteroids(int count);
	void spawnMeteors(int count);
	std::vector<Entity*>* entitylist;
};