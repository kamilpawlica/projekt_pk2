#include "Keyboardconf.h"

Keyboardconf* Keyboardconf::Instance = nullptr;

Keyboardconf::Keyboardconf()
{
    update();
}

Keyboardconf* Keyboardconf::GetInstance()
{
    if (Instance == nullptr)
    {
        Instance = new Keyboardconf();
    }

    return Instance;
}

bool Keyboardconf::UpKey(sf::Keyboard::Key Key)
{
    return (obecny[Key] == false) and (pop[Key] == false);
}

bool Keyboardconf::DownKey(sf::Keyboard::Key Key)
{
    return (obecny[Key] == true) and (pop[Key] == true);
}

bool Keyboardconf::PuszczonyKey(sf::Keyboard::Key Key)
{
    return (obecny[Key] == false) and (pop[Key] == true);
}

bool Keyboardconf::NacisnietyKey(sf::Keyboard::Key Key)
{
    return (obecny[Key] == true) and (pop[Key] == false);
}

void Keyboardconf::update()
{
    for (int i = 0; i < sf::Keyboard::KeyCount; ++i)
    {
        pop[i] = obecny[i];
        obecny[i] = sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(i));
    }
}


