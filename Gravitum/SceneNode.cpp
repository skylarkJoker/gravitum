#include "SceneNode.h"
#include "Command.h"

void SceneNode::update(sf::Time deltaTime)
{
    updateCurrent(deltaTime);
    for (const mngPtr &child : mChildren)
    {
        child->update(deltaTime);
    }
}

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
void SceneNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {}

void SceneNode::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    drawCurrent(target, states);
    for (const mngPtr &child : mChildren)
    {
        child->draw(target, states);
    }
}

void SceneNode::updateCurrent(sf::Time) {}

void SceneNode::updateChildren(sf::Time deltaTime) {
    for (mngPtr& child: mChildren) {
        child->update(deltaTime);
    }
}

sf::Transform SceneNode::getWorldTransform() const {
    sf::Transform transform = sf::Transform::Identity;
    for (const SceneNode* node = this; node != nullptr; node = node->mParent) {
        transform = node->getTransform() * transform;
    }
    return transform;
}

sf::Vector2f SceneNode::getWorldPosition() const {
    return getWorldTransform() * sf::Vector2f();
}

unsigned int SceneNode::getCategory() const
{
	return Category::Scene;
}

void SceneNode::onCommand(const Command& command, sf::Time deltaTime) {
	if (command.category & getCategory()) {
		command.action(*this, deltaTime);
	}

	for (mngPtr& child : mChildren) {
		child->onCommand(command, deltaTime);
	}
}
