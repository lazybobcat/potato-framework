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

#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <cstring>
#include <string>

#include <GUI/widget.hpp>
#include <resources/resourceholder.hpp>
#include <resources/resourceidentifiers.hpp>

namespace GUI {

class LineEdit : public Widget
{
public:
    LineEdit(FontHolder& fonts, const std::string& text = "");

    virtual bool isSelectable() const;
    virtual void activate();
    virtual void deactivate();
    virtual void handleEvent(const sf::Event& event);

    void setText(const std::string& text);
    void setCharacterSize(unsigned int size);
    void setSize(sf::Vector2i size);
    void setSize(unsigned int x, unsigned int y);
    void setColor(const sf::Color& color);

    std::string getString() const;

protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    void moveCursorLeft();
    void moveCursorRight();
    void insertCharacter(char c);
    void backspace();
    void adaptTextToBox();

private:
    std::string        mString;
    sf::Text           mText;
    sf::RectangleShape mShape;
    std::size_t        mCursorPosition;
};
}

#endif // LINEEDIT_H
