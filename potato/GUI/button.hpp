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

#ifndef BUTTON_H
#define BUTTON_H

#include <functional>
#include <string>
#include <vector>

#include <GUI/widget.hpp>
#include <resources/resourceholder.hpp>
#include <resources/resourceidentifiers.hpp>

namespace GUI {

class Button : public Widget
{
public:
    typedef std::shared_ptr<Button> Ptr;
    typedef std::function<void()>   Callback;

public:
    Button(const FontHolder& fonts, const TextureHolder&);

    void setCallback(Callback callback);
    void setText(const std::string& text);
    void setToggle(bool flag);

    virtual bool isSelectable() const;
    virtual void select();
    virtual void deselect();

    virtual void activate();
    virtual void deactivate();

    virtual void handleEvent(const sf::Event& event);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    Callback mCallback;
    //const sf::Texture&  mButtonTexture;
    sf::Sprite mSprite;
    sf::Text   mText;
    bool       mIsToggled;
};
}

#endif // BUTTON_H
