#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include "Menu.h"

class PauseMenu : public Menu
{
private:

	TextureManager& textureManager;

	UIButton resumeButton, menuButton;

	Texture gameOverTexture;
	Sprite gameOverSprite;

	void initTextures();
	void adjustButtons();

public:
	PauseMenu(TextureManager& manager);
	void init();

	void update(RenderWindow* window) override;
	void render(RenderWindow* window) override;

	bool menu();
	bool resume();
};

#endif
