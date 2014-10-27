#ifndef STATE_H
#define STATE_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <memory>

#include <states/stateidentifiers.h>
#include <resources/resourceidentifiers.h>
#include <resources/resourceholder.h>
#include <resources/musicplayer.h>
#include <resources/soundplayer.h>
#include <resources/scriptplayer.h>

class StateStack;
class PlayerController;

class State
{
public:
    typedef std::unique_ptr<State> Ptr;

    struct Context
    {
        Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, SoundPlayer& sounds, MusicPlayer& music, ScriptPlayer& scripts, PlayerController& player);

        sf::RenderWindow*   window;
        TextureHolder*      textures;
        FontHolder*         fonts;
        SoundPlayer*        sounds;
        MusicPlayer*        music;
        ScriptPlayer*       scripts;
        PlayerController*   player;
    };

public:
    State(StateStack& stack, Context context);
    virtual         ~State();

    virtual void    draw() = 0;
    virtual bool    update(sf::Time dt) = 0;
    virtual bool    handleEvent(const sf::Event& event) = 0;

    virtual void    onCreate();
    virtual void    onDestroy();
    virtual void    onPause();
    virtual void    onResume();

protected:
    void            requestStackPush(States::ID id);
    void            requestStackPop();
    void            requestStackClear();

    Context         getContext() const;

private:
    StateStack*     mStack;
    Context         mContext;
};

#endif // STATE_H
