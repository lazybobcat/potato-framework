#include <world.h>

World::World(sf::RenderWindow& window, TextureHolder &textures, FontHolder &fonts, MusicPlayer &music, SoundPlayer &sounds, ScriptPlayer &scripts, PlayerController &player) :
    mWindow(window),
    mWorldView(window.getDefaultView()),
    mTextures(textures),
    mFonts(fonts),
    mMusic(music),
    mSounds(sounds),
    mScripts(scripts),
    mPlayer(player),
    mSceneGraph(),
    mSceneLayers()
{
    loadTextures();
    buildScene();

    // Other things here, like setting the view center on the player, scores, etc...
}


void World::loadTextures()
{
    //mTextures.load(Textures::MyTextureIDHere, "assets/textures/whatever.png");
}

void World::buildScene()
{
    // Initialize layers
    for(std::size_t i = 0; i < LayerCount; ++i)
    {
        SceneNode::Ptr layer(new SceneNode());
        mSceneLayers[i] = layer.get();

        mSceneGraph.attachChild(std::move(layer));
    }

    // Tiled background
    // Add particle node to the scene
    // Player
    // Ennemies
    // ...
}

void World::update(sf::Time dt)
{
    // Game logic here

    // Forward commands to scene
    while(!mCommandQueue.isEmpty())
    {
        mSceneGraph.onCommand(mCommandQueue.pop(), dt);
    }

    // Set the listener position

    mSceneGraph.update(dt);
}

void World::draw()
{
    mWindow.setView(mWorldView);
    mWindow.draw(mSceneGraph);
}

CommandQueue& World::getCommandQueue()
{
    return mCommandQueue;
}
