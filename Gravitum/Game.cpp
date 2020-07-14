#include "Game.hpp"

Game::Game() : mWindow(sf::VideoMode(800, 600), "Hub"), mGround(), gravity(0.0f, 10.0f), world(gravity)
{
    // mWindow.setPosition(sf::Vector2i(3650, 450));
    timeStep = 1.0f / 60.0f;
    velocityIterations = 6;
    positionIterations = 2;

    drawBox.SetFlags(DrawBox::e_shapeBit);
    drawBox.setWindow(mWindow);
    world.SetDebugDraw(&drawBox);

    mGroundBodyDef.position.Set(400.f / ppm, 300.f / ppm);
    mGroundBody = world.CreateBody(&mGroundBodyDef);
    mGroundShape.SetAsBox((400.f / ppm) / 2, (32.0f / ppm) / 2);
    mGroundBody->CreateFixture(&mGroundShape, 0.0f);

    mGround.setSize(sf::Vector2f(400.f, 32.f));
    mGround.setFillColor(sf::Color(sf::Color::Black));
    mGround.setOrigin(mGround.getSize() / 2.f);
    b2Vec2 gpos = mGroundBody->GetPosition();
    mGround.setPosition(gpos.x * ppm, gpos.y * ppm);

    mJump = false;
    mDown = mJump;
    mMoveRight = mJump;
    mMoveLeft = mJump;
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
            handlePlayerInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            handlePlayerInput(event.key.code, false);
            break;
        case sf::Event::Closed:
            mWindow.close();
            break;
        }
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key code, bool isPressed)
{
    switch (code)
    {
    case sf::Keyboard::W:
        /* code */
        mJump = isPressed;
        break;
    case sf::Keyboard::S:
        /* code */
        mDown = isPressed;
        break;
    case sf::Keyboard::A:
        /* code */
        mMoveLeft = isPressed;
        break;
    case sf::Keyboard::D:
        /* code */
        mMoveRight = isPressed;
        break;
    default:
        break;
    }
}

void Game::update(sf::Time deltaTime)
{
    world.Step(TimePerFrame.asSeconds(), velocityIterations, positionIterations);
    b2Vec2 gpos = mGroundBody->GetPosition();
    mGround.setPosition(gpos.x * ppm, gpos.y * ppm);
}

void Game::render()
{
    mWindow.clear(sf::Color(sf::Color::White));
    world.DebugDraw();
    mWindow.draw(mGround);
    mWindow.display();
}