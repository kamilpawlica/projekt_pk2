#pragma once
//Klasa bazowa dla wszystkich objektow w calej grze
using namespace std;
#include <string>
#include <SFML/Graphics.hpp>
class Object
{
public:
	Object(int x, int y , const string &resource = "");

	virtual ~Object();

	virtual void Step();
	virtual void Draw();

	sf::Sprite* GetSprite();
private:
	sf::Sprite* Sprite;
};