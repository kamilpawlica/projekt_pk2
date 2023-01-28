#pragma once
#include "Object.h"
#include "Font.h"
class Button : public Object
{
public:
	Button(float x, 
		float y, 
		const std::string & spriteResource, 
		void (*callback)(),
		const std::string & text,
		sf::Color off_color,
		sf::Color on_color,
		const std::string& fontResource = "font");

		~Button();
		virtual void Step() override;
		virtual void Draw() override; //najpierw animacje, potem text


	
private:
	//callback to wskaznik na funkcje ktora nie ma zadnych argumentow i zwraca voida
	void (*Callback)();
	Font* Fontxd;
	std::string Text;
	sf::Color OnColor;
	sf::Color OffColor;
};