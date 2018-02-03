
#include "WzThread.h"
#include <unistd.h>
#include <pthread.h>
#include <time.h>

struct PWzThread
{
    pthread_t pThread;
};

static void* callBackForStart(void *_p)
{
    WzThread *p = (WzThread*)_p;
    p->run();
    return NULL;
}

WzThread::WzThread():pWzThread(NULL)
{

}

WzThread::~WzThread()
{
    if(pWzThread)
    {
        delete pWzThread;
        pWzThread = NULL;
    }
}

bool WzThread::start()
{
    pWzThread = new PWzThread;
    if(pthread_create(&(pWzThread->pThread),NULL,
                      callBackForStart,this)<0)
    {
        delete pWzThread;
        pWzThread = NULL;
        return false;
    }
    return true;
}

void WzThread::join()
{
    if(pWzThread)
    {
        pthread_join(pWzThread->pThread,NULL);
        delete pWzThread;
        pWzThread = NULL;
    }
}

void WzThread::sleepMs(int ms)
{
    usleep(ms*1000);
}

void WzThread::sleepS(int s)
{
    sleep(s);
}
