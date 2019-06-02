#pragma once
#include <map>
#include "SFML/Audio.hpp"
using namespace sf;
class AudioManager
{
private:
	static AudioManager* instance;
	AudioManager();
	

public:
	static AudioManager* getInstance();
	void loadSound(const std::string& ID, const std::string& file);
	void loadMusic(const std::string& ID, const std::string& file);
	std::map<std::string, SoundBuffer> soundBuffer;
	std::map<std::string, Music> MusicMap;
};