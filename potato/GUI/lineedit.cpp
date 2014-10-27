#include <GUI/lineedit.h>

#include <iostream>

using namespace GUI;

LineEdit::LineEdit(FontHolder& fonts, const std::string& text) :
    Widget(),
    mString(text),
    mText(text, fonts.get(Fonts::Main)),
    mShape(),
    mCursorPosition(text.size())
{
    mText.setCharacterSize(22);
    mText.setColor(sf::Color::White);
    mShape.setSize(sf::Vector2f(350.f, 30.f));
    mShape.setFillColor(sf::Color(0, 0, 0, 130));
    mShape.setOutlineThickness(1);
    mShape.setOutlineColor(sf::Color(255,255,255, 130));
}

bool LineEdit::isSelectable() const
{
    return true;
}

void LineEdit::activate()
{
    if(!isActive())
    {
        const char* cursor = "|";
        mCursorPosition = mString.size();
        mString.insert(mCursorPosition, cursor);
        mText.setString(mString);
    }

    Widget::activate();
}

void LineEdit::deactivate()
{
    if(isActive())
    {
        mString.erase(mCursorPosition, mCursorPosition+1);
        mText.setString(mString);
    }

    Widget::deactivate();
}

void LineEdit::handleEvent(const sf::Event &event)
{
    if(!isActive())
        return;

    switch(event.type)
    {
        case sf::Event::KeyPressed:
            switch(event.key.code)
            {
                case sf::Keyboard::Tab:
                    deactivate();
                    break;

                case sf::Keyboard::Left:
                    moveCursorLeft();
                    break;

                case sf::Keyboard::Right:
                    moveCursorRight();
                    break;

                default:
                    break;
            }
            break;

        case sf::Event::TextEntered:
            if(event.text.unicode == '\e') {
                deactivate();
            }
            else if(event.text.unicode == 13) {
                deactivate();
            }
            else if(event.text.unicode == '\t') {
                deactivate();
            } else if(event.text.unicode == '\b') {
                backspace();
            } else {
                insertCharacter((char)event.text.unicode);
            }
            break;

        default:
            break;
    }

}

void LineEdit::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(mShape, states);
    target.draw(mText, states);
}

void LineEdit::moveCursorLeft()
{
    if(mCursorPosition > 0)
    {
        mString.erase(mCursorPosition, 1);
        mCursorPosition = mCursorPosition-1;
        const char* cursor = "|";
        mString.insert(mCursorPosition, cursor);
        mText.setString(mString);
    }
}

void LineEdit::moveCursorRight()
{
    if((mCursorPosition+1) < mString.size())
    {
        mString.erase(mCursorPosition, 1);
        ++mCursorPosition;
        const char* cursor = "|";
        mString.insert(mCursorPosition, cursor);
        mText.setString(mString);
    }
}

void LineEdit::insertCharacter(char c)
{
    mString.insert(mCursorPosition, 1, c);
    mCursorPosition++;
    mText.setString(mString);
    adaptTextToBox();
}

void LineEdit::backspace()
{
    if(mCursorPosition > 0)
    {
        mString.erase(mCursorPosition, 1);
        mString.erase(mCursorPosition-1, 1);
        mCursorPosition = mCursorPosition-1;
        const char* cursor = "|";
        mString.insert(mCursorPosition, cursor);
        mText.setString(mString);
    }
}

void LineEdit::adaptTextToBox()
{
    while(mText.getGlobalBounds().width > mShape.getSize().x)
    {
        mText.setCharacterSize(mText.getCharacterSize()-1);
    }
}

void LineEdit::setText(const std::string &text)
{
    mString = text;
    mCursorPosition = mString.size();
    if(isActive())
        mString += '|';
    mText.setString(mString);
    adaptTextToBox();
}

void LineEdit::setCharacterSize(unsigned int size)
{
    mText.setCharacterSize(size);
}

void LineEdit::setSize(sf::Vector2i size)
{
    mShape.setSize(sf::Vector2f((float)size.x, (float)size.y));
}

void LineEdit::setSize(unsigned int x, unsigned int y)
{
    setSize(sf::Vector2i(x, y));
}

void LineEdit::setColor(const sf::Color &color)
{
    mText.setColor(color);
}

std::string LineEdit::getString() const
{
    return mText.getString();
}



