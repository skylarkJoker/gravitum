#include "Game.h"

Game::Game() 
    : 
    mWindow(sf::VideoMode(1080, 1024), "Hub"),
    mWorld(mWindow),
	mIsPaused(false)
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
			if(!mIsPaused)
				update(TimePerFrame);
        }
        render();
    }
}

void Game::processEvents()
{
	CommandQueue& commands = mWorld.getCommandQueue();

    sf::Event event;
    while (mWindow.pollEvent(event))
    {
		mPlayerEvent.handleEvent(event, commands);
        switch (event.type)
        {
        case sf::Event::Closed:
            mWindow.close();
            break;
        }
    }
	mPlayerEvent.handleRealtimeInput(commands);
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