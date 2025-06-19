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
	Sprite button;

	std::string idleID, hoverID;
	Texture idleTexture, hoverTexture;

	ButtonState currentState;
	Vector2f position;
	bool pressedLastFrame;

	//referencja do managera
	TextureManager& textureManager;
public:
	
	UIButton();
	UIButton(TextureManager& manager);

	void initButton(const std::string& idlePath, const std::string& hoverPath, const Vector2f& pos);

	void initButton(const std::string& idleid, const std::string& hoverid, const Vector2f& pos);

	void setScale(const float x, const float y);
	void setPosition(float x, float y);
	void setOriginCenter();

	void render(RenderWindow* window);
	void update(RenderWindow* window);

	bool isPressed(); 
	
};

#endif

