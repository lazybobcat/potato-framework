#ifndef EMITTERNODE_H
#define EMITTERNODE_H

#include <entities/scenenode.hpp>
#include <resources/particle.hpp>
#include <events/commandqueue.hpp>

class ParticleNode;

class EmitterNode : public SceneNode
{
public:
    explicit EmitterNode(Particle::Type type);

private:
    virtual void    updateCurrent(sf::Time dt, CommandQueue &commands);

    void            emitParticles(sf::Time dt);

private:
    sf::Time        mAccumulatedTime;
    Particle::Type  mType;
    ParticleNode*   mParticleSystem;
};

#endif // EMITTERNODE_H
