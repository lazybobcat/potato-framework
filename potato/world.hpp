//
// Copyright (c) 2018 potato-framework by Loïc Boutter (https://github.com/Lo-X/potato-framework)
//
// Everyone is permitted to copy and distribute verbatim or modified
// copies of this license document, and changing it is allowed as long
// as the name is changed.
//
//            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
//   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
//
//  0. You just DO WHAT THE FUCK YOU WANT TO.
//

#ifndef WORLD_H
#define WORLD_H

#include <array>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <controllers/playercontroller.hpp>
#include <entities/spritenode.hpp>
#include <events/category.hpp>
#include <events/commandqueue.hpp>
#include <resources/musicplayer.hpp>
#include <resources/resourceholder.hpp>
#include <resources/resourceidentifiers.hpp>
#include <resources/scriptplayer.hpp>
#include <resources/soundplayer.hpp>

class World : public sf::NonCopyable
{
public:
    World(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, MusicPlayer& music, SoundPlayer& sounds, ScriptPlayer& scripts, PlayerController& player);

    void update(sf::Time dt);
    void draw();

    CommandQueue& getCommandQueue();

private:
    void loadTextures();
    void buildScene();

private:
    enum Layer
    {
        Background,
        Foreground,
        LayerCount
    };

private:
    sf::RenderWindow& mWindow;
    sf::View          mWorldView;
    TextureHolder&    mTextures;
    FontHolder&       mFonts;
    MusicPlayer&      mMusic;
    SoundPlayer&      mSounds;
    ScriptPlayer&     mScripts;
    PlayerController& mPlayer;

    SceneNode mSceneGraph;
    std::array<SceneNode*, LayerCount> mSceneLayers;
    CommandQueue mCommandQueue;

    // Player
};

#endif // WORLD_H
