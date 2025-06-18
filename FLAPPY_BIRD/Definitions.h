#ifndef DEFINITIONS_H
#define DEFINITIONS_H

//niezbedne includy
#include <iostream>
#include <exception>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

//uproszczenie pracy z SFMLem
using namespace sf;

//wymiary
#define WIN_WIDTH 620
#define WIN_HEIGHT 800

#define GROUND_HEIGHT 112
#define BG_SCALE_W 0.692f
#define BG_SCALE_H 0.892f

#define PIPE_HEIGHT 320
#define PIPE_SCALE 1.5f

#define PIPE_SPEED 150
#define PIPE_DISTANCE 200

#define BIRD_SCALE 2.f //0.1f
#define BIRD_PATH_1 R"(Textures\bird_2\downflap.png)"
#define BIRD_PATH_2 R"(Textures\bird_2\midflap.png)"
#define BIRD_PATH_3 R"(Textures\bird_2\upflap.png)"

#define PIPE_BOTTOM_PATH ""
#define PIPE_TOP_PATH ""

#define BG_PATH R"(Textures\backgrounds\piwko1.jpg)"
#define GROUND_PATH R"(Textures\ground\base.png)"

#define PLAY_PATH R"(Textures\buttons\play_normal.png)"
#define PLAY_PATH_HOVER R"(Textures\buttons\play_pressed.png)"

#define PAUSE_PATH R"(Textures\buttons\pause.png)"
#define PAUSE_PATH_HOVER R"(Textures\buttons\pause_hover.png)"

#define RESUME_PATH R"(Textures\buttons\resume.png)"
#define RESUME_PATH_HOVER R"(Textures\buttons\resume_hover.png)"
#define PAUSE_SCALE 4.f

#define MENU_PATH R"(Textures\buttons\menu.png)"
#define MENU_PATH_HOVER R"(Textures\buttons\menu_hover.png)"

#define SCORE_PATH R"(Textures\buttons\score_normal.png)"
#define SCORE_PATH_HOVER R"(Textures\buttons\score_pressed.png)"

#define OK_PATH R"(Textures\buttons\ok.png)"
#define OK_PATH_HOVER R"(Textures\buttons\ok_hover.png)"

#define GAME_OVER_PATH R"(Textures\ui\gameover.png)"
#define FLAPPY_PATH R"(Textures\ui\flappybird.png)"

#define FONT_SCORE R"(Fonts\font_score.ttf)"
#define FONT_SCORE_2 R"(Fonts\Press_Start_2P\PressStart2P-Regular.ttf)"

#define INVINC_PATH R"(Textures\others\medal_gold.png)"
#define SLOWMO_PATH R"(Textures\others\medal_silver.png)"

#define PUP_SCALE 3.f






/*#define BACKGROUND_PATH
#define PLAY_BUTTON_PATH
#define TITLE_PATH
#define BIRD_TEXTURES 3
#define PIPE_TEXTURES 2
#define BIRD_PATH
#define PIPE_PATH
*/

#endif 

