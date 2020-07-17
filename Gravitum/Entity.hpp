#pragma once
#include "box2d/box2d.h"
#include "SceneNode.hpp"

    struct Dim {
        int width, height;
    };

class Entity : public SceneNode
{
private:
    sf::Vector2f mVelocity;
    virtual void updateCurrent(sf::Time);

protected:
    b2BodyDef mBodyDef;
    b2Body* mBody;
    b2PolygonShape mShape;
    b2FixtureDef mFixtureDef;
    Dim dim;

public:
    Entity();
    void setVelocity(sf::Vector2f);
    sf::Vector2f getVelocity() const;

    virtual void setBodyPos(float, float, b2World&);
    void setBodyType(b2BodyType);
    void setBody(b2Body&);
    void setPolyShapeAsBox(float, float);
    void setFixtureShape(b2PolygonShape&);
    void setDensity(float);
    void setFriction(float);

    void setup(float, float, float, float);


};