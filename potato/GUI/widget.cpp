#include <GUI/widget.h>

using namespace GUI;

Widget::Widget()
: mIsSelected(false)
, mIsActive(false)
{
}

Widget::~Widget()
{
}

bool Widget::isSelected() const
{
    return mIsSelected;
}

void Widget::select()
{
    mIsSelected = true;
}

void Widget::deselect()
{
    mIsSelected = false;
}

bool Widget::isActive() const
{
    return mIsActive;
}

void Widget::activate()
{
    mIsActive = true;
}

void Widget::deactivate()
{
    mIsActive = false;
}

