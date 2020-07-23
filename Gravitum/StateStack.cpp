#include "StateStack.h"

template <typename T>
void StateStack::registerState(States::ID stateID) {
	mFactories[stateID] = [this]()
	{
		return State::Ptr(new T(*this, mContext));
	}
}

State::Ptr StateStack::createState(States::ID stateID) {
	auto found = mFactories.find(stateID);
	assert(found != mFactories.end());

	return found->second();
}

void StateStack::handleEvent(const sf::Event& event)
{
	for (auto itr = mStack.rbegin(); itr != mStack.rend(); ++itr) {
		if (!(*itr)->handleEvent(event)) {
			return;
		}
}
	applyPendingChanges();
}

void StateStack::pushState(States::ID stateID)
{
}

void StateStack::popState()
{
}

void StateStack::clearStates()
{
}

bool StateStack::isEmpty() const
{
	return false;
}

StateStack::StateStack(State::Context context)
{
}

void StateStack::update(sf::Time deltaTime) {
	for (auto itr = mStack.rbegin(); itr != mStack.rend(); ++itr) {
		if (!(*itr)->update(deltaTime)) {
			return;
		}
}
	applyPendingChanges();
}

void StateStack::draw() {
	for (auto itr = mStack.rbegin(); itr != mStack.rend(); ++itr) {
		(*itr)->draw();
	}
}

void StateStack::applyPendingChanges() {
	for (PendingChange change : mPendingList)
	{
		switch (change.action)
		{
		case Action::Push:
			mStack.push_back(createState(change.stateID));
			break;
		case Action::Pop:
			mStack.pop_back();
			break;
		case Action::Clear:
			mStack.clear();
			break;
		default:
			break;
		}
	}

	mPendingList.clear();
}
