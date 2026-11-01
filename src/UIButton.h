#ifndef UIBUTTON_H
#define UIBUTTON_H

#include "Definitions.h"
#include "TextureManager.h"

enum class ButtonState
{
	IDLE = 0,
	HOVER,
	PRESSED
};

class UIButton
{
private:
	TextureManager& textureManager;
	Sprite button;

	std::string idleID, hoverID;

	ButtonState currentState;
	Vector2f position;
	bool pressedLastFrame;

public:
	UIButton(TextureManager& manager);

	void initButton(const std::string& idleid, const std::string& hoverid);

	void setScale(const float x, const float y);
	void setPosition(float x, float y);
	void setOriginCenter();

	void render(RenderWindow* window);
	void update(RenderWindow* window);

	bool isPressed();

};

#endif
