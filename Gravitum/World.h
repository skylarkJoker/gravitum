#pragma once

#include "SFML/System/NonCopyable.hpp"
#include "ResourceLoader.hpp"
#include "SceneNode.hpp"
#include "SpriteNode.hpp"
#include "Player.hpp"
#include "Ground.h"
#include "DrawBox.hpp"
#include <array>

class World :
    private sf::NonCopyable
{
public:
    explicit World(sf::RenderWindow&);
    void update(sf::Time);
    void draw();

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

