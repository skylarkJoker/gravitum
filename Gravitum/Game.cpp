#include "Game.hpp"

Game::Game() 
    : 
    mWindow(sf::VideoMode(1080, 1024), "Hub"),
    mWorld(mWindow)
{
}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (mWindow.isOpen())
    {
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::KeyPressed:
            break;
        case sf::Event::KeyReleased:
            break;
        case sf::Event::Closed:
            mWindow.close();
            break;
        }
    }
}

void Game::update(sf::Time deltaTime)
{
    mWorld.update(deltaTime);
}

void Game::render()
{
    mWindow.clear(sf::Color(sf::Color::Black));
    mWorld.draw();
    mWindow.display();
}