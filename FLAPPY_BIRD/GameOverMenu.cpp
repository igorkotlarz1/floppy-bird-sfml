#include "GameOverMenu.h"

GameOverMenu::GameOverMenu(TextureManager& manager) : textureManager(manager), restartButton(manager), menuButton(manager), exitButton(manager)
{
	
}

void GameOverMenu::init()
{
	initTextures();
	adjustButtons();
}

void GameOverMenu::initTextures()
{
	gameOverSprite.setTexture(textureManager.getTexture("GAMEOVER"));

	restartButton.initButton("PLAY", "PLAY_HV");
	menuButton.initButton("MENU", "MENU_HV");
	exitButton.initButton("OK", "OK_HV");
}

void GameOverMenu::update(RenderWindow* window)
{
	restartButton.update(window);
	menuButton.update(window);
	exitButton.update(window);
}
void GameOverMenu::render(RenderWindow* window)
{
	window->draw(gameOverSprite);
	restartButton.render(window);
	menuButton.render(window);
	exitButton.render(window);
}

void GameOverMenu::adjustButtons()
{
	restartButton.setScale(3.f, 3.f);
	menuButton.setScale(3.f, 3.f);
	exitButton.setScale(3.f, 3.f);
	gameOverSprite.setScale(2.f, 2.f);

	float centerX = WIN_WIDTH / 2.f;
	float gameOverY = 200.f;
	float restartY = 420.f;
	float menuY = restartY + 120.f;
	float exitY = menuY + 50.f;

	//Centrowanie do srodka
	gameOverSprite.setOrigin(gameOverSprite.getLocalBounds().width / 2.f, gameOverSprite.getLocalBounds().height / 2.f);
	gameOverSprite.setPosition(centerX, gameOverY);

	//restart pod napisem
	restartButton.setOriginCenter(); 	
	restartButton.setPosition(centerX, restartY); 

	//menu pod restartem
	menuButton.setOriginCenter();
	menuButton.setPosition(centerX, menuY);

	exitButton.setOriginCenter();
	exitButton.setPosition(centerX, exitY);	
}

bool GameOverMenu::restart() 
{
	return restartButton.isPressed();
}

bool GameOverMenu::exit() 
{
	return exitButton.isPressed();
}

bool GameOverMenu::menu()
{
	return menuButton.isPressed();
}
