#pragma once
#include <memory>
#include "SFML/Graphics.hpp"
#include "ResourceLoader.h"
#include "PlayerEvent.h"

class StateStack;

class State
{
public:
	typedef std::unique_ptr<State> Ptr;
	struct Context{
		Context();
		Context(sf::RenderWindow& window, TextureLoader& textures, FontLoader& fonts, PlayerEvent& playerEvent);

		sf::RenderWindow* window;
		TextureLoader* textures;
		FontLoader* fonts;
		PlayerEvent* playerEvent;
	};
public:
	State(StateStack& stack, Context context);
	virtual ~State();

	virtual void draw() = 0;
	virtual bool update(sf::Time deltaTime) = 0;
	virtual bool handleEvent(const sf::Event& event) = 0;

protected:
	void requestStackPush(States::ID stateID);
	void requestStackPop();
	void requestStackClear();

	Context getContext() const;

private:
	StateStack* mStack;
	Context mContext;
};

