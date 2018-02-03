#include "WzSemaphore.h"

#include <unistd.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

struct PWzSemaphore
{
    sem_t pSemaphore;
};

WzSemaphore::WzSemaphore(int defaultValue)
{
    pWzSemaphore = new PWzSemaphore;
    if(sem_init(&(pWzSemaphore->pSemaphore), 1,
                defaultValue) < 0)
    {
        delete pWzSemaphore;
        pWzSemaphore = NULL;
    }
}

WzSemaphore::~WzSemaphore()
{
    if(pWzSemaphore)
    {
        sem_destroy(&(pWzSemaphore->pSemaphore));
        delete pWzSemaphore;
        pWzSemaphore = NULL;
    }
}

void WzSemaphore::wait()
{
    if(!pWzSemaphore)return;
    sem_wait(&(pWzSemaphore->pSemaphore));
}

bool WzSemaphore::wait(int ms)
{
    timeval tv_now;
    gettimeofday(&tv_now, NULL);

    timespec ts;
    ts.tv_sec = tv_now.tv_sec;
    ts.tv_nsec = tv_now.tv_usec * 1000;

    int ns = ts.tv_nsec + (ms % 1000)  * 1000000;
    ts.tv_nsec = ns % 1000000000;
    ts.tv_sec += ns / 1000000000;
    ts.tv_sec += ms / 1000;

    if(sem_timedwait(&(pWzSemaphore->pSemaphore), &ts) != 0)
    {
        return true;
    }

    return false;
}

void WzSemaphore::release()
{
    if(!pWzSemaphore)return;
    sem_post(&(pWzSemaphore->pSemaphore));
}
