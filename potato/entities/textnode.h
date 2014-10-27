#ifndef TEXTNODE_H
#define TEXTNODE_H

#include <string>

#include <entities/scenenode.h>
#include <resources/resourceidentifiers.h>
#include <resources/resourceholder.h>

class TextNode : public SceneNode
{
public:
    TextNode(const std::string& text, const FontHolder& fonts);

    void            setText(const std::string& text);

private:
    virtual void    drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    sf::Text        mText;
};

#endif // TEXTNODE_H
