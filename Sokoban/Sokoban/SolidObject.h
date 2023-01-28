#pragma once
#include "Object.h"

class SolidObject : public Object
{
public:
	SolidObject(float x, float y, const string& resource = "", int horizontalFrames = 1, int verticalFrames = 1);
	
};