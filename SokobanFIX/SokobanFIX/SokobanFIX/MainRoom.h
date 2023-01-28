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
	/*
	template <typename T> //typ T
	std::vector<T> GetAllGameObjectsAtPosition(float x,float y); //szukanie obiektow wskazanego typu
	*/
private:
	std::vector<Object*> Obiekty; //wektor wskaznikow na klase object
};

/*
template<typename T>
inline std::vector<T> MainRoom::GetAllGameObjectsAtPosition(float x, float y)
{
	std::vector<T*> objects;
	for (Object* i : Obiekty)
	{
		T cast = dynamic_cast<T>(i)
		if (cast != nullptr);

		{
			if (i->IsNajechane(x, y) == true)
			{
				objects.push_back(cast);
			}
		}
	}



	return objects;
}
*/