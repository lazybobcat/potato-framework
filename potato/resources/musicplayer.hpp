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

#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

#include <map>
#include <string>

#include <resources/resourceholder.hpp>
#include <resources/resourceidentifiers.hpp>

class MusicPlayer : private sf::NonCopyable
{
public:
    MusicPlayer();

    void play(Musics::ID song);
    void stop();
    void pause(bool flag = true);
    void setVolume(float volume);

private:
    sf::Music mMusic;
    std::map<Musics::ID, std::string> mFilenames;
    float mVolume;
};

#endif // MUSICPLAYER_H
