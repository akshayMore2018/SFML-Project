#include "PauseScreen.h"
#include "TextureManager.h"
#include "Button.h"
#include "State.h"
#include "Game.h"
#include "PlayerProfile.h"
PauseScreen::PauseScreen(State* state)
{
	this->name = "Pause";
	this->currentState = state;
	panel.setTexture(TextureManager::getInstance()->textureMap["window"]);
	header.setTexture(TextureManager::getInstance()->textureMap["pauseHeader"]);
	TextureManager::getInstance()->textureMap["scoreImg"].setSmooth(true);
	score.setTexture(TextureManager::getInstance()->textureMap["scoreImg"]);
	Vector2u panelSize = TextureManager::getInstance()->textureMap["window"].getSize();
	panel.setOrigin(panelSize.x / 2, panelSize.y / 2);
	panel.setPosition(SCREEN_W/2,SCREEN_H/2);
	panel.setScale(0.5f, 0.5f);

	Vector2u headerSize = TextureManager::getInstance()->textureMap["pauseHeader"].getSize();
	header.setOrigin(headerSize.x / 2, headerSize.y / 2);
	header.setPosition(panel.getPosition().x, panel.getGlobalBounds().top+40);
	header.setScale(0.5f, 0.5f);

	Vector2u scoreSize = TextureManager::getInstance()->textureMap["scoreImg"].getSize();
	score.setOrigin(scoreSize.x / 2, scoreSize.y / 2);
	score.setPosition(panel.getPosition().x, panel.getGlobalBounds().top + 150);
	score.setScale(0.55f, 0.55f);

	text.setFont(TextureManager::getInstance()->fontMap["title"]);
	ss.str("");
	ss << PlayerProfile::getInstance()->playerScore;
	this->text.setString(ss.str());
	FloatRect textRect = this->text.getLocalBounds();
	this->text.setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);
	text.setCharacterSize(32);
	text.setPosition(score.getPosition().x, score.getPosition().y+40);

	resumeButton = new Button("resume",panel.getGlobalBounds().left+110, SCREEN_HEIGHT/2+ 70,100,100);
	resumeButton->setTexture("playButton", "playButtonSelected");

	restartButton = new Button("restart", SCREEN_WIDTH/2, SCREEN_HEIGHT / 2 + 70, 100, 100);
	restartButton->setTexture("restartButton", "restartButtonSelected");

	closeButton = new Button("close", panel.getGlobalBounds().left + panel.getLocalBounds().width*0.5f-110, SCREEN_HEIGHT / 2 + 70, 100, 100);
	closeButton->setTexture("closeButton", "closeButtonSelected");

}

PauseScreen::~PauseScreen()
{
	delete resumeButton;
	delete closeButton;
	delete restartButton;
}

void PauseScreen::enter()
{
	std::cout << "Pause Screen Entered" << std::endl;
	ss.str("");
	ss << PlayerProfile::getInstance()->playerScore;
	this->text.setString(ss.str());
}

void PauseScreen::update()
{
	this->resumeButton->update();
	this->restartButton->update();
	this->closeButton->update();
}

void PauseScreen::render(RenderWindow* window)
{
	window->draw(this->panel);
	window->draw(this->header);
	window->draw(this->score);
	window->draw(this->text);
	this->resumeButton->render(window);
	this->closeButton->render(window);
	this->restartButton->render(window);

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

	if (this->restartButton->containsVector(mouseViewPosition))
	{
		this->restartButton->buttonPressed();
	}
}

void PauseScreen::MouseButtonReleased(const Vector2f & mouseViewPosition)
{
	if (this->resumeButton->containsVector(mouseViewPosition))
	{
		this->currentState->setScreen(nullptr);
	}

	if (this->restartButton->containsVector(mouseViewPosition))
	{
		
		this->currentState->setScreen(nullptr);
		this->currentState->game->changeState("GameState");
		return;
	}

	if (this->closeButton->containsVector(mouseViewPosition))
	{
		
		this->currentState->setScreen(nullptr);
		this->currentState->game->changeState("MenuState");
		return;
	}
	this->resumeButton->buttonReleased();
	this->restartButton->buttonReleased();
	this->closeButton->buttonReleased();
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
