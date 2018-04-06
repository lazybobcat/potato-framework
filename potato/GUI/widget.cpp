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

#include <GUI/widget.hpp>

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
