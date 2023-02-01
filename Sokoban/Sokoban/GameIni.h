#pragma once
#include <SFML/Graphics.hpp>
#include "MainRoom.h"
#include <iostream>
class GameIni:public MainRoom
{
public:
	GameIni();

	virtual void Step() override;
};
