#ifndef GAMEOVERMENU_H
#define GAMEOVERMENU_H

#include "Menu.h"
class GameOverMenu : public Menu
{
private:
	TextureManager& textureManager;
	UIButton restartButton, menuButton, exitButton;

	Sprite gameOverSprite;

	void initTextures();
	void adjustButtons();

public:
	GameOverMenu(TextureManager& manager);
	void init();

	void update(RenderWindow* window) override;
	void render(RenderWindow* window) override;

	bool restart();
	bool exit();
	bool menu();
};

#endif
