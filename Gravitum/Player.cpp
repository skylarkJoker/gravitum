#include "Player.hpp"

//match a player type to a particular texture
Textures::ID toTextureID(Player::Type type)
{
    switch (type)
    {
    case Player::Type::Main:
        return Textures::ID::Player;
        break;
    case Player::Type::Secondary:
        return Textures::ID::Player2;
        break;
    default:
        return Textures::ID::Player;
        break;
    }
}

//set type and textures
Player::Player(Type type, const TextureLoader &textures) : mType(type), mSprite(textures.get(toTextureID(type)))
{
    sf::FloatRect bounds = mSprite.getLocalBounds();
    mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Player::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}

void Player::initBodies(b2World &world, float x, float y)
{
    mPlayerBodyDef.type = b2_dynamicBody;
    mPlayerBodyDef.position.Set(x / ppm, y / ppm);
    mPlayerBody = world.CreateBody(&mPlayerBodyDef);
    mPlayerPolyShape.SetAsBox((32.f / ppm) / 2, (32.0f / ppm) / 2);
    mPlayerFixture.shape = &mPlayerPolyShape;
    mPlayerFixture.density = 1.0f;
    mPlayerFixture.friction = 1.0f;

    mPlayerBody->CreateFixture(&mPlayerFixture);
}

void Player::setPosition(float x, float y)
{
    mPlayerBodyDef.position.Set(x, y);
}

void Player::setPosition(b2Vec2 position)
{
    mPlayerBodyDef.position = position;
}