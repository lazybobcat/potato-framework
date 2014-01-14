#include "state.h"
#include "statestack.h"
#include "../controllers/playercontroller.h"

State::Context::Context(sf::RenderWindow &window, TextureHolder &textures, FontHolder &fonts, SoundPlayer& sounds, MusicPlayer& music, ScriptPlayer& scripts, PlayerController &player) :
    window(&window),
    textures(&textures),
    fonts(&fonts),
    sounds(&sounds),
    music(&music),
    scripts(&scripts),
    player(&player)
{
}

State::State(StateStack &stack, Context context) :
    mStack(&stack),
    mContext(context)
{
}

State::~State()
{
}

void State::requestStackPush(States::ID stateID)
{
    mStack->pushState(stateID);
}

void State::requestStackPop()
{
    mStack->popState();
}

void State::requestStackClear()
{
    mStack->clearStates();
}

void State::onPause()
{

}

void State::onResume()
{

}

State::Context State::getContext() const
{
    return mContext;
}
