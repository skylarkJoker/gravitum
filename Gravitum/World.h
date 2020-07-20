#pragma once

#include "SFML/System/NonCopyable.hpp"
#include "ResourceLoader.h"
#include "SceneNode.h"
#include "SpriteNode.h"
#include "Player.h"
#include "Ground.h"
#include "DrawBox.h"
#include <array>
#include "CommandQueue.h"

class World :
    private sf::NonCopyable
{
public:
    explicit World(sf::RenderWindow&);
	~World();
    void update(sf::Time);
    void draw();
	CommandQueue& getCommandQueue();

private:
    void loadTextures();
    void buildScene();

private:
    enum Layer{
        Background,
        Midground,
        Foreground,
        LayerCount
    };
private:

	CommandQueue mCommandQueue;
    sf::RenderWindow& mWindow;
    sf::View mWorldView;

    TextureLoader mTextures;
    SceneNode mSceneGraph;
    std::array<SceneNode*, LayerCount> mSceneLayers;

    sf::FloatRect mWorldBounds;
    sf::Vector2f mSpawnPosition;
    float mScrollSpeed;
    Player* mPlayer;
    Ground* mGround;

    int32 velocityIterations;
    int32 positionIterations;
    b2Vec2 mGravity;
    b2World mWorld;
    DrawBox drawBox;

};

