#include "SolidObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>
SolidObject::SolidObject(float x, float y, const string& resource, int horizontalFrames, int verticalFrames)
	:Object(x,y,resource,horizontalFrames,verticalFrames)
{

}
