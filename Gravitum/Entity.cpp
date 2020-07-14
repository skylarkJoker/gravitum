#include "Entity.hpp"

void Entity::setVelocity(b2Vec2 velocity)
{
    mVelocity = velocity;
}

void Entity::setVelocity(float x, float y)
{
    mVelocity.Set(x, y);
}

b2Vec2 Entity::getVelocity() const
{
    return mVelocity;
}