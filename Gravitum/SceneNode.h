#pragma once
#include <memory>
#include <vector>
#include <algorithm>
#include <assert.h>
#include "SFML/Graphics.hpp"
#include "SFML/System/NonCopyable.hpp"
#include <functional>

struct Command;

namespace Category {
	enum Type
	{
		None = 0,
		Scene = 1 << 0,
		Player = 1 << 1,
		Enemy = 1 << 2
	};
}

class SceneNode : public sf::Transformable,
                  public sf::Drawable,
                  private sf::NonCopyable
{
public:
    typedef std::unique_ptr<SceneNode> mngPtr;
    void update(sf::Time deltaTime);

public:
    SceneNode();
    void attachChild(mngPtr child);
    mngPtr detachChild(const SceneNode& node);

    sf::Vector2f getWorldPosition() const;
	virtual unsigned int getCategory() const;
	void onCommand(const Command& command, sf::Time deltaTime);

private:

    std::vector<mngPtr> mChildren;
    SceneNode *mParent;

    sf::Transform getWorldTransform() const;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

    virtual void updateCurrent(sf::Time deltaTime);
    void updateChildren(sf::Time deltaTime);

};

