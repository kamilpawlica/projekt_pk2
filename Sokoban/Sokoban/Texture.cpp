#include "Texture.h"
using namespace std;
Texture* Texture::Instance = nullptr;

Texture::Texture() : Tekstury() {} //ustawiamy pusta mape

Texture* Texture::GetInstance()
{
	if (Instance == nullptr)
	{
		Instance = new Texture();
	}
	return Instance;
}

void Texture::AddTexture(const string& name, const string& filename)
{
	sf::Texture* Texture = new sf::Texture();
	Texture->loadFromFile(filename);
	Tekstury.insert(make_pair(name, Texture)); //wstawianie do mapy 
}
// szukamy w mapie
// zwraca iterator, jezeli 'second' (czyli wartosc w mapie sie zgadza)
// jezeli nie, zwracamy nullptr
sf::Texture* Texture::GetTexture(const string& name)
{
	map<string, sf::Texture*>::iterator iter = Tekstury.find(name);
	return (iter != Tekstury.end()) ? iter->second : nullptr; 
}

//Texture::Texture() : Tekstury() {} //ustawiamy pusta mape
