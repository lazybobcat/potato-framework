#ifndef WORLD_H
#define WORLD_H

#include <array>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <resources/resourceholder.hpp>
#include <resources/resourceidentifiers.hpp>
#include <resources/musicplayer.hpp>
#include <resources/soundplayer.hpp>
#include <resources/scriptplayer.hpp>
#include <controllers/playercontroller.hpp>
#include <events/category.hpp>
#include <events/commandqueue.hpp>
#include <entities/spritenode.hpp>

class World : public sf::NonCopyable
{
public:
    World(sf::RenderWindow& window, TextureHolder &textures, FontHolder &fonts, MusicPlayer &music, SoundPlayer &sounds, ScriptPlayer &scripts, PlayerController &player);

    void        update(sf::Time dt);
    void        draw();

    CommandQueue&   getCommandQueue();

private:
    void        loadTextures();
    void        buildScene();

private:
    enum Layer
    {
        Background,
        Foreground,
        LayerCount
    };

private:
    sf::RenderWindow&                   mWindow;
    sf::View                            mWorldView;
    TextureHolder&                      mTextures;
    FontHolder&                         mFonts;
    MusicPlayer&                        mMusic;
    SoundPlayer&                        mSounds;
    ScriptPlayer&                       mScripts;
    PlayerController&                   mPlayer;

    SceneNode                           mSceneGraph;
    std::array<SceneNode*,LayerCount>   mSceneLayers;
    CommandQueue                        mCommandQueue;

    // Player
};

#endif // WORLD_H
