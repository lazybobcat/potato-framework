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

#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

#include <list>

#include <resources/resourceholder.hpp>
#include <resources/resourceidentifiers.hpp>

class SoundPlayer : private sf::NonCopyable
{
public:
    SoundPlayer();

    void play(Sounds::ID sound);
    void play(Sounds::ID sound, sf::Vector2f position);

    void removeStoppedSounds();
    void setListenerPosition(sf::Vector2f position);
    sf::Vector2f getListenerPosition() const;

private:
    SoundHolder          mSoundBuffers;
    std::list<sf::Sound> mSounds;
};

#endif // SOUNDPLAYER_H
