#pragma once
//Klasa bazowa dla wszystkich objektow w calej grze
using namespace std;
#include <string>
#include <SFML/Graphics.hpp>
#include "Game.h"
class Object
{
public:
	Object(float x, float y, const string& resource = "", int horizontalFrames = 1, int verticalFrames = 1);

	virtual ~Object();

	virtual void Step();
	virtual void Draw();

	sf::Sprite* GetSprite();

	float X();
	void SetX(float x);

	float Y();
	void SetY(float y);

	float XStart();
	void SetXStart(float x);

	float YStart();
	void SetYStart(float y);

	float XPrevious();
	void SetXPrevious(float x);

	float YPrevious();
	void SetYPrevious(float y);

	bool Visible();
	void SetVisible(bool visible);

	float Depth();
	void SetDepth(float depth);

	int Alarm(int alarm);
	void SetAlarm(int alarm, int value);
	virtual void OnAlarm(int alarm);

	float Hspeed();
	void SetHspeed(float hspeed);

	float Vspeed();
	void SetVspeed(float vspeed);

	float Speed();
	void SetSpeed(float speed);

	float Direction();
	void SetDirection(float direction);

	float ImageIndex();
	void SetImageIndex(float value);

	float ImageSpeed();
	void SetImageSpeed(float value);

	int SpriteWidth();
	int SpriteHeight();

	bool IsNajechane(int x, int y);

	//template <typename T> //typ T
	//std::vector<T> GetAllGameObjectsAtPosition(float x, float y); //szukanie obiektow wskazanego typu

private:
	sf::Sprite* Sprite;
	sf::Vector2f StartPosition;
	sf::Vector2f PreviousPosition;
	bool IsVisible;
	float DepthVal;
	std::vector<int> Alarms;
	sf::Vector2f SpeedVector;
	int HorizontalFrames;
	int VerticalFrames;
	float Image_Index;
	float Image_Speed;
};
/*
template<typename T>
inline std::vector<T> Object::GetAllGameObjectsAtPosition(float x, float y)
{
	return Game::GetInstance()->GetCurrentRoom()->GetAllGameObjectsAtPosition<T>(x, y);
}
*/