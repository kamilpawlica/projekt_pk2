#include "GameIni.h"
#include "Texture.h"
#include "MainMenuRoom.h"
#include <SFML/Graphics.hpp>
#include <iostream>
//Pierwszy room
//tworzenie wskaznika, przekazanie go i push do wektora
GameIni::GameIni() 
{ 
	Texture::GetInstance()->AddTexture("font", "font.png");
	Texture::GetInstance()->AddTexture("box","box.png");
	Texture::GetInstance()->AddTexture("goal", "goal.png");
	Texture::GetInstance()->AddTexture("wall", "wall.png");
	Texture::GetInstance()->AddTexture("character", "character.png");
	Texture::GetInstance()->AddTexture("menu", "menu.png");
	Texture::GetInstance()->AddTexture("menu_button", "menu_button.png");

} 

void GameIni::Step()
{
	//ChangeRoom(new Level("Level1.txt", 1));
	ChangeRoom(new MainMenuRoom());
}