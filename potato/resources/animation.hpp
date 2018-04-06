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

#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>

class Animation : public sf::Drawable, public sf::Transformable
{
public:
    Animation();
    explicit Animation(const sf::Texture& texture);

    void setTexture(const sf::Texture& texture);
    const sf::Texture* getTexture() const;

    void setFrameSize(sf::Vector2i size);
    sf::Vector2i getFrameSize() const;

    void setNumFrames(std::size_t numFrames);
    std::size_t getNumFrames() const;

    void setDuration(sf::Time duration);
    sf::Time getDuration() const;

    void setRepeating(bool flag);
    bool isRepeating() const;

    void restart();
    bool isFinished() const;

    sf::FloatRect getLocalBounds() const;
    sf::FloatRect getGlobalBounds() const;

    void update(sf::Time dt);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    sf::Sprite   mSprite;
    sf::Vector2i mFrameSize;
    std::size_t  mNumFrames;
    std::size_t  mCurrentFrame;
    sf::Time     mDuration;
    sf::Time     mElapsedTime;
    bool         mRepeat;
};

#endif // ANIMATION_H
