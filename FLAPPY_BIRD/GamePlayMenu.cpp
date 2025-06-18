#include "GamePlayMenu.h"

void GamePlayMenu::initTextures()
{
	pauseButton.initButton(PAUSE_PATH, PAUSE_PATH_HOVER,{ 0.f, 0.f });
}

void GamePlayMenu::adjustButtons()
{
	pauseButton.setScale(PAUSE_SCALE, PAUSE_SCALE); //4.f

	//Odleglosci od lewej i gornej krawedxi
	const float marginLeft = 30.f;
	const float marginTop = 30.f;
	const float spacingY = 120.f;

	//Pozycjonowanie w oparciu o lewy gorny rog
	//resumeButton.setOrigin(0.f, 0.f); // origin: top-left
	pauseButton.setPosition(marginLeft, marginTop);

	//menuButton.setOrigin(0.f, 0.f); // origin: top-left
	//menuButton.setPosition(marginLeft, marginTop + spacingY);
}

GamePlayMenu::GamePlayMenu()
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
