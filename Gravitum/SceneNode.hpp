#pragma once
#include <memory>
#include <vector>
#include <algorithm>
#include <assert.h>
#include "SFML/Graphics.hpp"
#include "SFML/System/NonCopyable.hpp"

class SceneNode : public sf::Transformable,
                  public sf::Drawable,
                  private sf::NonCopyable
{
public:
    typedef std::unique_ptr<SceneNode> mngPtr;
    void update(sf::Time);

public:
    SceneNode();
    void attachChild(mngPtr);
    mngPtr detachChild(const SceneNode &);

    sf::Vector2f getWorldPosition() const;

private:
    std::vector<mngPtr> mChildren;
    SceneNode *mParent;

    sf::Transform getWorldTransform() const;
    virtual void draw(sf::RenderTarget &, sf::RenderStates) const;
    virtual void drawCurrent(sf::RenderTarget&, sf::RenderStates) const;

    virtual void updateCurrent(sf::Time);
    void updateChildren(sf::Time);
};