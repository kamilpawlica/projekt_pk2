#include "Level.h"
#include "Box.h"
#include "Character.h"
#include "Wall.h"
#include "Goal.h"
#include "MainMenuBackground.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
Level::Level(const string& filename, int levelNumber) : MainRoom(), LevelNumber(levelNumber)
{
	float x, y;
	
	ifstream file(filename);
	if (file.fail())
	{
		cout << "Zly plik!!!";
	}
	while (file.eof() == false)
	{
		string name;
		file >> name >> x >> y;

		if (name == "Box")
		{
			InstanceCreate(new Box(x, y));
		}
		else if (name == "Wall")
		{
			InstanceCreate(new Wall(x, y));
		}
		else if (name == "Character")
		{
			InstanceCreate(new Character(x, y));
		}
		else if (name == "Goal")
		{
			InstanceCreate(new Goal(x, y));
		}
	}

	file.close();
	
}