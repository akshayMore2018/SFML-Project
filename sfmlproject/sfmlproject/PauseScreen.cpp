#include "PauseScreen.h"
#include "TextureManager.h"

PauseScreen::PauseScreen()
{
	this->name = "Pause";
	panel.setTexture(TextureManager::getInstance()->textureMap["pauseWindow"]);
	header.setTexture(TextureManager::getInstance()->textureMap["pauseHeader"]);
	Vector2u panelSize = TextureManager::getInstance()->textureMap["pauseWindow"].getSize();
	panel.setOrigin(panelSize.x / 2, panelSize.y / 2);
	panel.setPosition(915/2,720/2);
	panel.setScale(0.5f, 0.5f);

	Vector2u headerSize = TextureManager::getInstance()->textureMap["pauseHeader"].getSize();
	header.setOrigin(headerSize.x / 2, headerSize.y / 2);
	header.setPosition(panel.getPosition().x, panel.getGlobalBounds().top+40);
	header.setScale(0.5f, 0.5f);
}

PauseScreen::~PauseScreen()
{
}

void PauseScreen::enter()
{
	std::cout << "Pause Screen Entered" << std::endl;
}

void PauseScreen::update()
{
	
}

void PauseScreen::render(RenderWindow* window)
{
	window->draw(this->panel);
	window->draw(this->header);
}

void PauseScreen::exit()
{
	std::cout << "Pause Screen Exit" << std::endl;
}
