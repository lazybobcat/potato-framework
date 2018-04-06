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

#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/System/Time.hpp>

#include <entities/scenenode.hpp>
#include <entities/soundnode.hpp>
#include <events/commandqueue.hpp>

class CommandQueue;

class Entity : public SceneNode
{
public:
    Entity(int healthpoints = 1);

    void damage(int points);
    void heal(int points);
    void destroy();
    int  getHealthpoints() const;
    bool isDestroyed() const;

    void playLocalSound(CommandQueue& commands, Sounds::ID sound);

protected:
    virtual void updateCurrent(sf::Time, CommandQueue&);

private:
    int mHealthpoints;
};

#endif // ENTITY_H
