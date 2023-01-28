#include <SFML/Graphics.hpp>
class Keyboardconf
{
public:
	static Keyboardconf* GetInstance();

	bool UpKey(sf::Keyboard::Key Key);
	bool DownKey(sf::Keyboard::Key Key);
	bool PuszczonyKey(sf::Keyboard::Key Key);
	bool NacisnietyKey(sf::Keyboard::Key Key);
	void update();
private:
	Keyboardconf();
	static Keyboardconf* Instance;

	bool obecny[125];
	bool pop[125];
};
