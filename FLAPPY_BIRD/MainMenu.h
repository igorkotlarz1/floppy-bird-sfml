#ifndef MAINMENU_H
#define MAINMENU_H

#include "Menu.h"

class MainMenu : public Menu
{
private:
	UIButton startButton, scoreButton;
	Texture flappyBirdTexture;
	Sprite flappyBirdSprite;

	void initTextures();
	void adjustButtons();

public:
	MainMenu();
	void update(RenderWindow* window) override;
	void render(RenderWindow* window) override;

	bool start();
	bool exit();
};

#endif 



