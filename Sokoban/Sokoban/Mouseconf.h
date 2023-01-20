#include <SFML/Graphics.hpp>
class Mouseconf
{
public:
	sf::Vector2i PozycjaKursora();
	static Mouseconf* GetInstance();
	bool UpButton(sf::Mouse::Button Button);
	bool DownButton(sf::Mouse::Button Button);
	bool PuszczonyButton(sf::Mouse::Button Button);
	bool NacisnietyButton(sf::Mouse::Button Button);
	void update();

	

private:
	Mouseconf();
	static Mouseconf* Instance;
	bool obecny[5];
	bool pop[5];
};