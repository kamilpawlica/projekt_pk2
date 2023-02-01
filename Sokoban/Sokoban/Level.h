#pragma once
#include "MainRoom.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Level : public MainRoom
{
public:
	Level(const std::string &filename,int levelNumber);

private:
	int LevelNumber;
};