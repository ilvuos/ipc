#pragma once
#include "FunBase.h"
//�߳���,�����߳�,�����߳�
class CThreadFun :
	public CFunBase
{
public:
	CThreadFun();
	~CThreadFun();
protected:
	static   DWORD WINAPI ThreadFunction(LPVOID lpPara);

protected:
	HANDLE   mhThread;
	DWORD    mdwThreadId;
	virtual void     RunThread();
public:
	int      Start();
	int      Stop();
};

