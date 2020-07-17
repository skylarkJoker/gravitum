#include "Entity.hpp"

Entity::Entity() 
    : 
    mBody(nullptr)
{
}


void Entity::setVelocity(sf::Vector2f velocity)
{
    mVelocity = velocity;
}

sf::Vector2f Entity::getVelocity() const
{
    return mVelocity;
}

void Entity::setBodyPos(float x, float y, b2World& world)
{
    mBodyDef.position.Set(x/16.f, y/16.f);
    mBody = world.CreateBody(&mBodyDef);
}

void Entity::setBodyType(b2BodyType bodyType)
{
    mBodyDef.type = bodyType;
}

void Entity::setBody(b2Body& body)
{
    mBody = &body;
}

void Entity::setPolyShapeAsBox(float width, float height)
{
    mShape.SetAsBox(width / 16.f / 2.f, height / 16.f / 2.f);
}

void Entity::setFixtureShape(b2PolygonShape& polyShape)
{
    mFixtureDef.shape = &polyShape;
}

void Entity::setDensity(float density)
{
    mFixtureDef.density = density;
}

void Entity::setFriction(float friction)
{
    mFixtureDef.friction = friction;
}

void Entity::updateCurrent(sf::Time deltaTime) {
    move(sf::Vector2f(mVelocity.x, mVelocity.y) * deltaTime.asSeconds());
}

void Entity::setup(float width, float height, float friction, float density) {
    b2PolygonShape shape;
    shape.SetAsBox(width/ 16.f / 2.f, height/ 16.f / 2.f);

    dim.height =(int) height;
    dim.width =(int) width;

    mFixtureDef.shape = &shape;
    mFixtureDef.friction = friction;
    mFixtureDef.density = density;

    mBody->CreateFixture(&mFixtureDef);
}