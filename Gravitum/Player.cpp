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
Player::Player(Type type, const TextureLoader &textures) 
    :
    mType(type), 
    mSprite(textures.get(toTextureID(type)))
{
    sf::FloatRect bounds = mSprite.getLocalBounds();
    mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Player::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}

void Player::updateCurrent(sf::Time deltaTime) {
    setSpritePos();
}

void Player::setupSprite() {
    sf::FloatRect bounds = mSprite.getLocalBounds();
    mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
    mSprite.setPosition(mBody->GetPosition().x * 16.f, mBody->GetPosition().y * 16.f);
}

void Player::setSpritePos() {
    mSprite.setPosition(mBody->GetPosition().x * 16.f, mBody->GetPosition().y * 16.f);
}

void Player::setBodyPos(float x, float y, b2World& world)
{
    mBodyDef.position.Set(x/16.f, y/16.f);
    mBodyDef.type = b2_dynamicBody;
    mBody = world.CreateBody(&mBodyDef);
}
