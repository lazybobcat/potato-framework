#ifndef TEXTNODE_H
#define TEXTNODE_H

#include <string>

#include <entities/scenenode.hpp>
#include <resources/resourceholder.hpp>
#include <resources/resourceidentifiers.hpp>

class TextNode : public SceneNode
{
public:
    TextNode(const std::string& text, const FontHolder& fonts);

    void setText(const std::string& text);

private:
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    sf::Text mText;
};

#endif // TEXTNODE_H
