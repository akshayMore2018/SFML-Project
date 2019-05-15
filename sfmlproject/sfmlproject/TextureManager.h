#pragma once
#include<iostream>
#include "SFML/Graphics.hpp"
#include <map>
class TextureManager
{
	static TextureManager* instance;
	TextureManager();


public:
	static TextureManager* getInstance();

	std::map<std::string, sf::Texture> textureMap;
};

