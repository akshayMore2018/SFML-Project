#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
enum button_states{IDLE=0,PRESSED};

class Button
{
public:
	Button(const std::string& ID, const std::string& text, float x, float y);
	~Button();

	void update();
	void render(RenderTarget* target);
	void buttonPressed();
	void buttonReleased();
	bool containsVector(const Vector2f& mousePosition);

private:
	short unsigned int buttonState;
	const Font* font;
	Text text;
	RectangleShape rect;
};

