#ifndef MENU_H
#define MENU_H

#include "Definitions.h"
#include "UIButton.h"

class Menu
{
public:
	virtual void render(RenderWindow* window) = 0;
	virtual void update(RenderWindow* window) = 0;
	virtual ~Menu() = default;
};

#endif 



