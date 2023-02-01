#include "MainRoom.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
MainRoom::MainRoom(): Obiekty(){}

MainRoom::~MainRoom()
{
	for (Object* i : Obiekty)
	{
		delete i; //usuwamy pamiec po wskazniku
	}
	Obiekty.clear(); //czyszczenie wektora na koniec rooma
}

//dla kazdego obiektu

void MainRoom::Step()
{
	for (Object* i : Obiekty)
	{
		i->Step();
	}

}

// sprawdzanie ktorego wskaznika Depth jest mniejszy
bool LessThanOperator(Object* lhs, Object* rhs)
{
	return lhs->Depth() < rhs->Depth();
}

void MainRoom::Draw()
{
	//algorytm sortowania obiektow po LessThanOperator
	std::sort(Obiekty.begin(), Obiekty.end(), LessThanOperator);

	for (Object* i : Obiekty)
	{
		i->Draw();
	}

}

//push wskaznika na koniec wektora

void MainRoom::InstanceCreate(Object* Object)
{
	Obiekty.push_back(Object);
}

void MainRoom::ChangeRoom(MainRoom* NextRoom)
{
	//Game::GetInstance()->ChangeRoom(NextRoom);
	Game* x = Game::GetInstance();
	x->ChangeRoom(NextRoom);
}
