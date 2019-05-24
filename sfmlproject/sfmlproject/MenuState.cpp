#include "MenuState.h"

MenuState::MenuState(RenderWindow* m_Window)
{
	this->stateName = "MenuState";
	this->m_Window = m_Window;

	//title
	TextureManager::getInstance()->loadFont("title","Assets/fonts/batmfa__.ttf");
	TextureManager::getInstance()->loadTexture("menuBG", "Assets/menu.png");
	text.setFont(TextureManager::getInstance()->fontMap["title"]);
	text.setString("Star Hopper");
	text.setCharacterSize(60);
	FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left+textRect.width/2,textRect.top+textRect.height/2);
	text.setPosition(this->m_Window->getSize().x / 2, (this->m_Window->getSize().y / 2)*0.5f);
	bg.setTexture(TextureManager::getInstance()->textureMap["menuBG"]);


	//buttons
	TextureManager::getInstance()->loadFont("buttons", "Assets/fonts/kenvector_future_thin.ttf");
	button = new Button("buttons", "Play",this->m_Window->getSize().x/2, this->m_Window->getSize().y / 2);
}

MenuState::~MenuState()
{
	std::cout << "MenuState destructor" << std::endl;
}

void MenuState::update()
{
	this->button->update();
}

void MenuState::render()
{
	this->m_Window->draw(bg);
	this->m_Window->draw(text);
	button->render(this->m_Window);
}


void MenuState::onExit()
{

}

void MenuState::MouseButtonPressed(const Vector2f& mouseViewPosition)
{
	if (this->button->containsVector(mouseViewPosition))
	{
		this->button->buttonPressed();
	}
}

void MenuState::MouseButtonReleased(const Vector2f& mouseViewPosition)
{
	if (this->button->containsVector(mouseViewPosition))
	{
		this->button->buttonReleased();
		setExit(true);
	}
}

void MenuState::KeyPressed(const Keyboard::Key& code)
{
}

void MenuState::KeyReleased(const Keyboard::Key& code)
{
}
