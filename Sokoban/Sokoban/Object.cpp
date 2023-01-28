#include "Object.h"
#include "Texture.h"
#include "Game.h"
#include <iostream>
using namespace std;
Object::Object(float x,float y, const string& resource, int horizontalFrames, int verticalFrames) : Sprite(new sf::Sprite()),
StartPosition(x, y), 
PreviousPosition(x, y), 
IsVisible(true),
DepthVal(0.0f),
Alarms(5, -1), //5 alarmow, 0 - 4, kazdy -1
SpeedVector(0.0f,0.0f),
HorizontalFrames(horizontalFrames),
VerticalFrames(verticalFrames),
Image_Index(0),
Image_Speed(0)

{
	if (resource != "")
	{
		sf::Texture* Texture = Texture::GetInstance()->GetTexture(resource);
		Sprite->setTexture(*Texture); //dereferencja
		Sprite->setPosition(x, y);
	}
}

Object::~Object()
{
	delete Sprite;
	Sprite = nullptr; 
}

void Object::Step()
{
	//Animations
	SetImageIndex(ImageIndex() + ImageSpeed());
	//Speed
	Sprite->setPosition(Sprite->getPosition() + SpeedVector);
	//Alarm
	for (std::size_t i = 0; i < Alarms.size(); ++i)
	{
		if (Alarms[i] > 0)
		{
			--Alarms[i];
			if (Alarms[i] == 0)
			{
				OnAlarm(i);
				Alarms[i] = -1;
			}
		}
	}

}

void Object::Draw()
{
	if (Sprite != nullptr)
	{
		if (IsVisible == true)
		{
			int x = static_cast<int>(ImageIndex()) % HorizontalFrames; //0 mod 40 = 0, 39 mod 40 = 39 itd, "iterowanie" po wwierrszach
			int y = static_cast<int>(ImageIndex()) / HorizontalFrames;
			Sprite->setTextureRect(sf::IntRect(x * SpriteWidth(), y * SpriteHeight(), SpriteWidth(), SpriteHeight())); //1 obrazek z tileset
			Game::GetInstance()->GetWindow()->draw(*Sprite);
			cout << x << " " << y << endl;
		}
	}
}

sf::Sprite* Object::GetSprite()
{
	return Sprite; 
}

float Object::X()
{
	return Sprite->getPosition().x;
}

void Object::SetX(float x)
{
	Sprite->setPosition(x, Sprite->getPosition().y);
}

float Object::Y()
{
	return Sprite->getPosition().y;
}

void Object::SetY(float y)
{
	Sprite->setPosition(Sprite->getPosition().x, y);
}

float Object::XStart()
{
	return StartPosition.x;
}

void Object::SetXStart(float x)
{
	StartPosition.x = x;
}

float Object::YStart()
{
	return StartPosition.y;
}

void Object::SetYStart(float y)
{
	StartPosition.y = y;
}



float Object::XPrevious()
{
	return PreviousPosition.x;
}

void Object::SetXPrevious(float x)
{
	PreviousPosition.x = x;
}

float Object::YPrevious()
{
	return PreviousPosition.y;
}

void Object::SetYPrevious(float y)
{
	PreviousPosition.y = y;
}

bool Object::Visible()
{
	return IsVisible;
}

void Object::SetVisible(bool visible)
{
	IsVisible = visible;
}

float Object::Depth()
{
	return DepthVal;
}

void Object::SetDepth(float depth)
{
	DepthVal = depth;
}

int Object::Alarm(int alarm)
{
	return Alarms[alarm]; 
}

void Object::SetAlarm(int alarm, int value)
{
	Alarms[alarm] = value;
}

void Object::OnAlarm(int alarm)
{

}

float Object::Hspeed()
{
	return SpeedVector.x;
}

void Object::SetHspeed(float hspeed)
{
	SpeedVector.x = hspeed;
}

float Object::Vspeed()
{
	return SpeedVector.y;
}

void Object::SetVspeed(float vspeed)
{
	SpeedVector.y = vspeed;
}
//testyyyy
float Object::Speed()
{
	return hypot(SpeedVector.x, SpeedVector.y);
}

void Object::SetSpeed(float NewSpeed)
{
	float OldSpeed = Speed();
	if (OldSpeed != 0.0f)
	{
		float factor = NewSpeed / OldSpeed;
		SpeedVector *= factor;
	}
	else
	{
		SpeedVector.x = NewSpeed;
	}
}

float Object::Direction()
{
	return 180.0f * atan2(-SpeedVector.y, SpeedVector.x) / 3.14f;
}

void Object::SetDirection(float direction)
{
	float radians = direction * 3.14 / 180.0f;
	float speed = Speed();
	SpeedVector = sf::Vector2f(speed * cos(radians), -speed * sin(radians));
}

float Object::ImageIndex()
{
	return Image_Index;
}

void Object::SetImageIndex(float value)
{
	value = fmod(value, HorizontalFrames * VerticalFrames);
	if (value < 0)
	{
		value += (HorizontalFrames * VerticalFrames);
	}
	Image_Index = value;
}

float Object::ImageSpeed()
{
	return Image_Speed;
}

void Object::SetImageSpeed(float value)
{
	Image_Speed = value;
}

int Object::SpriteWidth()
{
	return Sprite->getTexture()->getSize().x / HorizontalFrames; //640/40
}

int Object::SpriteHeight()
{
	return Sprite->getTexture()->getSize().y / VerticalFrames;
}

bool Object::IsNajechane(int x, int y)
{
	if ((x >= Sprite->getPosition().x) &&
		(x < Sprite->getPosition().x + SpriteWidth()) &&
		(y >= Sprite->getPosition().y) &&
		(y < Sprite->getPosition().y + SpriteHeight()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

