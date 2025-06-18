#ifndef UIBUTTON_H
#define UIBUTTON_H

#include "Definitions.h"

enum class ButtonState
{
	IDLE = 0,
	HOVER,
	PRESSED
};

class UIButton
{
private:
	Sprite button;
	Texture idleTexture, hoverTexture;

	ButtonState currentState;
	Vector2f position;
	bool pressedLastFrame;

public:
	
	UIButton();

	void initButton(const std::string& idlePath, const std::string& hoverPath, const Vector2f& pos);
	void setScale(const float x, const float y);
	void setPosition(float x, float y);
	void setOriginCenter();

	void render(RenderWindow* window);
	void update(RenderWindow* window);

	bool isPressed(); 
	
};

#endif

