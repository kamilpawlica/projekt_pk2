#include <SFML/Graphics.hpp>
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
	void SetResolution(int width, int height);
	sf::Vector2u GetWindowResolution();

	void SetTitle(const std::string& text);
	std::string GetTitle();

private:
	Game();
	int width, height; //rozdzielczosc
	std::string Title; //tytul okna
	sf::RenderWindow * Window;
	sf::CircleShape Shape;
	static Game* Instance;
};
