#include "entity.h"
#include "../entities/scenenode.h"

Entity::Entity(int healthpoints) :
    mHealthpoints(healthpoints)
{
}

void Entity::updateCurrent(sf::Time)
{

}

void Entity::damage(int points)
{
    mHealthpoints -= points;
}

void Entity::heal(int points)
{
    mHealthpoints += points;
}

void Entity::destroy()
{
    mHealthpoints = 0;
}

int Entity::getHealthpoints() const
{
    return mHealthpoints;
}

bool Entity::isDestroyed() const
{
    return (mHealthpoints <= 0);
}
