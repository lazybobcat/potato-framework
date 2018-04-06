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

#include <controllers/playercontroller.hpp>
#include <states/state.hpp>
#include <states/statestack.hpp>

State::Context::Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, SoundPlayer& sounds, MusicPlayer& music, ScriptPlayer& scripts, PlayerController& player)
  : window(&window)
  , textures(&textures)
  , fonts(&fonts)
  , sounds(&sounds)
  , music(&music)
  , scripts(&scripts)
  , player(&player)
{
}

State::State(StateStack& stack, Context context)
  : mStack(&stack)
  , mContext(context)
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

void State::onCreate()
{
}

void State::onDestroy()
{
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
