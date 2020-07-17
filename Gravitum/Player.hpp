#pragma once
#include "Entity.hpp"
#include "ResourceLoader.hpp"
#include "box2d/box2d.h"
#include "SFML/Graphics.hpp"

class Player : public Entity
{
public:
    enum class Type
    {
        Main,
        Secondary
    };

private:
    Type mType;
    sf::Sprite mSprite;

    float ppm = 16.f;

public:
    // explicit Player(Type);
    Player(Type, const TextureLoader &);
    virtual void drawCurrent(sf::RenderTarget &, sf::RenderStates) const;
    virtual void updateCurrent(sf::Time);
    virtual void setBodyPos(float, float, b2World&);

    void setupSprite();
    void setSpritePos();
};