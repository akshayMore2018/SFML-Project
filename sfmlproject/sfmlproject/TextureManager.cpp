#include "TextureManager.h"
TextureManager* TextureManager::instance = 0;
TextureManager::TextureManager()
{
}

TextureManager * TextureManager::getInstance()
{
	if (!instance) {
		instance = new TextureManager();
	}
	return instance;
}

void TextureManager::load(const std::string& ID,const std::string & file)
{
	if (!textureMap[ID].loadFromFile(file))
	{
		std::cout << "Couldn't load file :" << file << std::endl;
	}
}
