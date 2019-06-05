#include "LevelManager.h"
#include <iostream>
#include "Asteroid.h"
#include "Meteor.h"
LevelManager::LevelManager(std::vector<Entity*>* entitylist):entitylist(entitylist)
{
	
}

LevelManager::~LevelManager()
{
	std::cout << "LevelManager destructor" << std::endl;
	for (auto i = this->entitylist->begin(); i != this->entitylist->end(); i++)
	{
		delete (*i);
	}
	this->entitylist->clear();
}

void LevelManager::setLevel(short unsigned int levelToSet)
{
	switch (levelToSet)
	{
	case LEVEL1:
		spawnAsteroids(4);
		break;
	case LEVEL2:
		spawnAsteroids(5);
		spawnMeteors(1);
		break;
	case LEVEL3:
		spawnAsteroids(6);
		spawnMeteors(3);
		break;
	}
}

void LevelManager::spawnAsteroids(int count)
{
	for (int i = 0; i < count; i++)
	{
		this->entitylist->push_back(new Asteroid(rand() % 400, rand() % 400));
	}
}

void LevelManager::spawnMeteors(int count)
{
	for (int i = 0; i < count; i++)
	{
		this->entitylist->push_back(new Meteor(rand() % 400, rand() % 400));
	}
}


