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

#include <GUI/label.hpp>

using namespace GUI;

Label::Label(const std::string& text, const FontHolder& fonts)
  : mText(text, fonts.get(Fonts::Main), 16)
{
}

bool Label::isSelectable() const
{
    return false;
}

void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(mText, states);
}

void Label::handleEvent(const sf::Event&)
{
}

void Label::setText(const std::string& text)
{
    mText.setString(text);
}
