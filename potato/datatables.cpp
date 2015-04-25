#include <datatables.hpp>
#include <resources/particle.hpp>


std::vector<ParticleData> initializeParticleData()
{
    std::vector<ParticleData> data(Particle::ParticleCount);

    data[Particle::Default].color = sf::Color(255, 255, 50);
    data[Particle::Default].lifetime = sf::seconds(0.6f);

    return data;
}

