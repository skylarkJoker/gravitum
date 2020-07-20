#pragma once
#include "Entity.h"
#include "ResourceLoader.h"
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
	virtual unsigned int getCategory() const;

    void setupSprite();
    void setSpritePos();

	void moveBody(b2Vec2 velocity);
	sf::Vector2f getPos();
};