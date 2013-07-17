#ifndef TITLESTATE_H
#define TITLESTATE_H

#include <SFML/Graphics.hpp>

#include "state.h"

class TitleState : public State
{
public:
    TitleState(StateStack& stack, Context context);
    virtual void        draw();
    virtual bool        update(sf::Time dt);
    virtual bool        handleEvent(const sf::Event &event);

private:
    sf::Text            mText;
    bool                mShowText;
    sf::Time            mTextEffectTime;
};

#endif // TITLESTATE_H
