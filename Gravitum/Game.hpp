#pragma once
#include <SFML/Graphics.hpp>
#include "DrawBox.hpp"
#include "ResourceLoader.hpp"
#include <box2d/box2d.h>

class Game
{
public:
    Game();
    void run();

private:
    const float ppm = 16.f;
    const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
    float timeStep;
    int32 velocityIterations;
    int32 positionIterations;

    b2Vec2 gravity;
    b2World world;

    b2Body *mGroundBody;
    b2BodyDef mGroundBodyDef;
    b2PolygonShape mGroundShape;

    bool mJump, mDown, mMoveLeft, mMoveRight;

    sf::RenderWindow mWindow;
    sf::RectangleShape mGround;
    DrawBox drawBox;

    void processEvents();
    void handlePlayerInput(sf::Keyboard::Key, bool);
    void update(sf::Time deltaTime);
    void render();
};