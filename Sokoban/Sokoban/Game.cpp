#include "Game.h"

Game::Game() :Window(sf::VideoMode(1280, 720), "Sokoban game"), Shape(200.f) {} // rozdzielczosc, tytul okna

void Game::MainWindowEvent()
{
    sf::Event event;
    while (Window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            Window.close();
    }
}

void Game::Draw()
{
    Window.clear();
    Window.draw(Shape);
    Window.display();
}

void Game::Step()
{
    Shape.setFillColor(sf::Color::Red);
}

void Game::StartGame() //funkcja odpowiedzialna za uruchomienie programu
{

    while (Window.isOpen())
    {
        MainWindowEvent();
        Step();
        Draw();
    }
}