#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
using namespace std;
class Texture
{
public:
	static Texture* GetInstance();
	void AddTexture(const string& name, const string& filename);
	sf::Texture* GetTexture(const string& name); //get img ktorego szukamy

private:
	Texture();
	map<string, sf::Texture*> Tekstury; //kluczem mapy jest tekst, wartoscia wskaznik odpowiedniej tekstury
	static Texture* Instance;
};