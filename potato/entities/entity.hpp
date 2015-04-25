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

    void        damage(int points);
    void        heal(int points);
    void        destroy();
    int         getHealthpoints() const;
    bool        isDestroyed() const;

    void        playLocalSound(CommandQueue& commands, Sounds::ID sound);

protected:
    virtual void    updateCurrent(sf::Time, CommandQueue&);

private:
    int         mHealthpoints;
};

#endif // ENTITY_H
