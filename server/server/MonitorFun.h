#pragma once
#include "ThreadFun.h"
#include "XBroadCastServer.h"
// ��� client ����
class CMonitorFun :
	public CThreadFun 
{
public:
	CMonitorFun();
	~CMonitorFun();
protected:
	virtual void     RunThread();
protected:
	CXBroadCastServer mBroadCast;
};

