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
