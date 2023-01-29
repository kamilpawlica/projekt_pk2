#include <iostream>
#include "Game.h"   


int main()
{
    Game::GetInstance()->StartGame();

    //Game* obiekt = Game::GetInstance();
    //obiekt->SetTitle("Sokoban Game Project");
    //Game::GetInstance()->SetResolution(400, 400);
    return 0;
}