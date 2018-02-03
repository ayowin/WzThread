
#include "WzSemaphore.h"

#include <windows.h>

struct PWzSemaphore
{
	HANDLE pSemaphore;
};

WzSemaphore::WzSemaphore(int defaultValue)
{
	pWzSemaphore = new PWzSemaphore;
	pWzSemaphore->pSemaphore = CreateSemaphore(NULL, defaultValue, 5000, NULL);
	if(pWzSemaphore->pSemaphore == NULL)
	{
		delete pWzSemaphore;
		pWzSemaphore = NULL;
	}
}

WzSemaphore::~WzSemaphore()
{
	if(!pWzSemaphore)return;
	CloseHandle(pWzSemaphore->pSemaphore);
	pWzSemaphore = NULL;	
}

void WzSemaphore::wait()
{
	if(!pWzSemaphore)return;
	WaitForSingleObject(pWzSemaphore->pSemaphore,INFINITE);	
}

bool WzSemaphore::wait(int ms)
{
	if(!pWzSemaphore)return false;
	DWORD result = WaitForSingleObject(pWzSemaphore->pSemaphore,ms);
	if (result == WAIT_OBJECT_0)return true;
	else return false;
}

void WzSemaphore::release()
{
	if(!pWzSemaphore)return;
	ReleaseSemaphore(pWzSemaphore->pSemaphore,1,NULL);
}