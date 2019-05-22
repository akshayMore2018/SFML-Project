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
	void loadTexture(const std::string& ID,const std::string& file);
	void loadFont(const std::string& ID, const std::string& file);

	std::map<std::string, sf::Texture> textureMap;
	std::map<std::string, sf::Font> fontMap;
};

