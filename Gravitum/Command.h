#pragma once
#include <functional>
#include "SFML/System.hpp"

class SceneNode;

struct Command {
	Command();
	std::function<void(SceneNode&, sf::Time)> action;
	unsigned int category;
};
