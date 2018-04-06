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

#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <controllers/playercontroller.hpp>
#include <resources/resourceholder.hpp>
#include <resources/resourceidentifiers.hpp>
#include <states/statestack.hpp>

class Application
{
public:
    Application(unsigned int width, unsigned int height, const std::string& title);
    void run();

private:
    void processEvents();
    void update(sf::Time dt);
    void render();

    void registerStates();
    void updateStatistics(sf::Time elapsedTime);

private:
    static const sf::Time TimePerFrame;
    sf::RenderWindow      mWindow;
    // Textures, Fonts, Sounds, ...
    TextureHolder    mTextures;
    FontHolder       mFonts;
    SoundPlayer      mSounds;
    MusicPlayer      mMusic;
    ScriptPlayer     mScripts;
    PlayerController mPlayer;

    StateStack mStateStack;

    // Statistics
    sf::Text    mStatisticsText;
    sf::Time    mStatisticsUpdateTime;
    std::size_t mStatisticsNumFrames;
};

#endif // APPLICATION_H
