#ifndef BUTTON_H
#define BUTTON_H

#include <vector>
#include <string>
#include <functional>

#include <GUI/widget.h>
#include <resources/resourceholder.h>
#include <resources/resourceidentifiers.h>

namespace GUI
{

class Button : public Widget
{
public:
    typedef std::shared_ptr<Button> Ptr;
    typedef std::function<void()>   Callback;

public:
    Button(const FontHolder& fonts, const TextureHolder& textures);

    void            setCallback(Callback callback);
    void            setText(const std::string& text);
    void            setToggle(bool flag);

    virtual bool    isSelectable() const;
    virtual void    select();
    virtual void    deselect();

    virtual void    activate();
    virtual void    deactivate();

    virtual void    handleEvent(const sf::Event &event);

private:
    virtual void    draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    Callback            mCallback;
    //const sf::Texture&  mButtonTexture;
    sf::Sprite          mSprite;
    sf::Text            mText;
    bool                mIsToggled;
};

}

#endif // BUTTON_H
