
#include "WzThread.h"

#include <windows.h>
#include <process.h>

struct PWzThread
{
	HANDLE pThread;
};

unsigned int  static __stdcall callBackForStart(void *p)
{
	WzThread *t = (WzThread *)p;
	t->run();
	return 0;
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
	unsigned int treadId;
	pWzThread->pThread = (HANDLE)_beginthreadex(NULL,0,callBackForStart,this,0,&treadId);
	if(pWzThread->pThread)
	{
		return true;
	}
	else
	{
		delete pWzThread;
		pWzThread = NULL;
		return false;
	}	
}

void WzThread::sleepMs(int ms)
{
	Sleep(ms);
}

void WzThread::sleepS(int s)
{
	Sleep(s*1000);
}

void WzThread::join()
{
	if (pWzThread)
	{
		WaitForSingleObject(pWzThread->pThread,INFINITE);
		CloseHandle(pWzThread->pThread);
		delete pWzThread;
		pWzThread = NULL;
	}
}
