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

#include <GUI/button.hpp>
#include <SFML/Graphics.hpp>
#include <utils.hpp>

using namespace GUI;

Button::Button(const FontHolder& fonts, const TextureHolder& /*textures*/)
  : mCallback()
  ,
  //mButtonTexture(),
  mSprite()
  , mText("", fonts.get(Fonts::Main), 16)
  , mIsToggled(false)
{
    sf::IntRect textureRect(0, 0, 200, 50);
    //mSprite.setTexture(mButtonTexture);
    mSprite.setTextureRect(textureRect);

    sf::FloatRect bounds = mSprite.getLocalBounds();
    mText.setPosition(bounds.width / 2.f, bounds.height / 2.f);
}

void Button::setCallback(Callback callback)
{
    mCallback = std::move(callback);
}

void Button::setText(const std::string& text)
{
    mText.setString(text);
    centerOrigin(mText);
}

void Button::setToggle(bool flag)
{
    mIsToggled = flag;
}

bool Button::isSelectable() const
{
    return true;
}

void Button::select()
{
    Widget::select();

    mSprite.setTextureRect(sf::IntRect(0, 50, 200, 50));
}

void Button::deselect()
{
    Widget::deselect();

    mSprite.setTextureRect(sf::IntRect(0, 0, 200, 50));
}

void Button::activate()
{
    Widget::activate();
    if (mIsToggled)
        mSprite.setTextureRect(sf::IntRect(0, 100, 200, 50));

    if (mCallback)
        mCallback();

    if (!mIsToggled)
        deactivate();
}

void Button::deactivate()
{
    Widget::deactivate();

    if (mIsToggled) {
        if (isSelected())
            mSprite.setTextureRect(sf::IntRect(0, 50, 200, 50));
        else
            mSprite.setTextureRect(sf::IntRect(0, 0, 200, 50));
    }
}

void Button::handleEvent(const sf::Event&)
{
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(mSprite, states);
    target.draw(mText, states);
}
