#include "GameOverMenu.h"

GameOverMenu::GameOverMenu()
{
	initTextures();
	adjustButtons();
}

void GameOverMenu::initTextures()
{
	if(!gameOverTexture.loadFromFile(GAME_OVER_PATH))
		std::cout << "ERROR: failed to load GAMEOVER TEXTURE" << std::endl;

	gameOverSprite.setTexture(gameOverTexture);
	auto bounds = gameOverSprite.getGlobalBounds();

	gameOverSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
	gameOverSprite.setPosition(400.f, 150.f);

	restartButton.initButton(PLAY_PATH, PLAY_PATH_HOVER,{ 0.f, 0.f }); 
	menuButton.initButton(MENU_PATH, MENU_PATH_HOVER,{ 0.f, 0.f });
	exitButton.initButton(OK_PATH, OK_PATH_HOVER, { 0.f, 0.f });
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
	//scoreButton.setScale(2.f, 2.f);
	gameOverSprite.setScale(2.f, 2.f);

	float centerX = WIN_WIDTH / 2.f;
	float gameOverY = 200.f;
	float restartY = 420.f;
	//float buttonSpacing = 160.f; 
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
