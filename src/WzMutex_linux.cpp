#include "WzMutex.h"

#include <pthread.h>

struct PWzMutex
{
    pthread_mutex_t pMutex;
};

WzMutex::WzMutex()
{
    pWzMutex = new PWzMutex;
    if(pthread_mutex_init(&(pWzMutex->pMutex),NULL)<0)
    {
        delete pWzMutex;
        pWzMutex = NULL;
    }
}

WzMutex::~WzMutex()
{
    if(pWzMutex)
    {
        pthread_mutex_destroy(&(pWzMutex->pMutex));
        delete pWzMutex;
        pWzMutex = NULL;
    }
}

void WzMutex::lock()
{
    if(!pWzMutex)return;
    pthread_mutex_lock(&(pWzMutex->pMutex));
}

void WzMutex::unlock()
{
    if(!pWzMutex)return;
    pthread_mutex_unlock(&(pWzMutex->pMutex));
}
