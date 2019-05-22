#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
class Button
{
public:
	Button(const std::string& ID, const std::string& text, float x, float y);
	~Button();

	void update();
	void render(RenderTarget* target);

private:
	const Font* font;
	Text text;
	RectangleShape rect;
};