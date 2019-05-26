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

void TextureManager::loadTexture(const std::string& ID,const std::string & file)
{
	if (!textureMap[ID].loadFromFile(file))
	{
		std::cout << "Couldn't load file :" << file << std::endl;
	}
	else
	{
		std::cout << "loaded :" << file << std::endl;
	}
}

void TextureManager::loadFont(const std::string & ID, const std::string & file)
{
	if (!fontMap[ID].loadFromFile(file))
	{
		std::cout << "Couldn't load file :" << file << std::endl;
		system("pause");
	}
}
