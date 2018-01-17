#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <memory>

#include <resources/musicplayer.hpp>
#include <resources/resourceholder.hpp>
#include <resources/resourceidentifiers.hpp>
#include <resources/scriptplayer.hpp>
#include <resources/soundplayer.hpp>
#include <states/stateidentifiers.hpp>

class StateStack;
class PlayerController;

class State
{
public:
    typedef std::unique_ptr<State> Ptr;

    struct Context
    {
        Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, SoundPlayer& sounds, MusicPlayer& music, ScriptPlayer& scripts, PlayerController& player);

        sf::RenderWindow* window;
        TextureHolder*    textures;
        FontHolder*       fonts;
        SoundPlayer*      sounds;
        MusicPlayer*      music;
        ScriptPlayer*     scripts;
        PlayerController* player;
    };

public:
    State(StateStack& stack, Context context);
    virtual ~State();

    virtual void draw()                              = 0;
    virtual bool update(sf::Time dt)                 = 0;
    virtual bool handleEvent(const sf::Event& event) = 0;

    virtual void onCreate();
    virtual void onDestroy();
    virtual void onPause();
    virtual void onResume();

protected:
    void requestStackPush(States::ID id);
    void requestStackPop();
    void requestStackClear();

    Context getContext() const;

private:
    StateStack* mStack;
    Context     mContext;
};

#endif // STATE_H
