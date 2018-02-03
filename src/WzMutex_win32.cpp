
#include "WzMutex.h"

#include <windows.h>

struct PWzMutex
{
	HANDLE pMutex;
};

WzMutex::WzMutex()
{
	pWzMutex = new PWzMutex;
	pWzMutex->pMutex = CreateMutex(NULL,true,NULL);
	if (pWzMutex->pMutex==NULL)
	{
		delete pWzMutex;
		pWzMutex = NULL;
		return;
	}
	ReleaseMutex(pWzMutex->pMutex);
}

WzMutex::~WzMutex()
{
	if(pWzMutex)
	{
		CloseHandle(pWzMutex->pMutex);
		delete pWzMutex;
		pWzMutex = NULL;
	}
}

void WzMutex::lock()
{
	if(!pWzMutex)return;
	WaitForSingleObject(pWzMutex->pMutex,INFINITE);
}

void WzMutex::unlock()
{
	if (!pWzMutex)return;
	ReleaseMutex(pWzMutex->pMutex);
}