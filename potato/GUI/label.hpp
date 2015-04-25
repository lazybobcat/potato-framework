#ifndef LABEL_H
#define LABEL_H

#include <string>

#include <GUI/widget.hpp>
#include <resources/resourceidentifiers.hpp>
#include <resources/resourceholder.hpp>


namespace GUI
{

class Label : public Widget
{
public:
    typedef std::shared_ptr<Label> Ptr;

public:
    Label(const std::string& text, const FontHolder& fonts);

    virtual bool        isSelectable() const;
    void                setText(const std::string& text);

    virtual void        handleEvent(const sf::Event &event);

private:
    virtual void        draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    sf::Text            mText;
};

}

#endif // LABEL_H
