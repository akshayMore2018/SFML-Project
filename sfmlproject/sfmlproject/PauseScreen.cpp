#include "PauseScreen.h"
#include "TextureManager.h"
#include "Button.h"
#include "State.h"

PauseScreen::PauseScreen(State* state)
{
	this->name = "Pause";
	this->currentState = state;
	panel.setTexture(TextureManager::getInstance()->textureMap["pauseWindow"]);
	header.setTexture(TextureManager::getInstance()->textureMap["pauseHeader"]);
	Vector2u panelSize = TextureManager::getInstance()->textureMap["pauseWindow"].getSize();
	panel.setOrigin(panelSize.x / 2, panelSize.y / 2);
	panel.setPosition(SCREEN_W/2,SCREEN_H/2);
	panel.setScale(0.5f, 0.5f);

	Vector2u headerSize = TextureManager::getInstance()->textureMap["pauseHeader"].getSize();
	header.setOrigin(headerSize.x / 2, headerSize.y / 2);
	header.setPosition(panel.getPosition().x, panel.getGlobalBounds().top+40);
	header.setScale(0.5f, 0.5f);

	resumeButton = new Button("resume",panel.getGlobalBounds().left+120, SCREEN_H/2,100,100);
	resumeButton->setTexture("playButton", "playButtonSelected");

	closeButton = new Button("close", panel.getGlobalBounds().left + panel.getLocalBounds().width*0.5f-120, SCREEN_H / 2, 100, 100);
	closeButton->setTexture("closeButton", "closeButtonSelected");

}

PauseScreen::~PauseScreen()
{
	delete resumeButton;
	delete closeButton;
}

void PauseScreen::enter()
{
	std::cout << "Pause Screen Entered" << std::endl;
}

void PauseScreen::update()
{
	this->resumeButton->update();
	this->closeButton->update();
}

void PauseScreen::render(RenderWindow* window)
{
	window->draw(this->panel);
	window->draw(this->header);
	this->resumeButton->render(window);
	this->closeButton->render(window);

}

void PauseScreen::MouseButtonPressed(const Vector2f & mouseViewPosition)
{
	if (this->resumeButton->containsVector(mouseViewPosition))
	{
		this->resumeButton->buttonPressed();
	}

	if (this->closeButton->containsVector(mouseViewPosition))
	{
		this->closeButton->buttonPressed();
	}
}

void PauseScreen::MouseButtonReleased(const Vector2f & mouseViewPosition)
{
	if (this->resumeButton->containsVector(mouseViewPosition))
	{
		this->resumeButton->buttonReleased();
		this->currentState->setScreen(nullptr);
	}

	if (this->closeButton->containsVector(mouseViewPosition))
	{
		this->closeButton->buttonReleased();
		this->currentState->setScreen(nullptr);
		this->currentState->setExit(true);
	}
}

void PauseScreen::KeyPressed(const Keyboard::Key & code)
{
}

void PauseScreen::KeyReleased(const Keyboard::Key & code)
{
	
}

void PauseScreen::exit()
{
	std::cout << "Pause Screen Exit" << std::endl;
}
