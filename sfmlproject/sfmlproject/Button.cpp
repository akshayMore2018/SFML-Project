#include "Button.h"
#include "TextureManager.h"

Button::Button(const std::string & ID,float x, float y,float width , float height)
{
	this->ID = ID;
	this->textPresent = false;
	this->rect.setSize(sf::Vector2f(width, height));
	this->rect.setOrigin(this->rect.getSize().x / 2, this->rect.getSize().y / 2);
	this->rect.setPosition(x, y);
	this->buttonState = IDLE;
}



Button::~Button()
{
	std::cout << "Button destructor" << std::endl;
}


void Button::setText(const std::string & ID, const std::string & text)
{
	this->font = &(TextureManager::getInstance()->fontMap[ID]);
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(Color::Black);
	FloatRect textRect = this->text.getLocalBounds();
	this->text.setOrigin(textRect.left + textRect.width / 2, textRect.top + textRect.height / 2);
	this->text.setPosition(this->rect.getPosition().x, this->rect.getPosition().y);
	this->textPresent = true;
}

void Button::setTexture(const std::string & texID, const std::string& activeTexID)
{
	this->onValue = activeTexID;
	this->offValue = texID;
	this->rect.setTexture(&(TextureManager::getInstance()->textureMap[this->offValue]));
}

void Button::update()
{

}

void Button::render(RenderTarget * target)
{
	target->draw(rect);
	if(this->textPresent)
		target->draw(this->text);
}

void Button::buttonPressed()
{
	this->buttonState = PRESSED;
	this->rect.setTexture(&(TextureManager::getInstance()->textureMap[this->onValue]));
}

void Button::buttonReleased()
{
	this->buttonState = IDLE;
	this->rect.setTexture(&(TextureManager::getInstance()->textureMap[this->offValue]));
	
}

bool Button::containsVector(const Vector2f & mousePosition)
{
	if (this->rect.getGlobalBounds().contains(mousePosition))
	{
		return true;
	}
	return false;
}



