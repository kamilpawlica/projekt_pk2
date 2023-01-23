#include "MainRoom.h"
#include "Game.h"
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

void MainRoom::Draw()
{
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
