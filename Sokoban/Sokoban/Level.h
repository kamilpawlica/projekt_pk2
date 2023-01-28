#pragma once
#include "MainRoom.h"

class Level : public MainRoom
{
public:
	Level(const std::string &filename,int levelNumber);

private:
	int LevelNumber;
};