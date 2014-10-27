#ifndef QUADTREE_H
#define QUADTREE_H

#include <deque>
#include <array>

#include <entities/scenenode.h>

class QuadTree
{
public:
    QuadTree(int level, const sf::FloatRect& bounds);

    void                    insert(SceneNode *object);

    void                    clear();
    const sf::FloatRect&    getBounds() const;

    void                    getCloseObjects(SceneNode* from, std::deque<SceneNode*>& returnedObjects);

#ifdef DEBUG
    void    draw(sf::RenderTarget& target);
#endif

private:
    bool                    isFinal() const;
    bool                    hasChildren() const;

    void                    split();
    int                     getChildIndex(const sf::FloatRect& rect);

private:
    sf::FloatRect           mBounds;
    int                     mLevel;
    int                     mMaxLevel;
    std::deque<SceneNode*>  mObjects;

    std::array<QuadTree*,4> mChildren;
};

#endif // QUADTREE_H
