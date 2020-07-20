#include "SpriteNode.h"

SpriteNode::SpriteNode(const sf::Texture& texture)
{
	mSprite.setTexture(texture);
}

SpriteNode::SpriteNode(const sf::Texture& texture, const sf::IntRect& textureRect)
{
	mSprite.setTexture(texture);
	mSprite.setTextureRect(textureRect);
}

void SpriteNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}
