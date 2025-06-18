#include "Button.h"


void Button::initButton(const Vector2f& pos, const Vector2f& size)
{
	button.setPosition(pos);
	button.setSize(size);

	//Wycentrowanie napisu
	auto buttonSize = button.getSize();
	auto textBounds = text.getLocalBounds();

	text.setOrigin(textBounds.left + textBounds.width / 2.f, textBounds.top+ textBounds.height / 2.f);
	text.setPosition(pos.x + buttonSize.x / 2.f, pos.y + buttonSize.y / 2.f);
	//text.setCharacterSize(size.y * 0.3f);
}

void Button::initText(const std::string& label, Font& font)
{
	text.setFillColor(Color::Black);	
	text.setFont(font);	
	text.setString(label);
	text.setCharacterSize(12);
}

void Button::setColors()
{
	idleColor = Color(224, 224, 224);
	hoverColor = Color(252, 252, 252);
	outlineColor = Color(145, 145, 145);

	button.setFillColor(idleColor);
	button.setOutlineColor(outlineColor);
	button.setOutlineThickness(2.f);	
}

//KONSTRUKTOR
Button::Button(const std::string& label, Font& font, const Vector2f& pos, const Vector2f& size) 
{
	initText(label, font);
	initButton(pos, size);
	setColors();
}

Button::Button()
{

}


void Button::render(RenderWindow* window)
{
	window->draw(button);
	window->draw(text);
}

void Button::update(RenderWindow* window)
{
	auto mouseCords = Mouse::getPosition(*window);

	if (button.getGlobalBounds().contains((Vector2f)mouseCords))
	{
		button.setFillColor(hoverColor);
	}
	else 
	{
		button.setFillColor(idleColor);
	}
}
bool Button::isHovered(RenderWindow* window)
{
	auto mouseCords = Mouse::getPosition(*window);

	return button.getGlobalBounds().contains((Vector2f)mouseCords);
}

