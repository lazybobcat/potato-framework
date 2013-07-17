#ifndef STATE_H
#define STATE_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <memory>

#include "stateidentifiers.h"
#include "../resources/resourceidentifiers.h"
#include "../resources/resourceholder.h"

class StateStack;
class PlayerController;

class State
{
public:
    typedef std::unique_ptr<State> Ptr;

    struct Context
    {
        Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, PlayerController& player);

        sf::RenderWindow*   window;
        TextureHolder*      textures;
        FontHolder*         fonts;
        PlayerController*   player;
    };

public:
    State(StateStack& stack, Context context);
    virtual         ~State();

    virtual void    draw() = 0;
    virtual bool    update(sf::Time dt) = 0;
    virtual bool    handleEvent(const sf::Event& event) = 0;

protected:
    void            requestStackPush(States::ID id);
    void            requestStackPop();
    void            requestStackClear();

    Context         getContext() const;

private:
    StateStack*     mStack;
    Context         mContext;
};

#endif // STATE_H
