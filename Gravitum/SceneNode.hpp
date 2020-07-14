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

public:
    SceneNode();
    void attachChild(mngPtr);
    mngPtr detachChild(const SceneNode &);

private:
    std::vector<mngPtr> mChildren;
    SceneNode *mParent;

    virtual void draw(sf::RenderTarget &, sf::RenderStates) const;
    virtual void drawCurrent(sf::RenderTarget &, sf::RenderStates) const = 0;
};