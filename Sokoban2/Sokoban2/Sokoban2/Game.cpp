#include "Game.h"
#include "Keyboardconf.h"
#include "Mouseconf.h"
#include "GameIni.h"

Game* Game::Instance = nullptr;
Game::Game() //def konstruktora
    :width(1280),
    height(720),
    Title("Sokoban Game"),
    Window(new sf::RenderWindow(sf::VideoMode(width, height), Title)),
    CurrentRoom(new GameIni()),
    NextRoom(nullptr)
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
    CurrentRoom->Draw();
    Window->display();
}
void Game::Step()
{
    CurrentRoom->Step();
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
        SprawdzZmianeRoom();
    }
}
sf::RenderWindow* Game::GetWindow()
{
        return Window;
}

MainRoom* Game::GetCurrentRoom()
{
    return CurrentRoom;
}

//sprawdzamy czy wskaznik jest pusty, zeby nie doprowadzic do wycieku pamieci
void Game::ChangeRoom(MainRoom* NewRoom)
{
    if (NextRoom == nullptr)
    {
        NextRoom = NewRoom;
    }
    else
    {
        delete NewRoom;
    }
}

void Game::SprawdzZmianeRoom()
{
    if (NextRoom != nullptr)
    {
        delete CurrentRoom;
        CurrentRoom = NextRoom;
        NextRoom = nullptr;
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
