#include "Font.h"
#include "Game.h"

Font::Font(const std::string& resource)
	: Object(0, 0, resource, 16, 16)
{}

void Font::Print(int x, int y,
	const std::string& text,
	sf::Color tint,
	float xScale,
	float yScale)
{
	GetSprite()->setPosition(x, y);
	GetSprite()->setScale(xScale, yScale);
	GetSprite()->setColor(tint);
	for (const char& c : text)
	{
		SetImageIndex(static_cast<float>(c));
		Draw();
		SetX(X() + (xScale * SpriteWidth()));
	}
}