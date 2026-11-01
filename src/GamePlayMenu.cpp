#include "GamePlayMenu.h"

void GamePlayMenu::initTextures()
{
	pauseButton.initButton("PAUSE", "PAUSE_HV");
}

void GamePlayMenu::adjustButtons()
{
	pauseButton.setScale(PAUSE_SCALE, PAUSE_SCALE);

	// Margins from the top-left corner
	const float marginLeft = 30.f;
	const float marginTop = 30.f;
	const float spacingY = 120.f;

	// Position relative to the top-left corner
	pauseButton.setPosition(marginLeft, marginTop);
}

GamePlayMenu::GamePlayMenu(TextureManager& manager) : textureManager(manager), pauseButton(manager)
{

}

void GamePlayMenu::init()
{
	initTextures();
	adjustButtons();
}

void GamePlayMenu::update(RenderWindow* window)
{
	pauseButton.update(window);
}

void GamePlayMenu::render(RenderWindow* window)
{
	pauseButton.render(window);
}

bool GamePlayMenu::pause()
{
	return pauseButton.isPressed();
}
