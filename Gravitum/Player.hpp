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
    typedef ResourceLoader<sf::Texture, Textures::ID> TextureLoader;
    Type mType;
    float ppm = 16.f;
    sf::Sprite mSprite;

    b2BodyDef mPlayerBodyDef;
    b2Body *mPlayerBody;
    b2PolygonShape mPlayerPolyShape;
    b2FixtureDef mPlayerFixture;

public:
    Player(Type, const TextureLoader &);
    virtual void drawCurrent(sf::RenderTarget &, sf::RenderStates) const;
    void initBodies(b2World &, float, float);

    void setPosition(float, float);
    void setPosition(b2Vec2);
};