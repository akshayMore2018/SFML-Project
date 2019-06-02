#include "Button.h"
#include "TextureManager.h"
#include "AudioManager.h"
Button::Button(const std::string & ID,float x, float y,float width , float height)
{
	this->ID = ID;
	this->textPresent = false;
	this->rect.setSize(sf::Vector2f(width, height));
	this->rect.setOrigin(this->rect.getSize().x / 2, this->rect.getSize().y / 2);
	this->rect.setPosition(x, y);
	this->buttonState = IDLE;
	this->sound.setBuffer(AudioManager::getInstance()->soundBuffer["buttonPress"]);
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
	TextureManager::getInstance()->textureMap[this->offValue].setSmooth(true);
	TextureManager::getInstance()->textureMap[this->offValue].setSmooth(true);
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
	this->sound.play();
}

void Button::buttonReleased()
{
	while (this->sound.getStatus() == this->sound.Playing)
	{
		//noob way of delaying the program flow till sound finishes playing.
		//able to do this because sound plays on separate thread.
	}
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



