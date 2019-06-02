#include "GameOverScreen.h"
#include "TextureManager.h"
#include "Button.h"
#include "State.h"
#include "Game.h"
GameOverScreen::GameOverScreen(State* state)
{
	this->name = "GameOver";
	this->currentState = state;
	panel.setTexture(TextureManager::getInstance()->textureMap["window"]);

	Vector2u panelSize = TextureManager::getInstance()->textureMap["window"].getSize();
	panel.setOrigin(panelSize.x / 2, panelSize.y / 2);
	panel.setPosition( SCREEN_WIDTH/ 2, SCREEN_HEIGHT / 2);
	panel.setScale(0.5f, 0.5f);

	text.setFont(TextureManager::getInstance()->fontMap["title"]);
	this->text.setString("GAME OVER");
	FloatRect textRect = this->text.getLocalBounds();
	this->text.setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);
	text.setCharacterSize(32);
	text.setPosition(panel.getPosition().x, panel.getGlobalBounds().top + 40);


	restartButton = new Button("restart", panel.getGlobalBounds().left + 150, SCREEN_HEIGHT / 2 + 70, 100, 100);
	restartButton->setTexture("restartButton", "restartButtonSelected");

	closeButton = new Button("close", panel.getGlobalBounds().left + panel.getLocalBounds().width*0.5f - 150, SCREEN_HEIGHT / 2 + 70, 100, 100);
	closeButton->setTexture("closeButton", "closeButtonSelected");
}

GameOverScreen::~GameOverScreen()
{
	delete closeButton;
	delete restartButton;
}

void GameOverScreen::enter()
{
}

void GameOverScreen::update()
{
	this->restartButton->update();
	this->closeButton->update();
}

void GameOverScreen::render(RenderWindow * window)
{
	window->draw(this->panel);
	window->draw(this->text);
	this->closeButton->render(window);
	this->restartButton->render(window);
}

void GameOverScreen::MouseButtonPressed(const Vector2f & mouseViewPosition)
{
	if (this->closeButton->containsVector(mouseViewPosition))
	{
		this->closeButton->buttonPressed();
	}

	if (this->restartButton->containsVector(mouseViewPosition))
	{
		this->restartButton->buttonPressed();
	}
}

void GameOverScreen::MouseButtonReleased(const Vector2f & mouseViewPosition)
{
	this->restartButton->buttonReleased();
	this->closeButton->buttonReleased();
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
	
}

void GameOverScreen::KeyPressed(const Keyboard::Key & code)
{
}

void GameOverScreen::KeyReleased(const Keyboard::Key & code)
{
}

void GameOverScreen::exit()
{
}
