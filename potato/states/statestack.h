#ifndef STATESTACK_H
#define STATESTACK_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <vector>
#include <utility>
#include <functional>
#include <map>

#include "state.h"

class StateStack : private sf::NonCopyable
{
public:
    enum Action
    {
        Push,
        Pop,
        Clear
    };

public:
    explicit StateStack(State::Context context);

    template <typename T>
    void                registerState(States::ID id);
    void                update(sf::Time dt);
    void                draw();
    void                handleEvent(const sf::Event& event);

    void                pushState(States::ID id);
    void                popState();
    void                clearStates();

    bool                isEmpty() const;

private:
    State::Ptr			createState(States::ID id);
    void				applyPendingChanges();

private:
    struct PendingChange
    {
        explicit PendingChange(Action action, States::ID id = States::None);
        Action      action;
        States::ID  stateID;
    };

private:
    std::vector<State::Ptr>                             mStack;
    std::vector<PendingChange>                          mPendingList;
    State::Context                                      mContext;
    std::map<States::ID,std::function<State::Ptr()>>    mFactories;
};

template <typename T>
void StateStack::registerState(States::ID id)
{
    mFactories[id] = [this] ()
    {
        return State::Ptr(new T(*this, mContext));
    };
}

#endif // STATESTACK_H
