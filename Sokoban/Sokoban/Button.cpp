#include "Button.h"
#include "Mouseconf.h"
#include "Font.h"
#include <SFML/Graphics.hpp>
#include <iostream>
Button::Button(
	float x, 
	float y, 
	const std::string& spriteResource,
	void (*callback)(),
	const std::string& text,
	sf::Color off_color,
	sf::Color on_color,
	const std::string& fontResource)

	: Object(x, y, spriteResource, 2, 1),
	Callback(callback),
	Fontxd(new Font(fontResource)),
	Text(text),
	OffColor(off_color),
	OnColor(on_color)
	
{}

Button::~Button()
{
	delete Fontxd; //delete pointera
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

void Button::Draw()
{
	Object::Draw();
	sf::Color DrawColor = (ImageIndex() == 0) ? OffColor : OnColor; //jezeli imgindex 0, wez offcolor
	Fontxd->Print(X() + 10.0f, Y() + 10.0f, Text, DrawColor, 2, 2);
}
