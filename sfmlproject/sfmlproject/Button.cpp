#include "Button.h"
#include "TextureManager.h"

Button::Button(const std::string& ID, const std::string& text, float x, float y)
{
	this->font = &(TextureManager::getInstance()->fontMap[ID]);
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(Color::Black);
	FloatRect textRect = this->text.getLocalBounds();
	this->text.setOrigin(textRect.left+textRect.width/2,textRect.top+textRect.height/2);
	this->text.setPosition(x, y);
	this->rect.setSize(sf::Vector2f(200, 50));
	this->rect.setOrigin(this->rect.getSize().x / 2, this->rect.getSize().y / 2);
	this->rect.setPosition(x, y);
	//this->rect.setFillColor(sf::Color::Transparent);
	this->buttonState = IDLE;
}



Button::~Button()
{

}

void Button::update(const Vector2f mousePosition)
{
	this->buttonState = IDLE;

	if (this->rect.getGlobalBounds().contains(mousePosition))
	{
		this->buttonState = HOVER;

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			this->buttonState = PRESSED;
		}
	}


	switch (buttonState)
	{
	case IDLE:
		this->rect.setFillColor(Color::White);
		break;
	case HOVER:
		this->rect.setFillColor(Color(108, 122, 137));
		break;
	case PRESSED:
		//this->rect.setFillColor(Color(46, 49, 49));
		break;
	}

}

void Button::render(RenderTarget * target)
{
	target->draw(rect);
	target->draw(this->text);
}

