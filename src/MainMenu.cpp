#include "MainMenu.h"

MainMenu::MainMenu(TextureManager& manager) : textureManager(manager), startButton(manager)
{

}

void MainMenu::init()
{
	initTextures();
	adjustButtons();
}

void MainMenu::initTextures()
{
	flappyBirdSprite.setTexture(textureManager.getTexture("FLAPPYBIRD"));
	startButton.initButton("PLAY", "PLAY_HV");
}

void MainMenu::adjustButtons()
{
	startButton.setScale(3.f, 3.f);
	flappyBirdSprite.setScale(4.f, 4.f);

	float centerX = WIN_WIDTH / 2.f;
	float flappyBirdY = 250.f;
	float buttonsY = 500.f;

	flappyBirdSprite.setOrigin(flappyBirdSprite.getLocalBounds().width / 2.f, flappyBirdSprite.getLocalBounds().height / 2.f);
	flappyBirdSprite.setPosition(centerX, flappyBirdY);

	// Start button below the title
	startButton.setOriginCenter();
	startButton.setPosition(centerX , buttonsY);
}

void MainMenu::update(RenderWindow* window)
{
	startButton.update(window);
}

void MainMenu::render(RenderWindow* window)
{
	window->draw(flappyBirdSprite);
	startButton.render(window);
}

bool MainMenu::start()
{
	return startButton.isPressed();
}
