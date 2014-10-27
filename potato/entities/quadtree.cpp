#include <entities/quadtree.h>
#include <cassert>

QuadTree::QuadTree(int level, const sf::FloatRect &bounds) :
    mBounds(bounds),
    mLevel(level),
    mMaxLevel(4),
    mChildren{ {nullptr, nullptr, nullptr, nullptr} }
{
    if(!isFinal())
        split();
}



void QuadTree::insert(SceneNode* object)
{
    if(!object->isCollidable())
        return;

    // If that QuadTree node has children, we give them the object
    if(hasChildren())
    {
        int index = getChildIndex(object->getBoundingRect());

        if(index >= 0)
        {
            mChildren[index]->insert(object);
            return;
        }
    }

    // If there's no children or children cannot carry the objet
    mObjects.push_back(object);
}


void QuadTree::getCloseObjects(SceneNode *from, std::deque<SceneNode *> &returnedObjects)
{
    // If there's no children or children cannot carry the objet
    if(!mObjects.empty())
        returnedObjects.insert(returnedObjects.end(), mObjects.begin(), mObjects.end());

    // If that QuadTree node has children, search in them too
    if(hasChildren())
    {
        int index = getChildIndex(from->getBoundingRect());

        if(index >= 0)
        {
            mChildren[index]->getCloseObjects(from, returnedObjects);
        }
    }
}



void QuadTree::clear()
{
    mObjects.clear();
    for(QuadTree* child : mChildren)
    {
        if(child)
        {
            child->clear();
        }
    }
}


void QuadTree::split()
{
    assert(!isFinal());

    if(hasChildren())
        return;

    float subWidth    = mBounds.width / 2.f;
    float subHeight   = mBounds.height / 2.f;
    float x           = mBounds.left;
    float y           = mBounds.top;

    mChildren[0] = new QuadTree(mLevel+1, sf::FloatRect(x,          y,           subWidth, subHeight));
    mChildren[1] = new QuadTree(mLevel+1, sf::FloatRect(x+subWidth, y,           subWidth, subHeight));
    mChildren[2] = new QuadTree(mLevel+1, sf::FloatRect(x,          y+subHeight, subWidth, subHeight));
    mChildren[3] = new QuadTree(mLevel+1, sf::FloatRect(x+subWidth, y+subHeight, subWidth, subHeight));
}

int QuadTree::getChildIndex(const sf::FloatRect &rect)
{
    int index = -1;

    if(!hasChildren())
        return index;

    for(int i = 0; i < 4; ++i)
    {
        QuadTree* child = mChildren[i];
        const sf::FloatRect& bounds = child->getBounds();
        if(bounds.contains(sf::Vector2f(rect.left, rect.top)) && bounds.contains(sf::Vector2f(rect.left+rect.width, rect.top+rect.height)))
            return i;
    }

    return index;
}




const sf::FloatRect &QuadTree::getBounds() const
{
    return mBounds;
}

bool QuadTree::isFinal() const
{
    return mLevel >= mMaxLevel;
}

bool QuadTree::hasChildren() const
{
    return mChildren[0] != nullptr;
}


#ifdef DEBUG
void QuadTree::draw(sf::RenderTarget& target)
{
    sf::RectangleShape shape(sf::Vector2f(mBounds.width, mBounds.height));
    shape.setPosition(mBounds.left, mBounds.top);
    if(mObjects.empty())
        shape.setFillColor(sf::Color(0,0,0, 0));
    else
        shape.setFillColor(sf::Color(255, 125, 125, 100));
    shape.setOutlineThickness(1);
    shape.setOutlineColor(sf::Color(255,255,255));
    target.draw(shape);

    if(hasChildren())
    {
        for(QuadTree* child : mChildren)
            child->draw(target);
    }
}

#endif
