#include "Character.h"
#include "Keyboardconf.h"
#include "Game.h"
#include "MainMenuRoom.h"
#include "SolidObject.h"
#include "Texture.h"
#include "Box.h"
Character::Character(float x, float y) : Object(x, y, "character",1,1)
{

}

void Character::Step()
{

	Object::Step();

	if (Keyboardconf::GetInstance()->DownKey(sf::Keyboard::Escape))
	{
		Game::GetInstance()->GetCurrentRoom()->ChangeRoom(new MainMenuRoom());
	}

	if (Keyboardconf::GetInstance()->DownKey(sf::Keyboard::Right) && (Alarm(0) < 0))
	{
		std::vector<SolidObject*> solids = GetAllGameObjectsAtPosition<SolidObject*>(X() + SpriteWidth(), Y());
		if (solids.empty() == true)
		{
			SetImageSpeed(0.175f);
			SetSpeed(6);
			SetDirection(0);
			SetAlarm(0, 10);
			GetSprite()->setTexture(*Texture::GetInstance()->GetTexture("character"));
		}
		else
		{
			std::vector<Box*> boxes = GetAllGameObjectsAtPosition<Box*>(X() + SpriteWidth(), Y());
			if (boxes.size() == 1)
			{
				std::vector<SolidObject*> solids = GetAllGameObjectsAtPosition<SolidObject*>(X() + (SpriteWidth()<<1), Y());
				if (solids.size() == 0)
				{
					SetImageSpeed(0.175f);
					SetSpeed(2);
					SetDirection(0);
					SetAlarm(0, 30);
					GetSprite()->setTexture(*Texture::GetInstance()->GetTexture("character"));
					boxes[0]->SetImageSpeed(0.175f);
					boxes[0]->SetSpeed(2);
					boxes[0]->SetDirection(0);
					boxes[0]->SetAlarm(0, 30);
				}
			}
		}
	}

	if (Keyboardconf::GetInstance()->DownKey(sf::Keyboard::Left) && (Alarm(0) < 0))
	{
		std::vector<SolidObject*> solids = GetAllGameObjectsAtPosition<SolidObject*>(X() - SpriteWidth(), Y());
		if (solids.empty() == true)
		{
			SetImageSpeed(0.175f);
			SetSpeed(6);
			SetDirection(180);
			SetAlarm(0, 10);
			GetSprite()->setTexture(*Texture::GetInstance()->GetTexture("character"));
		}
		else
		{
			std::vector<Box*> boxes = GetAllGameObjectsAtPosition<Box*>(X() - SpriteWidth(), Y());
			if (boxes.size() == 1)
			{
				std::vector<SolidObject*> solids = GetAllGameObjectsAtPosition<SolidObject*>(X() - (SpriteWidth() << 1), Y());
				if (solids.size() == 0)
				{
					SetImageSpeed(0.175f);
					SetSpeed(2);
					SetDirection(180);
					SetAlarm(0, 30);
					GetSprite()->setTexture(*Texture::GetInstance()->GetTexture("character"));
					boxes[0]->SetImageSpeed(0.175f);
					boxes[0]->SetSpeed(2);
					boxes[0]->SetDirection(180);
					boxes[0]->SetAlarm(0, 30);
				}
			}
		}
	}

}

void Character::OnAlarm(int alarm)
{
	SetImageSpeed(0);
	SetSpeed(0);
}