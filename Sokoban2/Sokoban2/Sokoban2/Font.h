#pragma once
#include "Object.h"

class Font : public Object
{
public:
	Font(const std::string& resource = "font");

	void Print(int x, int y,
		const std::string& text,
		sf::Color tint = sf::Color::White,
		float xScale = 1.0f,
		float yScale = 1.0f);
};