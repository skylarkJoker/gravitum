#pragma once
#include "Entity.hpp"
#include "ResourceLoader.hpp"
#include "box2d/box2d.h"
#include "SFML/Graphics.hpp"

class Ground :
    public Entity
{
public:
    enum class Type {
        Normal,
        Ice,
        Sand
    };

private:
    Type mType;
    sf::Sprite mSprite;


public:
    Ground(Type, const TextureLoader&);

    void setupSprite();
    void setSpritePos();
    virtual void drawCurrent(sf::RenderTarget &, sf::RenderStates) const;
};

