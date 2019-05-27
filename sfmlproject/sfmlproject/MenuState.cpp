#include "MenuState.h"
#include "GameState.h"
MenuState::MenuState(RenderWindow* m_Window, std::stack<State*>* states)
{
	this->stateName = "MenuState";
	this->m_Window = m_Window;
	this->states = states;	
	TextureManager::getInstance()->loadFont("title", "Assets/fonts/batmfa__.ttf");
	TextureManager::getInstance()->loadTexture("menuBG", "Assets/gui/menu/menu.png");
	TextureManager::getInstance()->loadTexture("startButton", "Assets/gui/menu/Start_BTN.png");
	TextureManager::getInstance()->loadTexture("exitButton", "Assets/gui/menu/Exit_BTN.png");
		
	text.setFont(TextureManager::getInstance()->fontMap["title"]);
	text.setString("Star Hopper");
	text.setCharacterSize(60);
	FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left+textRect.width/2,textRect.top+textRect.height/2);
	text.setPosition(SCREEN_W/2, (SCREEN_H/ 2)*0.5f);
	bg.setTexture(TextureManager::getInstance()->textureMap["menuBG"]);

	//buttons
	startButton = new Button("Start",this->m_Window->getSize().x/2, this->m_Window->getSize().y / 2, 220, 60);
	startButton->setTexture("startButton", "startButton");

	exitButton = new Button("Exit", this->m_Window->getSize().x / 2, this->m_Window->getSize().y / 2 + 100, 220, 60);
	exitButton->setTexture("exitButton", "exitButton");

}

MenuState::~MenuState()
{
	std::cout << "MenuState destructor" << std::endl;
	delete startButton;
	delete exitButton;

	m_Window->close();
}

void MenuState::update()
{
	this->startButton->update();
	this->exitButton->update();

}

void MenuState::render()
{
	this->m_Window->draw(bg);
	this->m_Window->draw(text);
	startButton->render(this->m_Window);
	exitButton->render(this->m_Window);
}


void MenuState::onExit()
{

}

void MenuState::MouseButtonPressed(const Vector2f& mouseViewPosition)
{
	if (this->startButton->containsVector(mouseViewPosition))
	{
		this->startButton->buttonPressed();
	}


	if (this->exitButton->containsVector(mouseViewPosition))
	{
		this->exitButton->buttonPressed();
	}
}

void MenuState::MouseButtonReleased(const Vector2f& mouseViewPosition)
{
	if (this->startButton->containsVector(mouseViewPosition))
	{
		this->startButton->buttonReleased();
		this->states->push(new GameState(this->m_Window, this->states));
		
	}

	if (this->exitButton->containsVector(mouseViewPosition))
	{
		this->exitButton->buttonReleased();
		setExit(true);
	}
}

void MenuState::KeyPressed(const Keyboard::Key& code)
{
	if (code == Keyboard::Escape)
	{
		setExit(true);
	}
}

void MenuState::KeyReleased(const Keyboard::Key& code)
{
}
