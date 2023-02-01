#pragma once
#include "Object.h"
#include <SFML/Graphics.hpp>
#include <iostream>
class Character : public Object
{
public:
	Character(float x, float y);
	virtual void Step() override;
	virtual void OnAlarm(int alarm) override;
};