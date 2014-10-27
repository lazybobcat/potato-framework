#include <GUI/container.h>

using namespace GUI;

Container::Container() :
    Widget(),
    mSelectedChild(-1)
{
}


void Container::pack(Widget::Ptr widget)
{
    mChildren.push_back(widget);

    if(!hasSelection() && widget->isSelectable())
        select(mChildren.size() -1);
}

bool Container::isSelectable() const
{
    return false;
}

void Container::handleEvent(const sf::Event &event)
{
    if(hasSelection() && mChildren[mSelectedChild]->isActive())
    {
        mChildren[mSelectedChild]->handleEvent(event);
    }
    else if(event.type == sf::Event::KeyReleased)
    {
        switch(event.key.code)
        {
            case sf::Keyboard::Z:
            case sf::Keyboard::W:
            case sf::Keyboard::Up:
                selectPrevious();
                break;

            case sf::Keyboard::S:
            case sf::Keyboard::Down:
                selectNext();
                break;

            case sf::Keyboard::Return:
            case sf::Keyboard::Space:
                if(hasSelection())
                    mChildren[mSelectedChild]->activate();
                break;

            default:break;
        }
    }
}

void Container::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    for(const Widget::Ptr& widget : mChildren)
    {
        target.draw(*widget, states);
    }
}

bool Container::hasSelection() const
{
    return mSelectedChild >= 0;
}

void Container::select(std::size_t index)
{
    if(mChildren[index]->isSelectable())
    {
        if(hasSelection())
            mChildren[mSelectedChild]->deselect();

        mChildren[index]->select();
        mSelectedChild = index;
    }
}

void Container::selectNext()
{
    if(!hasSelection())
        return;

    int next = mSelectedChild;
    do
        next = (next + 1) % mChildren.size();
    while(!mChildren[next]->isSelectable());

    select(next);
}

void Container::selectPrevious()
{
    if(!hasSelection())
        return;

    int prev = mSelectedChild;
    do
        prev = (prev + mChildren.size() - 1) % mChildren.size();
    while (!mChildren[prev]->isSelectable());

    select(prev);
}



















































