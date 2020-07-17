#include "Ground.h"

//match a player type to a particular texture
Textures::ID toTextureID(Ground::Type type)
{
    switch (type)
    {
    case Ground::Type::Normal:
        return Textures::ID::Ground;
        break;
    case Ground::Type::Ice:
        return Textures::ID::Ice;
        break;
    default:
        return Textures::ID::Ground;
        break;
    }
}


Ground::Ground(Type type, const TextureLoader& texture)
    :
    mType(type),
    mSprite(texture.get(toTextureID(type)))
{
}

void Ground::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(mSprite, states);
}

void Ground::setupSprite()
{
    mSprite.setTextureRect(sf::IntRect(0, 0, dim.width, dim.height));
    sf::FloatRect bounds = mSprite.getLocalBounds();
    mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
    mSprite.setPosition(mBody->GetPosition().x * 16.f, mBody->GetPosition().y * 16.f);
}

void Ground::setSpritePos() {
    mSprite.setPosition(mBody->GetPosition().x * 16.f, mBody->GetPosition().y * 16.f);
}
