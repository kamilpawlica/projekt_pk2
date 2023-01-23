#include "Object.h"
#include "Texture.h"
#include "Game.h"
using namespace std;
Object::Object(int x,int y, const string& resource) : Sprite(new sf::Sprite())
{
	if (resource != "")
	{
		sf::Texture* Texture = Texture::GetInstance()->GetTexture(resource);
		Sprite->setTexture(*Texture); //dereferencja
		Sprite->setPosition(x, y);
	}
}

Object::~Object()
{
	delete Sprite;
	Sprite = nullptr; 
}

void Object::Step()
{

}

void Object::Draw()
{
	if (Sprite != nullptr)
	{
		Game::GetInstance()->GetWindow()->draw(*Sprite);
	}
}

sf::Sprite* Object::GetSprite()
{
	return Sprite; 
}
