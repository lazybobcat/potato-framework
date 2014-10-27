#ifndef PARTICLENODE_H
#define PARTICLENODE_H

#include <SFML/Graphics/VertexArray.hpp>

#include <deque>
#include <vector>

#include <entities/scenenode.h>
#include <resources/resourceholder.h>
#include <resources/resourceidentifiers.h>
#include <resources/particle.h>
#include <resources/affectors.h>
#include <events/commandqueue.h>

class ParticleNode : public SceneNode
{
public:
    ParticleNode(Particle::Type type, const TextureHolder& textures);

    void                    addParticle(sf::Vector2f position);
    Particle::Type          getParticleType() const;

private:
    virtual void            updateCurrent(sf::Time dt, CommandQueue &commands);
    virtual void            drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;

    void                    addVertex(float worldX, float worldY, float texCoordX, float texCoordY, const sf::Color& color) const;
    void                    computeVertices() const;

    void                    addAffector(std::function<void(Particle&, sf::Time)> affector);

private:
    typedef std::function<void(Particle&, sf::Time)>    Affector;

private:
    std::deque<Particle>    mParticles;
    std::vector<Affector>   mAffectors;
    const sf::Texture&      mTexture;
    Particle::Type          mType;

    mutable sf::VertexArray mVertexArray;
    mutable bool            mNeedsVertexUpdate;
};

#endif // PARTICLENODE_H
