#ifndef DATATABLES_H
#define DATATABLES_H

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>

#include <vector>
#include <functional>

#include "resources/resourceidentifiers.h"

struct ParticleData
{
    sf::Color   color;
    sf::Time    lifetime;
};

std::vector<ParticleData>	initializeParticleData();


#endif // DATATABLES_H
