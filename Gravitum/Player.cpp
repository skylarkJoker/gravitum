#include "Player.h"

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

void Player::moveBody(b2Vec2 velocity)
{
	//flip sprite!
	if (velocity.x < 0) {
		mSprite.setScale(-1.f, 1.f);
	}
	else {
		mSprite.setScale(1.f, 1.f);
	}
	
	//move the sprite
	b2Vec2 vel = mBody->GetLinearVelocity();
	float vChange = velocity.x - vel.x;
	float impulse = mBody->GetMass() * vChange;

	mBody->ApplyLinearImpulse(b2Vec2(impulse,0.f), mBody->GetWorldCenter(), true);
}

void Player::setBodyPos(float x, float y, b2World& world)
{
    mBodyDef.position.Set(x/16.f, y/16.f);
    mBodyDef.type = b2_dynamicBody;
    mBody = world.CreateBody(&mBodyDef);
}

unsigned int Player::getCategory() const
{
	return Category::Player;
}

sf::Vector2f Player::getPos() {
	return mSprite.getPosition();
}
