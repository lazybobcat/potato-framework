#ifndef WIDGET_H
#define WIDGET_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <memory>

namespace GUI
{

class Widget : public sf::Drawable, public sf::Transformable, private sf::NonCopyable
{
public:
    typedef std::shared_ptr<Widget> Ptr;

public:
    Widget();
    virtual ~Widget();

    virtual bool    isSelectable() const = 0;
    bool            isSelected() const;
    virtual void    select();
    virtual void    deselect();

    virtual bool    isActive() const;
    virtual void    activate();
    virtual void    deactivate();

    virtual void    handleEvent(const sf::Event& event) = 0;

protected:
    bool            mIsSelected;
    bool            mIsActive;
};

}

#endif // WIDGET_H
