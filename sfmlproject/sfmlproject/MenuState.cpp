#include "MenuState.h"

MenuState::MenuState()
{

	//title
	TextureManager::getInstance()->loadFont("title","Assets/fonts/batmfa__.ttf");
	TextureManager::getInstance()->loadTexture("menuBG", "Assets/menu.jpg");
	text.setFont(TextureManager::getInstance()->fontMap["title"]);
	text.setString("Star Hopper");
	text.setCharacterSize(60);
	FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left+textRect.width/2,textRect.top+textRect.height/2);
	text.setPosition(915 / 2, (720 / 2)*0.5f);
	bg.setTexture(TextureManager::getInstance()->textureMap["menuBG"]);


	//buttons
	TextureManager::getInstance()->loadFont("buttons", "Assets/fonts/kenvector_future_thin.ttf");
	button = new Button("buttons", "Play", 915 / 2, 720 / 2);
}

MenuState::~MenuState()
{
	std::cout << "MenuState destructor" << std::endl;
}

void MenuState::update()
{
	
}

void MenuState::render(RenderWindow * m_Window)
{
	m_Window->draw(bg);
	m_Window->draw(text);
	button->render(m_Window);
}

void MenuState::handleInputs()
{
	if (Keyboard::isKeyPressed(Keyboard::P))
	{
		setExit(true);
	}

}

void MenuState::onExit()
{
}
