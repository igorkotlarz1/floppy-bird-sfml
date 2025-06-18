#ifndef GAMEOVERMENU_H
#define GAMEOVERMENU_H

#include "Menu.h"
class GameOverMenu : public Menu
{
private:
	UIButton restartButton, menuButton, exitButton;
	Texture gameOverTexture;
	Sprite gameOverSprite;

	void initTextures();
	void adjustButtons();

public:
	GameOverMenu();

	void update(RenderWindow* window) override;
	void render(RenderWindow* window) override;

	bool restart();
	bool exit();
	bool menu();
};

#endif 



