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

#ifndef SOUNDNODE_H
#define SOUNDNODE_H

#include <entities/scenenode.hpp>
#include <resources/soundplayer.hpp>

class SoundNode : public SceneNode
{
public:
    SoundNode(SoundPlayer& player);

    void playSound(Sounds::ID sound, sf::Vector2f position);

    virtual unsigned int getCategory() const;

private:
    SoundPlayer& mPlayer;
};

#endif // SOUNDNODE_H
