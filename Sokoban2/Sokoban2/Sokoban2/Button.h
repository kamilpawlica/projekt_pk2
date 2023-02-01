#pragma once
#include "Object.h"

class Button : public Object
{
public:
	Button(float x, float y, const std::string & resource, void (*Callback)());
	virtual void Step() override;
private:
	void (*Callback)();
};