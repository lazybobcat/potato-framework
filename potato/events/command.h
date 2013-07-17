#ifndef COMMAND_H
#define COMMAND_H

#include <SFML/System.hpp>

#include <functional>
#include <cassert>

#include "category.h"

class SceneNode;

struct Command
{
    Command();

    std::function<void(SceneNode&, sf::Time)>   action;
    unsigned int                                category;
};

template <typename GameObject, typename Function>
std::function<void(SceneNode&, sf::Time)> derivedAction(Function fn)
{
    return [=](SceneNode& node, sf::Time dt)
    {
        assert(dynamic_cast<GameObject*>(&node) != nullptr);
        fn(static_cast<GameObject&>(node), dt);
    };
}

#endif // COMMAND_H
