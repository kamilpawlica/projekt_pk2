#include "GameIni.h"
#include "Texture.h"
#include "Level.h"

//Pierwszy room
//tworzenie wskaznika, przekazanie go i push do wektora
GameIni::GameIni()
{
	Texture::GetInstance()->AddTexture("box", "box.png");
	Texture::GetInstance()->AddTexture("goal", "goal.png");
	Texture::GetInstance()->AddTexture("wall", "wall.png");
	Texture::GetInstance()->AddTexture("character", "character.png");

}

void GameIni::Step()
{
	ChangeRoom(new Level("Level1.txt", 1));
}