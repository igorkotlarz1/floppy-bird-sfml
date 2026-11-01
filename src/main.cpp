#include "Game.h"

int main()
{
    Game& game = Game::getInstance();
    Clock clock;

    while (game.isRunning())
    {
        Time dt = clock.restart();
        game.update(dt);
        game.render();
    }

    return 0;
}
