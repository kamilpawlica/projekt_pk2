#include "Button.h"
#include "Mouseconf.h"
Button::Button(	float x,float y,const std::string& resource, void (*callback)())
	: Object(x,y, resource, 2,1),
	Callback(callback)
{
	SetImageSpeed(0.1f);
}

void Button::Step()
{
	sf::Vector2i mouse = Mouseconf::GetInstance()->PozycjaKursora();
	SetImageIndex(0);
	if (IsNajechane(mouse.x, mouse.y) == true)
	{
		SetImageIndex(1);
		if (Mouseconf::GetInstance()->NacisnietyButton(sf::Mouse::Left) == true)
		{
			Callback();
		}
	}
}
