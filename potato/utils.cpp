#include <utils.h>
#include <random>
#include <ctime>

namespace
{
    std::default_random_engine createRandomEngine()
    {
        auto seed = static_cast<unsigned long>(std::time(nullptr));
        return std::default_random_engine(seed);
    }

    auto RandomEngine = createRandomEngine();
}

/////////////////////////////

void centerOrigin(sf::Sprite &sprite)
{
    sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
}

void centerOrigin(sf::Text& text)
{
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
}

void centerOrigin(Animation& animation)
{
    sf::FloatRect bounds = animation.getLocalBounds();
    animation.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
}

/////////////////////////////

int randomInt(int min, int max)
{
    std::uniform_int_distribution<> distr(min, max);
    return distr(RandomEngine);
}

float randomFloat(float min, float max)
{
    std::uniform_real_distribution<float> distr(min, max);
    return distr(RandomEngine);
}
