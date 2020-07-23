#include "PlayerEvent.h"

PlayerEvent::PlayerEvent()
{
	mKeyBinding[sf::Keyboard::A] = Action::MoveLeft;
	mKeyBinding[sf::Keyboard::D] = Action::MoveRight;
	
	mActionBinding[Action::MoveLeft].action = derivedAction<Player>(PlayerMove(b2Vec2(-mSpeed, 0.f)));
	mActionBinding[Action::MoveRight].action = derivedAction<Player>(PlayerMove(b2Vec2(mSpeed, 0.f)));
	mActionBinding[Action::Stand].action = derivedAction<Player>(PlayerMove(b2Vec2(0.f, 0.f)));

	for (auto& pair : mActionBinding) {
		pair.second.category = Category::Player;
	}


}

void PlayerEvent::handleEvent(const sf::Event & event, CommandQueue & commands)
{
}

void PlayerEvent::handleRealtimeInput(CommandQueue & commands)
{
	const float speed = 20.f;

	for (auto pair : mKeyBinding) {
		if (sf::Keyboard::isKeyPressed(pair.first) && isRealtimeAction(pair.second))
			commands.push(mActionBinding[pair.second]);
		else
			commands.push(mActionBinding[Action::Stand]);
	}
}

bool PlayerEvent::isRealtimeAction(Action action)
{
	return true;
}
