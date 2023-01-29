#pragma once
//Klasa podstawowa dla wszystkich obiektow na planszy
#include <vector>
#include "Object.h"
class MainRoom
{
public:
	MainRoom();

	virtual ~MainRoom();

	virtual void Step();
	virtual void Draw();

	void InstanceCreate(Object* Object); //wskaznik na obiekty
	void ChangeRoom(MainRoom* NextRoom);


private:
	std::vector<Object*> Obiekty; //wektor wskaznikow na klase object
};