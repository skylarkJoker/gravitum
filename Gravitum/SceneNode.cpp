#include "SceneNode.hpp"

SceneNode::SceneNode() : mParent(nullptr) {}

void SceneNode::attachChild(mngPtr child)
{
    child->mParent = this;
    mChildren.push_back(std::move(child));
}

SceneNode::mngPtr SceneNode::detachChild(const SceneNode &node)
{
    //find, remove and return a SceneNode
    for (auto it = mChildren.begin(); it != mChildren.end(); ++it)
    {
        if (it->get() == &node)
        {
            mngPtr child(std::move(it->get()));
            child->mParent = nullptr;
            mChildren.erase(it);
            return child;
        }
    }
    return nullptr;

    /* 
     auto found = std::find_if(mChildren.begin(), mChildren.end(), [&](mngPtr &p) -> bool { return p.get() == &node; });
     assert(found != mChildren.end());
     mngPtr child = std::move(*found);
     child->mParent = nullptr;
     return child;
    */
}

void SceneNode::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    drawCurrent(target, states);
    for (const mngPtr &child : mChildren)
    {
        child->draw(target, states);
    }
}