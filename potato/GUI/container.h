#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>

#include <GUI/widget.h>

namespace GUI
{

class Container : public Widget
{
public:
    typedef std::shared_ptr<Container> Ptr;

public:
    Container();

    void            pack(Widget::Ptr widget);

    virtual bool    isSelectable() const;
    virtual void    handleEvent(const sf::Event &event);

private:
    virtual void    draw(sf::RenderTarget &target, sf::RenderStates states) const;

    bool            hasSelection() const;
    void            select(std::size_t index);
    void            selectNext();
    void            selectPrevious();

private:
    std::vector<Widget::Ptr>    mChildren;
    int                         mSelectedChild;
};

}

#endif // CONTAINER_H
