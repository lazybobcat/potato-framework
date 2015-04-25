#include <entities/particlenode.hpp>
#include <datatables.hpp>

#include <iostream>

namespace
{
    const std::vector<ParticleData> Table = initializeParticleData();
}

ParticleNode::ParticleNode(Particle::Type type, const TextureHolder &textures) :
    SceneNode(Category::ParticleSystem),
    mParticles(),
    mAffectors(),
    mTexture(textures.get(Textures::Particle)),
    mType(type),
    mVertexArray(sf::Quads),
    mNeedsVertexUpdate(false)
{
}


void ParticleNode::addParticle(sf::Vector2f position)
{
    Particle p;
    p.position  = position;
    p.color     = Table[mType].color;
    p.lifetime  = Table[mType].lifetime;

    mParticles.push_back(p);
}

void ParticleNode::updateCurrent(sf::Time dt, CommandQueue &/*commands*/)
{
    while(!mParticles.empty() && mParticles.front().lifetime <= sf::Time::Zero)
        mParticles.pop_front();

    for(Particle& p : mParticles)
    {
        p.lifetime -= dt;
        for(Affector& affector : mAffectors)
        {
            affector(p, dt);
        }
    }

    mNeedsVertexUpdate = true;
}

void ParticleNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    if(mNeedsVertexUpdate)
    {
        computeVertices();
        mNeedsVertexUpdate = false;
    }

    states.texture = &mTexture;
    target.draw(mVertexArray, states);
}

void ParticleNode::computeVertices() const
{
    sf::Vector2f size(mTexture.getSize());
    sf::Vector2f half = size / 2.f;

    mVertexArray.clear();

    for(const Particle& p : mParticles)
    {
        sf::Vector2f pos = p.position;
        sf::Color color  = p.color;

        float ratio = p.lifetime.asSeconds() / Table[mType].lifetime.asSeconds();
        color.a = static_cast<sf::Uint8>(255*std::max(ratio, 0.f));

        addVertex(pos.x - half.x, pos.y - half.y, 0.f, 0.f, color);
        addVertex(pos.x + half.x, pos.y - half.y, size.x, 0.f, color);
        addVertex(pos.x + half.x, pos.y + half.y, size.x, size.y, color);
        addVertex(pos.x - half.x, pos.y + half.y, 0.f, size.y, color);
    }
}

void ParticleNode::addVertex(float worldX, float worldY, float texCoordX, float texCoordY, const sf::Color &color) const
{
    sf::Vertex vertex;
    vertex.position = sf::Vector2f(worldX, worldY);
    vertex.texCoords = sf::Vector2f(texCoordX, texCoordY);
    vertex.color = color;

    mVertexArray.append(vertex);
}


void ParticleNode::addAffector(std::function<void (Particle &, sf::Time)> affector)
{
    mAffectors.push_back(Affector(std::move(affector)));
}



Particle::Type ParticleNode::getParticleType() const
{
    return mType;
}


