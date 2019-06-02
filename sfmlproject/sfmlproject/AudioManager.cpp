#include "AudioManager.h"
#include <iostream>
AudioManager* AudioManager::instance = 0;
AudioManager::AudioManager()
{
}

void AudioManager::loadSound(const std::string & ID, const std::string & file)
{
	if (!this->soundBuffer[ID].loadFromFile(file))
	{
		std::cout << "Failed to load :" << file << std::endl;
	}
	else
	{
		std::cout << "loaded :" << file << std::endl;
	}
}

void AudioManager::loadMusic(const std::string & ID, const std::string & file)
{
	if (!this->MusicMap[ID].openFromFile(file))
	{
		std::cout << "Failed to load :" << file << std::endl;
	}
	else
	{
		std::cout << "loaded :" << file << std::endl;
	}
}

AudioManager * AudioManager::getInstance()
{
	if (instance == nullptr)
		instance = new AudioManager();
	return instance;
}
