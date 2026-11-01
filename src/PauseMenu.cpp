#include "PauseMenu.h"

void PauseMenu::initTextures()
{
	resumeButton.initButton("RESUME", "RESUME_HV");
	menuButton.initButton("MENU", "MENU_HV");
}

void PauseMenu::adjustButtons()
{
	resumeButton.setScale(PAUSE_SCALE, PAUSE_SCALE);
	menuButton.setScale(PAUSE_SCALE, PAUSE_SCALE);

	// Margins from the top-left corner
	const float marginLeft = 30.f;
	const float marginTop = 30.f;
	const float distance = 60.f;

	// Position relative to the top-left corner
	resumeButton.setPosition(marginLeft, marginTop);

	menuButton.setPosition(marginLeft + distance, marginTop );
}

PauseMenu::PauseMenu(TextureManager& manager) : textureManager(manager), resumeButton(manager), menuButton(manager)
{

}

void PauseMenu::init()
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
