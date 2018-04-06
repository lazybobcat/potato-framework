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

#ifndef AFFECTORS_H
#define AFFECTORS_H

#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

#include <functional>

class Particle;

template <typename Affector>
std::function<void(Particle&, sf::Time)> derivedAffector(Affector& affector)
{
    return [&affector](Particle& particle, sf::Time dt) {
        return affector(particle, dt);
    };
}

#endif // AFFECTORS_H
