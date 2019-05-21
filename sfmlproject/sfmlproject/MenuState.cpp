#include "MenuState.h"

MenuState::MenuState()
{
	if (!font.loadFromFile("Assets/fonts/batmfa__.ttf"))
	{
		std::cout << "Could not load font file" << std::endl;
		system("pause");
	}
	text.setFont(font);
	text.setString("Star Hopper");
	text.setCharacterSize(60);
	FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left+textRect.width/2,textRect.top+textRect.height/2);
	text.setPosition(915 / 2, (720 / 2)*0.5f);

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
	m_Window->draw(text);
}

void MenuState::events(const Event & m_Event)
{
	switch (m_Event.type)
	{
	case Event::KeyPressed:
		if (m_Event.key.code == Keyboard::N)
		{
			setExit(true);
		}
		break;
	}
}

void MenuState::onExit()
{
}
