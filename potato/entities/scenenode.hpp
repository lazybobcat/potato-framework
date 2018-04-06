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

#ifndef SCENENODE_H
#define SCENENODE_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <cassert>
#include <memory>
#include <vector>

#include <events/commandqueue.hpp>

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
    typedef std::unique_ptr<SceneNode> Ptr;

public:
    explicit SceneNode(Category::Type category = Category::None);

    void attachChild(Ptr child);
    Ptr detachChild(const SceneNode& node);

    void update(sf::Time dt, CommandQueue& commands);

    virtual bool isCollidable() const;

    sf::Transform         getWorldTransform() const;
    sf::Vector2f          getWorldPosition() const;
    virtual sf::FloatRect getBoundingRect() const;

    virtual unsigned int getCategory() const;
    void onCommand(const Command& command, sf::Time dt);

private:
    virtual void updateCurrent(sf::Time dt, CommandQueue& commands);
    virtual void updateChildren(sf::Time dt, CommandQueue& commands);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    std::vector<Ptr> mChildren;
    SceneNode*       mParent;

    Category::Type mDefaultCategory;
};

#endif // SCENENODE_H
