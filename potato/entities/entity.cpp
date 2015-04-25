#include <entities/entity.hpp>
#include <entities/scenenode.hpp>
#include <events/commandqueue.hpp>

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

void Entity::playLocalSound(CommandQueue &commands, Sounds::ID sound)
{
    Command command;
    command.category = Category::SoundEffect;
    command.action = derivedAction<SoundNode>(std::bind(&SoundNode::playSound, std::placeholders::_1, sound, getWorldPosition()));

    commands.push(command);
}
