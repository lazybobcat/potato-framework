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

#include <entities/emitternode.hpp>
#include <entities/particlenode.hpp>

EmitterNode::EmitterNode(Particle::Type type)
  : SceneNode()
  , mAccumulatedTime(sf::Time::Zero)
  , mType(type)
  , mParticleSystem(nullptr)
{
}

void EmitterNode::updateCurrent(sf::Time dt, CommandQueue& commands)
{
    if (mParticleSystem) {
        emitParticles(dt);
    } else {
        auto finder = [this](ParticleNode& container, sf::Time) {
            if (container.getParticleType() == mType)
                mParticleSystem = &container;
        };
        Command command;
        command.action   = derivedAction<ParticleNode>(finder);
        command.category = Category::ParticleSystem;
        commands.push(command);
    }
}

void EmitterNode::emitParticles(sf::Time dt)
{
    const float    emissionRate = 30.f;
    const sf::Time interval     = sf::seconds(1.f) / emissionRate;

    mAccumulatedTime += dt;

    while (mAccumulatedTime > interval) {
        mAccumulatedTime -= interval;
        mParticleSystem->addParticle(getWorldPosition());
    }
}
