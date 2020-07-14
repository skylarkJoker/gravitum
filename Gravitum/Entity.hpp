#pragma once
#include "box2d/box2d.h"
#include "SceneNode.hpp"

class Entity : public SceneNode
{
private:
    b2Vec2 mVelocity;

public:
    void setVelocity(b2Vec2);
    void setVelocity(float, float);
    b2Vec2 getVelocity() const;
};