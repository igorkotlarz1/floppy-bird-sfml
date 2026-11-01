#ifndef GAMEPLAYMENU_H
#define GAMEPLAYMENU_H

#include "Menu.h"

class GamePlayMenu : public Menu
{
private:
	TextureManager& textureManager;

	UIButton pauseButton;
	Text scoreText;

	void initTextures();
	void adjustButtons();

public:
	GamePlayMenu(TextureManager& manager);
	void init();
	void update(RenderWindow* window) override;
	void render(RenderWindow* window) override;

	bool pause();
};
#endif
