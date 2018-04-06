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

#include <states/paralleltask.hpp>

ParallelTask::ParallelTask()
  : mThread(&ParallelTask::runTask, this)
  , mFinished(false)
{
}

void ParallelTask::execute()
{
    mFinished = false;
    mElapsedTime.restart();
    mThread.launch();
}

bool ParallelTask::isFinished()
{
    sf::Lock lock(mMutex);
    return mFinished;
}

float ParallelTask::getCompletion()
{
    sf::Lock lock(mMutex);

    // 100% at 3 seconds of elapsed time
    return mElapsedTime.getElapsedTime().asSeconds() / 3.f;
}

void ParallelTask::runTask()
{
    // DUMMY TASK HERE !!!
    bool ended = false;
    while (!ended) {
        sf::Lock lock(mMutex);
        if (mElapsedTime.getElapsedTime().asSeconds() >= 3.f) {
            ended = true;
        }
    }

    {
        sf::Lock lock(mMutex);
        mFinished = true;
    }
}
