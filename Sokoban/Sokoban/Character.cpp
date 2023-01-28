#include "Character.h"
#include "Keyboardconf.h"
#include "Game.h"
#include "MainMenuRoom.h"
#include "SolidObject.h"
Character::Character(float x, float y) : Object(x, y, "character") {}

void Character::Step()
{
		
	Object::Step();
	
	// Gdy nacisniemy escape, powrot do menu glownego
	if (Keyboardconf::GetInstance()->DownKey(sf::Keyboard::Escape))
	{
		Game::GetInstance()->GetCurrentRoom()->ChangeRoom(new MainMenuRoom());
	}

	if (Keyboardconf::GetInstance()->NacisnietyKey(sf::Keyboard::Right))
	{
		//std::vector<SolidObject*> solids = GetAllGameObjectsAtPosition<SolidObject*>(X()+SpriteWidth(), Y());
		//if (solids.empty() == true)
		//{
			SetSpeed(6);
			SetDirection(0);
			SetAlarm(0, 10);
		//}
	}


}

void Character::OnAlarm(int alarm)
{
	SetSpeed(0);
}

