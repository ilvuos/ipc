#include "stdafx.h"
#include "ThreadFun.h"

DWORD WINAPI CThreadFun::ThreadFunction(PVOID pParam)
{
	if (NULL != pParam)
	{
		((CThreadFun*)pParam)->RunThread();
	}
	return 0;
}

CThreadFun::CThreadFun()
{
	 mhThread = 0 ;
	 mdwThreadId = 0;
}

CThreadFun::~CThreadFun()
{
}

void CThreadFun::RunThread()
{
}

int  CThreadFun::Start()
{
	//已经存在
	if (mbExist)
		return -1;
	mbExist = 1;
	mhThread = 0;
	mdwThreadId = 0;
	//创建线程
	mhThread = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)ThreadFunction, this, 0, &mdwThreadId);
	if (!mhThread)
		return -2;
	return 0;
}
int  CThreadFun::Stop()
{
	//没有创建
	if (!mbExist)
		return 0;
	//销毁线程
	CloseHandle(mhThread);
	mbExist = 0;
}