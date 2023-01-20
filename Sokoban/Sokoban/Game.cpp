#include <iostream>
#include "Game.h"
#include "Keyboardconf.h"
#include "Mouseconf.h"
Game* Game::Instance = nullptr;
Game::Game() //def konstruktora
    :width(1280),
    height(720),
    Title("Sokoban Game"),
    Window(new sf::RenderWindow(sf::VideoMode(width, height), Title)), Shape(200.f) 
{} 
void Game::MainWindowEvent()
{
    sf::Event event;
    while (Window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            Window->close();
    }
}

Game::~Game() //destr 
{
    delete Window;
}

void Game::Draw()
{
    Window->clear();
    Window->draw(Shape);
    Window->display();
}

void Game::Step()
{
    Shape.setFillColor(sf::Color::Red);
}

void Game::StartGame() //funkcja odpowiedzialna za uruchomienie programu
{

    while (Window->isOpen())
    {
        Keyboardconf::GetInstance()->update();
        Mouseconf::GetInstance()->update();
        MainWindowEvent();
        Step();
        Draw();
    }
}

Game* Game::GetInstance()
{
    if (Instance == nullptr)
    {
        Instance = new Game();
    }
    return Instance;
}

sf::RenderWindow* Game::GetWindow()
{
    return Window;
}


// ***** testyyy
// ----------------------------
/*
void Game::SetResolution(int szerokosc, int wysokosc)
{
    delete Window;
    width = szerokosc;
    height = wysokosc;
    Window = new sf::RenderWindow(sf::VideoMode(width, height), Title);
}

sf::Vector2u Game::GetWindowResolution()
{
    return Window->getSize();
}

void Game::SetTitle(const std::string& text)
{
    Title = text;
    Window->setTitle(Title);
}

std::string Game::GetTitle()
{
    return Title;
}
*/
// ----------------------------