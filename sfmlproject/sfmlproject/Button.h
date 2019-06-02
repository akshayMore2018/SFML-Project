#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
using namespace sf;
enum button_states{IDLE=0,PRESSED};

class Button
{
public:
	Button(const std::string & ID,float x, float y,float width, float height);
	~Button();

	void update();
	void render(RenderTarget* target);
	void buttonPressed();
	void buttonReleased();
	bool containsVector(const Vector2f& mousePosition);
	void setText(const std::string& ID, const std::string& text);
	void setTexture(const std::string& texID , const std::string& activeTexID);

	RectangleShape rect;

private:
	short unsigned int buttonState;
	const Font* font;
	Text text;
	
	bool textPresent;
	std::string offValue, onValue;
	std::string ID;
	Sound sound;
};

