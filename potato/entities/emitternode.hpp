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

#ifndef EMITTERNODE_H
#define EMITTERNODE_H

#include <entities/scenenode.hpp>
#include <events/commandqueue.hpp>
#include <resources/particle.hpp>

class ParticleNode;

class EmitterNode : public SceneNode
{
public:
    explicit EmitterNode(Particle::Type type);

private:
    virtual void updateCurrent(sf::Time dt, CommandQueue& commands);

    void emitParticles(sf::Time dt);

private:
    sf::Time       mAccumulatedTime;
    Particle::Type mType;
    ParticleNode*  mParticleSystem;
};

#endif // EMITTERNODE_H
