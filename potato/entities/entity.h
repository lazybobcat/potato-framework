#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/System/Time.hpp>

#include "scenenode.h"

class Entity : public SceneNode
{
public:
    Entity(int healthpoints = 1);

    void        damage(int points);
    void        heal(int points);
    void        destroy();
    int         getHealthpoints() const;
    bool        isDestroyed() const;

protected:
    virtual void    updateCurrent(sf::Time);

private:
    int         mHealthpoints;
};

#endif // ENTITY_H
