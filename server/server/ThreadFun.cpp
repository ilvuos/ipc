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
	//�Ѿ�����
	if (mbExist)
		return -1;
	mbExist = 1;
	mhThread = 0;
	mdwThreadId = 0;
	//�����߳�
	mhThread = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)ThreadFunction, this, 0, &mdwThreadId);
	if (!mhThread)
		return -2;
	return 0;
}
int  CThreadFun::Stop()
{
	//û�д���
	if (!mbExist)
		return 0;
	//�����߳�
	CloseHandle(mhThread);
	mbExist = 0;
}