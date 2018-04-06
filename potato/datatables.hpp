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

#ifndef DATATABLES_H
#define DATATABLES_H

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Time.hpp>

#include <functional>
#include <vector>

#include <resources/resourceidentifiers.hpp>

// Example : this structure contains each information about a particle type
struct ParticleData
{
    sf::Color color;
    sf::Time  lifetime;
};

// This function inits each particle types with its basic data
std::vector<ParticleData> initializeParticleData();

#endif // DATATABLES_H
