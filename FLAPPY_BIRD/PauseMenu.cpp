#include "PauseMenu.h"

void PauseMenu::initTextures()
{
	resumeButton.initButton(RESUME_PATH, RESUME_PATH_HOVER, { 0.f, 0.f });
	menuButton.initButton(MENU_PATH, MENU_PATH_HOVER,{ 0.f, 0.f });
}

void PauseMenu::adjustButtons()
{
	resumeButton.setScale(PAUSE_SCALE, PAUSE_SCALE); //4.f
	menuButton.setScale(PAUSE_SCALE, PAUSE_SCALE);

	// Odleg³oœci od górnej i lewej krawêdzi
	const float marginLeft = 30.f;
	const float marginTop = 30.f;
	const float distance = 60.f;

	// Pozycjonowanie w oparciu o lewy górny róg
	//resumeButton.setOrigin(0.f, 0.f); // origin: top-left
	resumeButton.setPosition(marginLeft, marginTop);

	//menuButton.setOrigin(0.f, 0.f); // origin: top-left
	menuButton.setPosition(marginLeft + distance, marginTop );
}

PauseMenu::PauseMenu()
{
	initTextures();
	adjustButtons();
}

void PauseMenu::update(RenderWindow* window)
{
	menuButton.update(window);
	resumeButton.update(window);
}

void PauseMenu::render(RenderWindow* window)
{
	menuButton.render(window);
	resumeButton.render(window);
}

bool PauseMenu::menu()
{
	return menuButton.isPressed();
}

bool PauseMenu::resume()
{
	return resumeButton.isPressed();
}
