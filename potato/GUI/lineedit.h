#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <string>
#include <cstring>

#include <GUI/widget.h>
#include <resources/resourceholder.h>
#include <resources/resourceidentifiers.h>

namespace GUI
{

class LineEdit: public Widget
{
public:
    LineEdit(FontHolder& fonts, const std::string& text = "");

    virtual bool    isSelectable() const;
    virtual void    activate();
    virtual void    deactivate();
    virtual void    handleEvent(const sf::Event &event);

    void            setText(const std::string& text);
    void            setCharacterSize(unsigned int size);
    void            setSize(sf::Vector2i size);
    void            setSize(unsigned int x, unsigned int y);
    void            setColor(const sf::Color& color);

    std::string     getString() const;

protected:
    virtual void    draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    void            moveCursorLeft();
    void            moveCursorRight();
    void            insertCharacter(char c);
    void            backspace();
    void            adaptTextToBox();

private:
    std::string         mString;
    sf::Text            mText;
    sf::RectangleShape  mShape;
    std::size_t         mCursorPosition;
};

}

#endif // LINEEDIT_H
