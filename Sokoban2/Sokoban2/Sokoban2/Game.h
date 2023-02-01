#pragma once
#include <SFML/Graphics.hpp>
#include "MainRoom.h"
class Game
{
public:
	~Game(); //destruktor
	void MainWindowEvent();
	void Draw();
	void Step();
	void StartGame();
	static Game* GetInstance();
	sf::RenderWindow* GetWindow();
	MainRoom* GetCurrentRoom();

	void ChangeRoom(MainRoom* NewRoom);

	void SetResolution(int width, int height);
	sf::Vector2u GetWindowResolution();
	void SetTitle(const std::string& text);
	std::string GetTitle();

	void QuitGame();
	
private:
	Game();
	void SprawdzZmianeRoom();
	int width, height; //rozdzielczosc
	std::string Title; //tytul okna
	sf::RenderWindow* Window;

	MainRoom* CurrentRoom;
	MainRoom* NextRoom;
	static Game* Instance;
};