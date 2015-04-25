#ifndef PARALLELTASK_H
#define PARALLELTASK_H

#include <SFML/System.hpp>

class ParallelTask
{
public:
    ParallelTask();
    void        execute();
    bool        isFinished();
    float       getCompletion();

private:
    void        runTask();

private:
    sf::Thread  mThread;
    bool        mFinished;
    sf::Clock   mElapsedTime;
    sf::Mutex   mMutex;
};

#endif // PARALLELTASK_H
