#ifndef GAMESTATE_H
#define GAMESTATE_H

enum class GameState 
{
    LOADING = 0,
    MENU,
    PLAYING,
    PAUSE,
    GAME_OVER
};

enum class Difficulty
{
    EASY = 0,
    MEDIUM,
    HARD
};

#endif