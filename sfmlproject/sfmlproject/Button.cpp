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
}



Button::~Button()
{

}

void Button::update()
{
}

void Button::render(RenderTarget * target)
{
	target->draw(rect);
	target->draw(this->text);
}
