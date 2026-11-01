#ifndef DEFINITIONS_H
#define DEFINITIONS_H

// Shared constants and asset paths. Paths are relative to the working
// directory; CMake copies assets/ next to the executable.

#include <iostream>
#include <exception>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace sf;

// Window and layout (px)
#define WIN_WIDTH 620
#define WIN_HEIGHT 800

#define GROUND_HEIGHT 112
#define BG_SCALE_W 0.692f
#define BG_SCALE_H 0.892f

#define PIPE_HEIGHT 320
#define PIPE_SCALE 1.5f

#define PIPE_SPEED 150
#define PIPE_DISTANCE 200

#define BIRD_SCALE 2.f
#define BIRD_PATH_1 "assets/textures/bird/downflap.png"
#define BIRD_PATH_2 "assets/textures/bird/midflap.png"
#define BIRD_PATH_3 "assets/textures/bird/upflap.png"

#define PIPE_BOTTOM_PATH "assets/textures/pipe_bottom.png"
#define PIPE_TOP_PATH "assets/textures/pipe_top.png"

#define BG_PATH "assets/textures/background.jpg"
#define GROUND_PATH "assets/textures/ground.png"

#define PLAY_PATH "assets/textures/buttons/play_normal.png"
#define PLAY_PATH_HOVER "assets/textures/buttons/play_pressed.png"

#define PAUSE_PATH "assets/textures/buttons/pause.png"
#define PAUSE_PATH_HOVER "assets/textures/buttons/pause_hover.png"

#define RESUME_PATH "assets/textures/buttons/resume.png"
#define RESUME_PATH_HOVER "assets/textures/buttons/resume_hover.png"
#define PAUSE_SCALE 4.f

#define MENU_PATH "assets/textures/buttons/menu.png"
#define MENU_PATH_HOVER "assets/textures/buttons/menu_hover.png"

#define OK_PATH "assets/textures/buttons/ok.png"
#define OK_PATH_HOVER "assets/textures/buttons/ok_hover.png"

#define GAME_OVER_PATH "assets/textures/ui/game_over.png"
#define FLAPPY_PATH "assets/textures/ui/title.png"

#define FONT_SCORE "assets/fonts/score.ttf"

#define INVINC_PATH "assets/textures/invincibility.png"

#define PUP_SCALE 3.f

#endif
