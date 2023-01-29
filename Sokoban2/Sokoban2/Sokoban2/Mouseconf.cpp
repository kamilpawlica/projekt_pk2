#include "Mouseconf.h"
#include "Game.h"
Mouseconf* Mouseconf::Instance = nullptr;

Mouseconf::Mouseconf()
{
    update();
}

sf::Vector2i Mouseconf::PozycjaKursora()
{
    return sf::Mouse::getPosition(*Game::GetInstance()->GetWindow());
}

Mouseconf* Mouseconf::GetInstance()
{
    if (Instance == nullptr)
    {
        Instance = new Mouseconf();
    }

    return Instance;
}

bool Mouseconf::UpButton(sf::Mouse::Button Button)
{
    return (obecny[Button] == false) and (pop[Button] == false);
}

bool Mouseconf::DownButton(sf::Mouse::Button Button)
{
    return (obecny[Button] == true) and (pop[Button] == true);
}

bool Mouseconf::PuszczonyButton(sf::Mouse::Button Button)
{
    return (obecny[Button] == false) and (pop[Button] == true);
}

bool Mouseconf::NacisnietyButton(sf::Mouse::Button Button)
{
    return (obecny[Button] == true) and (pop[Button] == false);
}

void Mouseconf::update()
{
    for (int i = 0; i < sf::Mouse::ButtonCount; ++i)
    {
        pop[i] = obecny[i];
        obecny[i] = sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(i));
    }
}