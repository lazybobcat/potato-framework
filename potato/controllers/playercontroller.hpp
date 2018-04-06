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

#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <map>

#include <events/command.hpp>

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

    void handleEvent(const sf::Event& event, CommandQueue& commands);
    void handleRealtimeInput(CommandQueue& commands);

    void assignKey(Action action, sf::Keyboard::Key key);
    sf::Keyboard::Key getAssignedKey(Action action) const;

private:
    void        initializeActions();
    static bool isRealtimeAction(Action action);

private:
    std::map<sf::Keyboard::Key, Action> mKeyBinding;
    std::map<Action, Command>           mActionBinding;
};

#endif // PLAYERCONTROLLER_H
