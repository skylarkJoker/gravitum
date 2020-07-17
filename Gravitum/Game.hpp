#pragma once
#include <SFML/Graphics.hpp>
#include "DrawBox.hpp"
#include "ResourceLoader.hpp"
#include <box2d/box2d.h>
#include "World.h"

class Game
{
public:
    Game();
    void run();

private:
    sf::RectangleShape rectangle;

    const float ppm = 16.f;
    const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

    sf::RenderWindow mWindow;
    World mWorld;

    void processEvents();
    void update(sf::Time deltaTime);
    void render();
};