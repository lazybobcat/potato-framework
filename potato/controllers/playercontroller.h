#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <map>

#include "../events/command.h"

class CommandQueue;

class PlayerController : private sf::NonCopyable
{
public:
    enum Action
    {
        // Player Actions here...
        MoveLeft,
        MoveRight,
        MoveUp,
        MoveDown,
        // Fire ? LaunchMissile ? Jump ? ...
        ActionCount
    };

public:
    PlayerController();

    void                handleEvent(const sf::Event& event, CommandQueue& commands);
    void                handleRealtimeInput(CommandQueue& commands);

    void                assignKey(Action action, sf::Keyboard::Key key);
    sf::Keyboard::Key   getAssignedKey(Action action) const;

private:
    void                initializeActions();
    static bool         isRealtimeAction(Action action);

private:
    std::map<sf::Keyboard::Key, Action>		mKeyBinding;
    std::map<Action, Command>				mActionBinding;
};

#endif // PLAYER_H
