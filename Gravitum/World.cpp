#include "World.h"

World::World(sf::RenderWindow& window)
	:
	mWindow(window),
	mWorldView(window.getDefaultView()),
	mWorldBounds(
		0.f,
		0.f,
		mWorldView.getSize().x,
		mWorldView.getSize().y),
	mSpawnPosition(
		mWorldView.getSize().x / 2.f,
		mWorldView.getSize().y / 2.f),
	mPlayer(nullptr),
	mGravity(0.f, 10.f),
	mWorld(mGravity),
	drawBox(window),
	velocityIterations(6),
	positionIterations(2)
{
	loadTextures();
	buildScene();
	
	mWorldView.setCenter(mSpawnPosition);
	mWorld.SetDebugDraw(&drawBox);
	drawBox.SetFlags(b2Draw::e_shapeBit);
}

void World::loadTextures()
{
	mTextures.load(Textures::ID::Player, "img/tex/female/female_stand.png");
	mTextures.load(Textures::ID::Player2, "img/tex/male/adventurer_stand.png");

	mTextures.load(Textures::ID::Ground, "img/tex/ground/slice03_03.png");
	mTextures.get(Textures::ID::Ground).setRepeated(true);

	mTextures.load(Textures::ID::Background, "img/tex/bg/backgroundEmpty.png");
}

void World::buildScene()
{
	for (std::size_t i = 0; i < LayerCount; ++i)
	{
		SceneNode::mngPtr layer(new SceneNode());
		mSceneLayers[i] = layer.get();

		mSceneGraph.attachChild(std::move(layer));
	}

	//set background  
	sf::Texture& texture = mTextures.get(Textures::ID::Background);
	sf::IntRect textureRect(sf::FloatRect(0.f, 0.f, mWorldBounds.width, texture.getSize().y));
	texture.setRepeated(true);

	std::unique_ptr<SpriteNode> backgroundSprite(
	new SpriteNode(texture, textureRect));
	backgroundSprite->setPosition(0, 0);
	mSceneLayers[Background]
		->attachChild(std::move(backgroundSprite));

	//create ground
	std::unique_ptr<Ground> ground(new Ground(Ground::Type::Normal, mTextures));
	mGround = ground.get();
	mGround->setBodyPos(mSpawnPosition.x, 800.f, mWorld);
	mGround->setup(800.f, 70.f, 0.f, 0.f);
	mGround->setupSprite();
	mSceneLayers[Midground]->attachChild(std::move(ground));

	//set up player and init velocity add to AIR layer
	std::unique_ptr<Player> playerOne(new Player(
		Player::Type::Main, mTextures));
	mPlayer = playerOne.get();
	mPlayer->setBodyPos(mSpawnPosition.x, mSpawnPosition.y, mWorld);
	mPlayer->setup(80.f, 110.f, 1.f, 0.3f);
	mPlayer->setupSprite();
	mSceneLayers[Midground]->attachChild(std::move(playerOne));

}

void World::draw() {
	mWindow.setView(mWorldView);
	mWindow.draw(mSceneGraph);
	mWorld.DebugDraw();
 }

void World::update(sf::Time deltaTime) {

	//mWorldView.setCenter(mPlayer->getPosition());
	mWorld.Step(deltaTime.asSeconds(), velocityIterations, positionIterations);
	mSceneGraph.update(deltaTime);
}
