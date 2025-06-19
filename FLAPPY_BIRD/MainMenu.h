#ifndef MAINMENU_H
#define MAINMENU_H

#include "Menu.h"

class MainMenu : public Menu
{
private:

	TextureManager& textureManager;

	UIButton startButton;

	//Texture flappyBirdTexture;
	Sprite flappyBirdSprite;

	void initTextures();
	void adjustButtons();

public:
	MainMenu(TextureManager& manager);
	void init();

	void update(RenderWindow* window) override;
	void render(RenderWindow* window) override;

	bool start();
};

#endif 



