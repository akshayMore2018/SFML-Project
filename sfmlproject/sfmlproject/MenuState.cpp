#include "MenuState.h"
#include "GameState.h"
#include "Game.h"
#include "AudioManager.h"
MenuState::MenuState(RenderWindow* m_Window, Game* game)
{
	this->stateName = "MenuState";
	this->m_Window = m_Window;
	this->game = game;	

	if (!TextureManager::getInstance()->textureMap.count("menuBG") == 1)
	{
		std::cout << "loading menu assets" << std::endl;
		TextureManager::getInstance()->loadFont("title", "Assets/fonts/batmfa__.ttf");
		TextureManager::getInstance()->loadTexture("menuBG", "Assets/gui/menu/menu.png");
		TextureManager::getInstance()->loadTexture("startButton", "Assets/gui/menu/Start_BTN.png");
		TextureManager::getInstance()->loadTexture("exitButton", "Assets/gui/menu/Exit_BTN.png");
		TextureManager::getInstance()->loadTexture("titlePanel", "Assets/gui/menu/titlePanel.png");
	}
	else
	{
		std::cout << "Menu assets already loaded" << std::endl;
	}
	if (!AudioManager::getInstance()->soundBuffer.count("buttonPress") == 1)
	{
		std::cout << "loading sounds...." << std::endl;
		AudioManager::getInstance()->loadSound("buttonPress", "Assets/sounds/buttonClick.wav");
	}
	else
	{
		std::cout << "Sounds already loaded" << std::endl;
	}
	
	bg.setTexture(TextureManager::getInstance()->textureMap["menuBG"]);
	TextureManager::getInstance()->textureMap["titlePanel"].setSmooth(true);
	titlePanel.setTexture(TextureManager::getInstance()->textureMap["titlePanel"]);
	titlePanel.setPosition(SCREEN_W / 2, (SCREEN_H / 2)*0.5f);
	titlePanel.setOrigin(TextureManager::getInstance()->textureMap["titlePanel"].getSize().x/2, TextureManager::getInstance()->textureMap["titlePanel"].getSize().y / 2);
	titlePanel.setScale(0.8f, 0.6f);
	titlePanel.setColor(sf::Color(255, 255, 255, 180));

	text.setFont(TextureManager::getInstance()->fontMap["title"]);
	text.setString("Star Hopper");
	text.setCharacterSize(60);
	FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);
	text.setPosition(titlePanel.getPosition().x,titlePanel.getPosition().y);


	//buttons
	startButton = new Button("Start",this->m_Window->getSize().x/2, this->titlePanel.getPosition().y + 300, 220, 60);
	startButton->setTexture("startButton", "startButton");

	exitButton = new Button("Exit", this->m_Window->getSize().x / 2, this->titlePanel.getPosition().y + 400, 220, 60);
	exitButton->setTexture("exitButton", "exitButton");

}

MenuState::~MenuState()
{
	std::cout << "MenuState destructor" << std::endl;
	delete startButton;
	delete exitButton;
}

void MenuState::update()
{
	this->startButton->update();
	this->exitButton->update();

}

void MenuState::render()
{
	this->m_Window->draw(bg);
	this->m_Window->draw(titlePanel);
	this->m_Window->draw(text);
	startButton->render(this->m_Window);
	exitButton->render(this->m_Window);
}


void MenuState::onExit(const std::string& nextStateID)
{

}

void MenuState::MouseButtonPressed(const Vector2f& mouseViewPosition)
{
	if (this->startButton->containsVector(mouseViewPosition))
	{
		this->startButton->buttonPressed();
		this->startButton->rect.setFillColor(Color(255, 200, 0));
	}


	if (this->exitButton->containsVector(mouseViewPosition))
	{
		this->exitButton->buttonPressed();
		this->exitButton->rect.setFillColor(Color(255, 200, 0));
	}
}

void MenuState::MouseButtonReleased(const Vector2f& mouseViewPosition)
{
	this->startButton->rect.setFillColor(Color(255, 255, 255));
	this->exitButton->rect.setFillColor(Color(255, 255, 255));
	if (this->exitButton->containsVector(mouseViewPosition))
	{
		this->exitButton->buttonReleased();
		this->exitButton->rect.setFillColor(Color(255, 255, 255));
		this->game->changeState("null");
	}

	else if (this->startButton->containsVector(mouseViewPosition))
	{
		this->startButton->buttonReleased();
		this->startButton->rect.setFillColor(Color(255,255,255));
		this->game->changeState("GameState");
	}
}

void MenuState::KeyPressed(const Keyboard::Key& code)
{
	
}

void MenuState::KeyReleased(const Keyboard::Key& code)
{
}
