#ifndef SPRITENODE_H
#define SPRITENODE_H

#include <entities/scenenode.h>

class SpriteNode : public SceneNode
{
public:
    explicit SpriteNode(const sf::Texture& texture);
             SpriteNode(const sf::Texture &texture, const sf::IntRect& rect);

private:
    virtual void    drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    sf::Sprite      mSprite;
};

#endif // SPRITENODE_H
