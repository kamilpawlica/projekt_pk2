#include "Box.h"
#include "Game.h"

Box::Box(float x, float y) : SolidObject(x, y, "box") {}

void Box::OnAlarm(int alarm)
{
	SetSpeed(0);
}
