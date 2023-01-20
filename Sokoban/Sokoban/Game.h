#include <SFML/Graphics.hpp>
class Game
{
public:
	Game(); //konstruktor
	void MainWindowEvent();
	void Draw();
	void Step();
	void StartGame();
private:
	sf::RenderWindow Window;
	sf::CircleShape Shape;

};
