#include "PlayerEvent.h"

void PlayerEvent::handleEvent(const sf::Event & event, CommandQueue & commands)
{
}

void PlayerEvent::handleRealtimeInput(CommandQueue & commands)
{
	const float speed = 20.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		Command moveRight;
		moveRight.category = Category::Player;
		moveRight.action = derivedAction<Player>(PlayerMove(b2Vec2(speed, 0.f)));
		commands.push(moveRight);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		Command moveLeft;
		moveLeft.category = Category::Player;
		moveLeft.action = derivedAction<Player>(PlayerMove(b2Vec2(-speed, 0.f)));
		commands.push(moveLeft);
	}
	else {
		Command stop;
		stop.category = Category::Player;
		stop.action = derivedAction<Player>(PlayerMove(b2Vec2(0.f, 0.f)));
		commands.push(stop);
	}
}
