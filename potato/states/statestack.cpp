#include "statestack.h"
#include <cassert>

StateStack::StateStack(State::Context context) :
    mStack(),
    mPendingList(),
    mContext(context),
    mFactories()
{
}


State::Ptr StateStack::createState(States::ID id)
{
    auto found = mFactories.find(id);
    assert(found != mFactories.end());

    return found->second();
}

void StateStack::update(sf::Time dt)
{
    // Iterate from top to bottom, stop as soon as update() returns false
    for (auto it = mStack.rbegin(); it != mStack.rend(); ++it)
    {
        if (!(*it)->update(dt))
            break;
    }

    applyPendingChanges();
}

void StateStack::draw()
{
    // Draw all active states from bottom to top
    for(State::Ptr& state : mStack)
        state->draw();
}

void StateStack::handleEvent(const sf::Event &event)
{
    for (auto it = mStack.rbegin(); it != mStack.rend(); ++it)
    {
        if (!(*it)->handleEvent(event))
            break;
    }

    applyPendingChanges();
}

void StateStack::pushState(States::ID id)
{
    mPendingList.push_back(PendingChange(Push, id));
}

void StateStack::popState()
{
    mPendingList.push_back(PendingChange(Pop));
}

void StateStack::clearStates()
{
    mPendingList.push_back(PendingChange(Clear));
}

bool StateStack::isEmpty() const
{
    return mStack.empty();
}

void StateStack::applyPendingChanges()
{
    for(PendingChange change : mPendingList)
    {
        switch(change.action)
        {
            case Push:
                if(!mStack.empty())
                {
                    mStack.back()->onPause();
                }
                mStack.push_back(createState(change.stateID));
                break;

            case Pop:
                mStack.pop_back();
                if(!mStack.empty())
                {
                    mStack.back()->onResume();
                }
                break;

            case Clear:
                mStack.clear();
            break;
        }
    }

    mPendingList.clear();
}



StateStack::PendingChange::PendingChange(Action action, States::ID stateID) :
    action(action),
    stateID(stateID)
{
}



