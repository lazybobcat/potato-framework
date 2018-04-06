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

#ifndef WIDGET_H
#define WIDGET_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <memory>

namespace GUI {

class Widget : public sf::Drawable, public sf::Transformable, private sf::NonCopyable
{
public:
    typedef std::shared_ptr<Widget> Ptr;

public:
    Widget();
    virtual ~Widget();

    virtual bool isSelectable() const = 0;
    bool         isSelected() const;
    virtual void select();
    virtual void deselect();

    virtual bool isActive() const;
    virtual void activate();
    virtual void deactivate();

    virtual void handleEvent(const sf::Event& event) = 0;

protected:
    bool mIsSelected;
    bool mIsActive;
};
}

#endif // WIDGET_H
