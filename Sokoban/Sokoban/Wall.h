#pragma once
#include "SolidObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>
class Wall : public SolidObject
{
public:
	Wall(float x, float y);
};