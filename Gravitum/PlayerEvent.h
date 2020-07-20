#pragma once
#include "SFML/Window.hpp"
#include "CommandQueue.h"
#include "Player.h"
#include "box2d/box2d.h"

template <typename GameObj, typename Function>
std::function<void(SceneNode&, sf::Time)> derivedAction(Function fn) {
	return [=](SceneNode& node, sf::Time deltaTime){
		assert(dynamic_cast<GameObj*>(&node) != nullptr);

		fn(static_cast<GameObj&>(node), deltaTime);
	};
}

struct PlayerMove {
	PlayerMove(b2Vec2 v):velocity(v){}

	void operator() (Player& player, sf::Time) const {
		player.moveBody(velocity);
	}

	b2Vec2 velocity;
};

class PlayerEvent
{
public:
	void handleEvent(const sf::Event& event, CommandQueue& commands);
	void handleRealtimeInput(CommandQueue& commands);
};

