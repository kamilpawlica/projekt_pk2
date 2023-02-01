#include "MainMenuRoom.h"
#include "MainMenuBackground.h"
#include "Button.h"
#include "Game.h"
#include "Level.h"
	void QuitGame()
	{
		Game::GetInstance()->QuitGame();
	}

	void PlayLevel1()
	{
		Game::GetInstance()->GetCurrentRoom()->ChangeRoom(new Level("Level1.txt", 1));
	}

	void PlayLevel2()
	{
		Game::GetInstance()->GetCurrentRoom()->ChangeRoom(new Level("Level1.txt", 1));
	}

	void PlayLevel3()
	{
		Game::GetInstance()->GetCurrentRoom()->ChangeRoom(new Level("Level1.txt", 1));
	}
	MainMenuRoom::MainMenuRoom() : MainRoom()
{
	InstanceCreate(new MainMenuBackground(0, 0));
	InstanceCreate(new Button(900, 630, "menu_button", QuitGame));
	InstanceCreate(new Button(500, 200, "menu_button", PlayLevel1));
	InstanceCreate(new Button(500, 300, "menu_button", PlayLevel2));
	InstanceCreate(new Button(500, 400, "menu_button", PlayLevel3));
}