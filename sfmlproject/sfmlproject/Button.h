#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
enum button_states{IDLE=0,HOVER,PRESSED};

class Button
{
public:
	Button(const std::string& ID, const std::string& text, float x, float y);
	~Button();

	void update(const Vector2f mousePosition);
	void render(RenderTarget* target);
	inline const bool isPressed()const;
private:
	short unsigned int buttonState;
	const Font* font;
	Text text;
	RectangleShape rect;
};

inline const bool Button::isPressed() const
{
	if (this->buttonState == PRESSED)
		return true;
	return false;
}
