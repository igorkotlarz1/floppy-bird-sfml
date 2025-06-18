#ifndef BUTTON_H
#define BUTTON_H

#include "Definitions.h"

class Button
{
private:
	sf::RectangleShape button;
	sf::Text text;

	Color idleColor, hoverColor, outlineColor;

	void initButton(const Vector2f& pos, const Vector2f& size);
	void initText(const std::string& label, Font& font);
	void setColors();


public:

	Button(const std::string& label, Font& font, const Vector2f& pos, const Vector2f& size);
	Button();

	void render(RenderWindow* window);
	void update(RenderWindow* window);
	bool isHovered(RenderWindow* window);

};
#endif
