#include "UIButton.h"

UIButton::UIButton(TextureManager& manager): textureManager(manager), currentState(ButtonState::IDLE), pressedLastFrame(true)
{
}

void UIButton::initButton(const std::string& idleid, const std::string& hoverid)
{
	idleID = idleid;
	hoverID = hoverid;

	button.setTexture(textureManager.getTexture(idleid));
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

	if (button.getGlobalBounds().contains((Vector2f)mouseCords))
	{
		if (pressedNow && !pressedLastFrame)
			currentState = ButtonState::PRESSED;
		else
			currentState = ButtonState::HOVER;
	}
	else
		currentState = ButtonState::IDLE;

	switch (currentState)
	{
	case ButtonState::IDLE:
		button.setTexture(textureManager.getTexture(idleID));
		break;
	case ButtonState::HOVER:
		button.setTexture(textureManager.getTexture(hoverID));
		break;
	case ButtonState::PRESSED:
		button.setTexture(textureManager.getTexture(hoverID));
		break;
	}

	pressedLastFrame = pressedNow;
}

bool UIButton::isPressed()
{
	if (currentState == ButtonState::PRESSED)
	{
		// fire once per click, not every frame
		currentState = ButtonState::HOVER;
		return true;
	}
	return false;
}
