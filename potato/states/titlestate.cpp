#include <states/titlestate.hpp>
#include <utils.hpp>

TitleState::TitleState(StateStack &stack, Context context) :
    State(stack, context),
    mText(),
    mShowText(true),
    mTextEffectTime(sf::Time::Zero)
{
    mText.setFont(context.fonts->get(Fonts::Main));
    mText.setString("Welcome on Potato Framework ! Press any key to quit !");
    centerOrigin(mText);
    mText.setPosition(context.window->getView().getSize() / 2.f);
}


void TitleState::draw()
{
    sf::RenderWindow& window = *getContext().window;

    if (mShowText)
        window.draw(mText);
}

bool TitleState::update(sf::Time dt)
{
    mTextEffectTime += dt;

    if (mTextEffectTime >= sf::seconds(0.5f))
    {
        mShowText = !mShowText;
        mTextEffectTime = sf::Time::Zero;
    }

    return true;
}

bool TitleState::handleEvent(const sf::Event& event)
{
    // If any key is pressed, we leave
    if (event.type == sf::Event::KeyReleased)
    {
        requestStackPop();
    }

    return true;
}
