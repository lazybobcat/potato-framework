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

#ifndef QUADTREE_H
#define QUADTREE_H

#include <array>
#include <deque>

#include <entities/scenenode.hpp>

class QuadTree
{
public:
    QuadTree(int level, const sf::FloatRect& bounds);

    void insert(SceneNode* object);

    void                 clear();
    const sf::FloatRect& getBounds() const;

    void getCloseObjects(SceneNode* from, std::deque<SceneNode*>& returnedObjects);

#ifdef DEBUG
    void draw(sf::RenderTarget& target);
#endif

private:
    bool isFinal() const;
    bool hasChildren() const;

    void split();
    int getChildIndex(const sf::FloatRect& rect);

private:
    sf::FloatRect          mBounds;
    int                    mLevel;
    int                    mMaxLevel;
    std::deque<SceneNode*> mObjects;

    std::array<QuadTree*, 4> mChildren;
};

#endif // QUADTREE_H
