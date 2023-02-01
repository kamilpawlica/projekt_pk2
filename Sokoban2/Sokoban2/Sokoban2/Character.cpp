#include "Character.h"
#include "Keyboardconf.h"
Character::Character(float x, float y) : Object(x, y, "character") 
{
	SetSpeed(1.0f);
}

void Character::Step()
{

	Object::Step();

	if (Keyboardconf::GetInstance()->NacisnietyKey(sf::Keyboard::Right))
	{
		SetDirection(Direction() - 1);
	}

	if (Keyboardconf::GetInstance()->NacisnietyKey(sf::Keyboard::Left))
	{
		SetDirection(Direction() + 1);
	}

	if (Keyboardconf::GetInstance()->DownKey(sf::Keyboard::Space))
	{
		SetAlarm(0, 1);
	}

	if (Keyboardconf::GetInstance()->NacisnietyKey(sf::Keyboard::Return))
	{
		SetSpeed(0);
	}
}

void Character::OnAlarm(int alarm)
{
	SetX(XStart());
	SetY(YStart());
}