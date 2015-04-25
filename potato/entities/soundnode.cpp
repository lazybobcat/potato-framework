#include <entities/soundnode.hpp>

SoundNode::SoundNode(SoundPlayer &player) :
    SceneNode(Category::SoundEffect),
    mPlayer(player)
{
}

void SoundNode::playSound(Sounds::ID sound, sf::Vector2f position)
{
    mPlayer.play(sound, position);
}

unsigned int SoundNode::getCategory() const
{
    return Category::SoundEffect;
}
