#ifndef AFFECTORS_H
#define AFFECTORS_H

#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

#include <functional>

class Particle;

template <typename Affector>
std::function<void(Particle&, sf::Time)> derivedAffector(Affector& affector)
{
    return [&affector] (Particle& particle, sf::Time dt)
    {
        return affector(particle, dt);
    };
}

#endif // AFFECTORS_H
