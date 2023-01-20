#include <iostream>
#include "Game.h"   


int main()
{
    Game* game = new Game();

    game->StartGame();

    delete game;
    return 0;
}