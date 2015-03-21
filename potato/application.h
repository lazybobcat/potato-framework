#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <resources/resourceidentifiers.h>
#include <resources/resourceholder.h>
#include <controllers/playercontroller.h>
#include <states/statestack.h>

class Application
{
public:
    Application(unsigned int width, unsigned int height, const std::string& title);
    void        run();

private:
    void        processEvents();
    void        update(sf::Time dt);
    void        render();

    void        registerStates();
    void        updateStatistics(sf::Time elapsedTime);

private:
    static const sf::Time   TimePerFrame;
    sf::RenderWindow        mWindow;
    // Textures, Fonts, Sounds, ...
    TextureHolder           mTextures;
    FontHolder              mFonts;
    SoundPlayer             mSounds;
    MusicPlayer             mMusic;
    ScriptPlayer            mScripts;
    PlayerController        mPlayer;

    StateStack              mStateStack;

    // Statistics
    sf::Text				mStatisticsText;
    sf::Time				mStatisticsUpdateTime;
    std::size_t             mStatisticsNumFrames;
};

#endif // APPLICATION_H
