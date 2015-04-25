#ifndef SOUNDNODE_H
#define SOUNDNODE_H

#include <entities/scenenode.hpp>
#include <resources/soundplayer.hpp>

class SoundNode : public SceneNode
{
public:
    SoundNode(SoundPlayer& player);

    void    playSound(Sounds::ID sound, sf::Vector2f position);

    virtual unsigned int    getCategory() const;

private:
    SoundPlayer&    mPlayer;
};

#endif // SOUNDNODE_H
