#include "MainMenu.h"


MainMenu::MainMenu()
{
	initTextures();
	adjustButtons();
}

void MainMenu::initTextures()
{
	if (!flappyBirdTexture.loadFromFile(FLAPPY_PATH))
		std::cout << "ERROR: failed to load GAMEOVER TEXTURE" << std::endl;

	flappyBirdSprite.setTexture(flappyBirdTexture);
	auto bounds = flappyBirdSprite.getGlobalBounds();

	startButton.initButton(PLAY_PATH, PLAY_PATH_HOVER,{ 0.f, 0.f }); 
	scoreButton.initButton(SCORE_PATH, SCORE_PATH_HOVER,{ 0.f, 0.f });

}

void MainMenu::adjustButtons()
{
	startButton.setScale(3.f, 3.f);
	//scoreButton.setScale(2.f, 2.f);
	flappyBirdSprite.setScale(4.f, 4.f);

	float centerX = WIN_WIDTH / 2.f;
	float flappyBirdY = 250.f;
	float buttonsY = 500.f;

	flappyBirdSprite.setOrigin(flappyBirdSprite.getLocalBounds().width / 2.f, flappyBirdSprite.getLocalBounds().height / 2.f);
	flappyBirdSprite.setPosition(centerX, flappyBirdY);

	//Restart pod napisem
	startButton.setOriginCenter(); 
	startButton.setPosition(centerX , buttonsY);

	//Score po prawej
	//scoreButton.setOriginCenter();
	//scoreButton.setPosition(centerX + buttonDistance / 2.f, buttonsY);

}

void MainMenu::update(RenderWindow* window)
{
	startButton.update(window);
	//scoreButton.update(window);
}

void MainMenu::render(RenderWindow* window)
{
	window->draw(flappyBirdSprite);
	startButton.render(window);
	//scoreButton.render(window);
}

bool MainMenu::start() 
{
	return startButton.isPressed();
}

bool MainMenu::exit()
{
	return false;
}
