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

#include <entities/soundnode.hpp>

SoundNode::SoundNode(SoundPlayer& player)
  : SceneNode(Category::SoundEffect)
  , mPlayer(player)
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
