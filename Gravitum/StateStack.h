#pragma once
#include "SFML/System/NonCopyable.hpp"
#include "SFML/Graphics.hpp"
#include "State.h"
#include "StateID.h"


#include <map>
#include <vector>
#include <functional>
#include <assert.h>


class StateStack : private sf::NonCopyable
{
public:
	enum class Action {
		Push,
		Pop,
		Clear
	};
public:
	explicit StateStack(State::Context context);

	template<typename T>
	void registerState(States::ID stateID);

	void update(sf::Time deltaTime);
	void draw();
	void handleEvent(const sf::Event& event);

	void pushState(States::ID stateID);
	void popState();
	void clearStates();

	bool isEmpty() const;

private:
	State::Ptr createState(States::ID stateID);
	void applyPendingChanges();

private:
	struct PendingChange {
		Action action;
		States::ID stateID;
	};

private: 
	std::vector<State::Ptr> mStack;
	std::vector<PendingChange> mPendingList;
	State::Context mContext;
	std::map<States::ID, std::function<State::Ptr()>> mFactories;
};

