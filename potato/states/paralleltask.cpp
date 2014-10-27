#include <states/paralleltask.h>

ParallelTask::ParallelTask() :
    mThread(&ParallelTask::runTask, this),
    mFinished(false)
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
    while(!ended)
    {
        sf::Lock lock(mMutex);
        if(mElapsedTime.getElapsedTime().asSeconds() >= 3.f)
        {
            ended = true;
        }
    }

    {
        sf::Lock lock(mMutex);
        mFinished = true;
    }
}
