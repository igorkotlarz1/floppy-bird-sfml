#include "UIButton.h"

UIButton::UIButton() : currentState(ButtonState::IDLE), pressedLastFrame(true)
{
}

UIButton::UIButton(TextureManager& manager)
{
}

void UIButton::initButton(const std::string& idlePath, const std::string& hoverPath, const Vector2f& pos)
{
	if (!idleTexture.loadFromFile(idlePath) || !hoverTexture.loadFromFile(hoverPath))
		std::cout << "ERROR: failed to load UIButton textures!" << std::endl;

	button.setTexture(idleTexture);
	button.setPosition(pos);
	position = pos;
}

void UIButton::setScale(const float x, const float y)
{
	button.setScale(x, y);
}

void UIButton::setPosition(float x, float y)
{
	button.setPosition(x, y);
}

void UIButton::setOriginCenter()
{
	auto bounds = button.getLocalBounds();
	button.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void UIButton::render(RenderWindow* window)
{
	window->draw(button);	
}

void UIButton::update(RenderWindow* window)
{
	auto mouseCords = Mouse::getPosition(*window);
	bool pressedNow = Mouse::isButtonPressed(Mouse::Left);

	if (button.getGlobalBounds().contains((Vector2f)mouseCords)) //button.getGlobalBounds().contains((Vector2f)mouseCords)
	{
		if (pressedNow && !pressedLastFrame) 
		{
			currentState = ButtonState::PRESSED;
		}
		else
			currentState = ButtonState::HOVER;
	}
	else
		currentState = ButtonState::IDLE;

	switch (currentState)
	{
	case ButtonState::IDLE:
		button.setTexture(idleTexture);
		break;
	case ButtonState::HOVER:
		button.setTexture(hoverTexture);
		break;
	case ButtonState::PRESSED:
		button.setTexture(hoverTexture);
		break;
	}	

	pressedLastFrame = pressedNow;
}

bool UIButton::isPressed() 
{
	//return currentState == ButtonState::PRESSED ? true : false;
	if (currentState == ButtonState::PRESSED)
	{
		//eliminacja wielokrotnego klikniecia
		currentState = ButtonState::HOVER;
		return true;
	}
	return false;
}


