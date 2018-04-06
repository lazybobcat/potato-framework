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

#ifndef PARALLELTASK_H
#define PARALLELTASK_H

#include <SFML/System.hpp>

class ParallelTask
{
public:
    ParallelTask();
    void  execute();
    bool  isFinished();
    float getCompletion();

private:
    void runTask();

private:
    sf::Thread mThread;
    bool       mFinished;
    sf::Clock  mElapsedTime;
    sf::Mutex  mMutex;
};

#endif // PARALLELTASK_H
