#include <entities/textnode.hpp>
#include <utils.hpp>

TextNode::TextNode(const std::string& text, const FontHolder& fonts) :
    mText(text, fonts.get(Fonts::Main), 20)
{
    centerOrigin(mText);
}

void TextNode::setText(const std::string &text)
{
    mText.setString(text);
    centerOrigin(mText);
}

void TextNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mText, states);
}
