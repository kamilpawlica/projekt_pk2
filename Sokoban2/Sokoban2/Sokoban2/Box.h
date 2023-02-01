#pragma once
#include "SolidObject.h"
#include "SFML/Graphics.hpp"
class Box :public SolidObject
{
public:
	Box(float x, float y);

	virtual void OnAlarm(int alarm);
};